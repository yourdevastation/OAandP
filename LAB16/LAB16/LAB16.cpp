// LAB16.cpp : Определяет точку входа для приложения.
//
#define _CRT_SECURE_NO_WARNINGS

#include "framework.h"
#include "LAB16.h"
#include <stdio.h>
#include <Windows.h>


#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB16, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB16));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB16));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB16);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
#define N 10
#define M 15
// Коды ячеек:
// 0 - свободна
// 1 - игрок
// 2 - препятствие
// 3 - золото
int map[N][M] = {
    {0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0,   0, 0, 0, 0, 3,   0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0,   0, 0, 0, 0, 3,   0, 0, 0, 0, 0},
    {0, 0, 0, 3, 3,   3, 3, 0, 0, 0,   3, 3, 0, 0, 0},
    {0, 0, 0, 0, 0,   0, 3, 0, 0, 0,   3, 3, 0, 0, 0},

    {0, 0, 0, 0, 0,   0, 3, 3, 3, 0,   0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0,   0, 0, 0, 3, 0,   2, 0, 0, 2, 0},
    {0, 0, 0, 0, 0,   0, 0, 2, 0, 0,   2, 0, 0, 2, 0},
    {0, 0, 0, 0, 0,   0, 2, 2, 2, 2,   2, 2, 2, 2, 0},
    {0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0, 0, 0, 0}
};

#define WIDTH 30
#define HEIGHT 20

void drawMap(HDC hdc) {
    // кисть для пустого поля
    HBRUSH hBrushEmptyCell = CreateSolidBrush(RGB(200, 200, 200)); // серый
    // кисть для поля с золотом
    HBRUSH hBrushGold = CreateSolidBrush(RGB(255, 255, 0)); // желтый
    // кисть для стены
    HBRUSH hBrushWall = CreateSolidBrush(RGB(0, 0, 0)); // черный
    // кисть для игрока
    HBRUSH hBrushMan = CreateSolidBrush(RGB(0, 0, 255)); // синий

    // Коды ячеек:
    // 0 - свободна
    // 1 - игрок
    // 2 - препятствие
    // 3 - золото
    HBRUSH brush[4] = { hBrushEmptyCell, hBrushMan, hBrushWall, hBrushGold };
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {

            int x1 = j * WIDTH;
            int x2 = (j + 1) * WIDTH;
            int y1 = i * HEIGHT;
            int y2 = (i + 1) * HEIGHT;

            RECT r = { x1, y1, x2, y2 };
            FillRect(hdc, &r, brush[map[i][j]]);
        }
    }


    // Все кисти удаляем!!!
    for (i = 0; i < 4; i++)
        DeleteObject(brush[i]);

}

int steps = 0;
int gold = 0;

void Left() {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 1; j < M; j++) {
            if (map[i][j] == 1) { // если в map[i][j]  игрок
                if (map[i][j - 1] == 0) { // если слева от игрока - пустая клетка
                    map[i][j - 1] = 1;
                    map[i][j] = 0;
                    steps++;
                }
                else if (map[i][j - 1] == 3) {// если слева от игрока - золото
                    map[i][j - 1] = 1;
                    map[i][j] = 0;
                    steps++;
                    gold++;
                }
            }
        }
    }
}
void Right() {
    int i, j;

    for (i = 0; i < N; i++) {

        for (j = M - 2; j >= 0; j--) {

            if (map[i][j] == 1) { // если в map[i][j]  игрок
                if (map[i][j + 1] == 0) {
                    map[i][j + 1] = 1;
                    map[i][j] = 0;
                    steps++;
                }
                else if (map[i][j + 1] == 3) {
                    map[i][j + 1] = 1;
                    map[i][j] = 0;
                    steps++;
                    gold++;
                }
            }
        }
    }
}
void Up() {
    int i, j;

    for (i = 1; i < N; i++) {

        for (j = 0; j < M; j++) {

            if (map[i][j] == 1) { // если в map[i][j]  игрок
                if (map[i - 1][j] == 0) {
                    map[i - 1][j] = 1;
                    map[i][j] = 0;
                    steps++;
                }
                else if (map[i - 1][j] == 3) {
                    map[i - 1][j] = 1;
                    map[i][j] = 0;
                    steps++;
                    gold++;
                }
            }
        }
    }
}
void Down() {
    int i, j;

    for (i = N - 2; i >= 0; i--) {

        for (j = 0; j < M; j++) {

            if (map[i][j] == 1) {
                if (map[i + 1][j] == 0) {
                    map[i + 1][j] = 1;
                    map[i][j] = 0;
                    steps++;
                }
                else if (map[i + 1][j] == 3) {
                    map[i + 1][j] = 1;
                    map[i][j] = 0;
                    steps++;
                    gold++;
                }
            }
        }
    }
}

void Save() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE* fout;
    fout = fopen("c:\\test_saves\\game.txt", "wt");
    if (fout == NULL) {
        printf("Выходной файл не создался");
        return;
    }
    fprintf(fout, "%d ", N);
    fprintf(fout, "%d\n", M);

    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            fprintf(fout, "%d ", map[i][j]);
        }
        fprintf(fout, "\n");
    }
    fprintf(fout, "%d ", steps);
    fprintf(fout, "%d", gold);

    fclose(fout);
}
void Load() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE* fin;
    fin = fopen("c:\\test_saves\\game.txt", "rt");
    if (fin == NULL) {
        printf("Входной файл не создался");
        return;
    }
    int n, m;
    fscanf(fin, "%d", &n);
    fscanf(fin, "%d", &m);

    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            fscanf(fin, "%d", &map[i][j]);
        }
    }
    fscanf(fin, "%d", &steps);
    fscanf(fin, "%d", &gold);

    fclose(fin);
}

void InsertWall() {
    int i, j;

    for (i = 0; i < N; i++) {

        for (j = 1; j < M; j++) {

            if (map[i][j] == 1) {
                if (map[i][j - 1] == 0) {
                    map[i][j - 1] = 2;
                }
                if (map[i][j - 1] == 3) {
                    map[i][j - 1] = 2;
                }
            }
        }
    }
}
void InsertGold() {
    int i, j;

    for (i = 0; i < N; i++) {

        for (j = M - 2; j >= 0; j--) {

            if (map[i][j] == 1) {
                if (map[i][j + 1] == 0) {
                    map[i][j + 1] = 3;
                }
                if (map[i][j + 1] == 2) {
                    map[i][j + 1] = 3;
                }
            }
        }
    }
}

void DestroyWall() {
    int i, j;

    for (i = 1; i < N; i++) {

        for (j = 0; j < M; j++) {

            if (map[i][j] == 1) {
                if (map[i - 1][j] == 2) {
                    map[i - 1][j] = 0;
                }
            }
        }
    }
}
void DestroyWallsRight() {
    int i, j;

    for (i = 0; i < N; i++) {

        for (j = M - 2; j >= 0; j--) {

            if (map[i][j] == 1) {
                for (int w = j; w < M - 1; w++) {
                    if (map[i][w + 1] == 2) {
                        map[i][w + 1] = 0;
                    }
                }
            }
        }
    }
}
void DestroyWallsNear() {
    int i1, j1;

    for (i1 = 1; i1 < N; i1++) {

        for (j1 = 0; j1 < M; j1++) {

            if (map[i1][j1] == 1) {
                if (map[i1 - 1][j1] == 2) {
                    map[i1 - 1][j1] = 0;
                }
            }
        }
    }
    int i2, j2;
    for (i2 = N - 2; i2 >= 0; i2--) {

        for (j2 = 0; j2 < M; j2++) {

            if (map[i2][j2] == 1) {
                if (map[i2 + 1][j2] == 2) {
                    map[i2 + 1][j2] = 0;
                }
            }
        }
    }
    int i3, j3;
    for (i3 = 0; i3 < N; i3++) {

        for (j3 = 1; j3 < M; j3++) {

            if (map[i3][j3] == 1) {
                if (map[i3][j3 - 1] == 2) {
                    map[i3][j3 - 1] = 0;
                }
            }
        }
    }
    int i4, j4;
    for (i4 = 0; i4 < N; i4++) {

        for (j4 = M - 2; j4 >= 0; j4--) {

            if (map[i4][j4] == 1) {
               
                if (map[i4][j4 + 1] == 2) {
                        map[i4][j4 + 1] = 0;
                }
            }
        }
    }
}
void DestroyWallsTwoCells() {
    int i1, j1;
    int w1;
    //up destroy
    for (i1 = 1; i1 < N; i1++) {

        for (j1 = 0; j1 < M; j1++) {

            if (map[i1][j1] == 1) {
                for(w1 = i1; w1 > i1 - 2; w1--)
                if (map[w1 - 1][j1] == 2) {
                    map[w1 - 1][j1] = 0;
                }
            }
        }
    }
    int i2, j2;
    int w2;
    //down destroy
    for (i2 = N - 2; i2 >= 0; i2--) {

        for (j2 = 0; j2 < M; j2++) {

            if (map[i2][j2] == 1) {
                for (w2 = i2; w2 < i2 + 2; w2++)
                    if (map[w2 + 1][j2] == 2) {
                        map[w2 + 1][j2] = 0;
                    }
            }
        }
    }
    int i3, j3;
    int w3;
     //left destroy
    for (i3 = 0; i3 < N; i3++) {

        for (j3 = 1; j3 < M; j3++) {

            if (map[i3][j3] == 1) {
                for (int w3 = j3; w3 > j3 - 2; w3--) {
                    if (map[i3][w3 - 1] == 2) {
                        map[i3][w3 - 1] = 0;
                    }
                }
            }
        }
    }
    int i4, j4;
    int w4;
     //right destroy
    for (i4 = 0; i4 < N; i4++) {

        for (j4 = M - 2; j4 >= 0; j4--) {

            if (map[i4][j4] == 1) {
                for (int w4 = j4; w4 < j4 + 2; w4++) {
                    if (map[i4][w4 + 1] == 2) {
                        map[i4][w4 + 1] = 0;
                    }
                }
            }
        }
    }
}

void doMidasHand(int i, int j)
{
    if (map[i][j] == 2)
    {
        map[i][j] = 3;
        if (i > 0) doMidasHand(i - 1, j);
        if (i < N - 1) doMidasHand(i + 1, j);
        if (j > 0) doMidasHand(i, j - 1);
        if (j < M - 1) doMidasHand(i, j + 1);
    }
}
void midasHandToRight()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 1)
                doMidasHand(i, j + 1);

        }
    }
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...

            drawMap(hdc);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_DOWN:
            Down();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_LEFT:
            Left();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP:
            Up();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RIGHT:
            Right();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x53: //s
            Save();
            break;
        case 0x4c: //l
            Load();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x41: //A
            InsertWall();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x52: //R
            InsertGold();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x55: //U
            DestroyWall();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x44: //D
            DestroyWallsNear();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x5A: //Z
            DestroyWallsRight();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x4F: //0
            DestroyWallsTwoCells();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x4d: //M - MidasHand
            midasHandToRight();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
