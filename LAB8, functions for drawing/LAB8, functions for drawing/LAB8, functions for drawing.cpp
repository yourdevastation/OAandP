// LAB8, functions for drawing.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "LAB8, functions for drawing.h"

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
    LoadStringW(hInstance, IDC_LAB8FUNCTIONSFORDRAWING, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB8FUNCTIONSFORDRAWING));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB8FUNCTIONSFORDRAWING));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB8FUNCTIONSFORDRAWING);
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
int numImage;

void StClausAuto(HDC hdc, int x, int y) {
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
    SelectObject(hdc, hPen);

    //top triangle
    MoveToEx(hdc, 20 + x, 0 + y, NULL);
    LineTo(hdc, 30 + x, 20 + y);
    LineTo(hdc, 10 + x, 20 + y);
    LineTo(hdc, 20 + x, 0 + y);

    //middle triangle
    MoveToEx(hdc, 20 + x, 10 + y, NULL);
    LineTo(hdc, 30 + x, 40 + y);
    LineTo(hdc, 10 + x, 40 + y);
    LineTo(hdc, 20 + x, 10 + y);

    //bottom triangle
    MoveToEx(hdc, 20 + x, 30 + y, NULL);
    LineTo(hdc, 40 + x, 80 + y);
    LineTo(hdc, 00 + x, 80 + y);
    LineTo(hdc, 20 + x, 30 + y);
}

void StClausAuto_1stScreen(HDC hdc) {
    StClausAuto(hdc, 0, 0);
    StClausAuto(hdc, 200, 200);
    StClausAuto(hdc, 100, 100);
    StClausAuto(hdc, 200, 0);
    StClausAuto(hdc, 0, 200);
}

void StClausAuto_2ndScreen(HDC hdc) {
    int x = 0;
    do {
        StClausAuto(hdc, x, 0);
        x += 50;
    } while (x < 400);
}

void StClausAuto_3rdScreen(HDC hdc) {
    int y = 0;
    do {
        StClausAuto(hdc, 0, y);
        y += 90;
    } while (y < 300);
}

void StClausAuto_4thScreen(HDC hdc) {
    int x = 0;
    int y = 0;
    do {
        StClausAuto(hdc, x, y);
        x += 50;
        y += 90;
    } while (y < 300);
}

void drawTruck(HDC hdc, int x, int y) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 200));
    SelectObject(hdc, hPen);

    Rectangle(hdc, 0 + x, 30 + y, 40 + x, 50 + y);
    Rectangle(hdc, 10 + x, 10 + y, 40 + x, 30 + y);
    Rectangle(hdc, 40 + x, 0 + y, 100 + x, 50 + y);

    hPen = CreatePen(PS_SOLID, 3, RGB(100, 0, 0));
    SelectObject(hdc, hPen);
    Ellipse(hdc, 10 + x, 40 + y, 30 + x, 60 + y);
    Ellipse(hdc, 70 + x, 40 + y, 90 + x, 60 + y);
}

void drawTruck_1stScreen(HDC hdc) {
    drawTruck(hdc, 10, 10);
    drawTruck(hdc, 10, 310);
    drawTruck(hdc, 310, 10);
    drawTruck(hdc, 310, 310);
    drawTruck(hdc, 160, 160);
}

void drawTruck_2ndScreen(HDC hdc) {
    int x = 0;
    do {
        drawTruck(hdc, x, 10);
        x += 110;
    } while (x < 660);
}

void drawTruck_3rdScreen(HDC hdc) {
    int y = 10;
    do {
        drawTruck(hdc, 10, y);
        y += 70;
    } while (y < 430);
}

void drawTruck_4thScreen(HDC hdc) {
    int x = 10;
    int y = 10;
    do {
        drawTruck(hdc, x, y);
        x += 110;
        y += 70;
    } while (y < 430);
}

void drawSnowWomen(HDC hdc, int x, int y) {
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    Ellipse(hdc, 20 + x, 0 + y, 40 + x, 20 + y);
    Ellipse(hdc, 10 + x, 20 + y, 50 + x, 60 + y);
    Ellipse(hdc, 0 + x, 60 + y, 60 + x, 120 + y);

    MoveToEx(hdc, 0 + x, 40 + y, NULL);
    LineTo(hdc, 15 + x, 30 + y);

    MoveToEx(hdc, 60 + x, 40 + y, NULL);
    LineTo(hdc, 45 + x, 30 + y);

    hPen = CreatePen(PS_SOLID, 1, RGB(99, 56, 17));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 40 + x, 120 + y, NULL);
    LineTo(hdc, 70 + x, 0 + y);
    MoveToEx(hdc, 65 + x, 20 + y, NULL);
    LineTo(hdc, 65 + x, 0 + y);
    MoveToEx(hdc, 65 + x, 20 + y, NULL);
    LineTo(hdc, 75 + x, 0 + y);
}

void drawSnowWomen_1stScreen(HDC hdc) {
    drawSnowWomen(hdc, 10, 10);
    drawSnowWomen(hdc, 310, 10);
    drawSnowWomen(hdc, 10, 310);
    drawSnowWomen(hdc, 310, 310);
    drawSnowWomen(hdc, 160, 160);
}

void drawSnowWomen_2ndScreen(HDC hdc) {
    int x = 10;
    do {
        drawSnowWomen(hdc, x, 10);
        x += 90;
    } while (x < 540);
}

void drawSnowWomen_3rdScreen(HDC hdc) {
    int y = 10;
    do {
        drawSnowWomen(hdc, 10, y);
        y += 140;
    } while (y < 560);
}

void drawSnowWomen_4thScreen(HDC hdc) {
    int x = 10;
    int y = 10;
    do {
        drawSnowWomen(hdc, x, y);
        x += 90;
        y += 140;
    } while (y < 560);
}

void drawCadillac(HDC hdc, int x1, int y1) {
    HPEN hPen1 = CreatePen(PS_SOLID, 2, RGB(197, 197, 197));
    SelectObject(hdc, hPen1);

    Arc(hdc, 10 + x1, 75 + y1, 190 + x1, 225 + y1, 60 + x1, 0 + y1, 140 + x1, 0 + y1);
    Arc(hdc, 30 + x1, 85 + y1, 170 + x1, 210 + y1, 60 + x1, 0 + y1, 140 + x1, 0 + y1);

    MoveToEx(hdc, 80 + x1, 75 + y1, NULL);
    LineTo(hdc, 83 + x1, 90 + y1);

    MoveToEx(hdc, 120 + x1, 75 + y1, NULL);
    LineTo(hdc, 117 + x1, 90 + y1);

    HPEN hPen2 = CreatePen(PS_SOLID, 2, RGB(84, 84, 84));
    SelectObject(hdc, hPen2);
    HBRUSH hBrush1 = CreateSolidBrush(RGB(203, 201, 202));
    SelectObject(hdc, hBrush1);
    POINT pt[9];
    pt[0].x = 50 + x1;
    pt[0].y = 120 + y1;
    pt[1].x = 100 + x1;
    pt[1].y = 110 + y1;
    pt[2].x = 150 + x1;
    pt[2].y = 120 + y1;
    pt[3].x = 140 + x1;
    pt[3].y = 140 + y1;
    pt[4].x = 135 + x1;
    pt[4].y = 180 + y1;
    pt[5].x = 100 + x1;
    pt[5].y = 190 + y1;
    pt[6].x = 65 + x1;
    pt[6].y = 180 + y1;
    pt[7].x = 60 + x1;
    pt[7].y = 140 + y1;
    pt[8].x = 50 + x1;
    pt[8].y = 120 + y1;

    Polygon(hdc, pt, 9);

    HPEN hPen3 = CreatePen(PS_SOLID, 1, RGB(36, 36, 36));
    SelectObject(hdc, hPen3);
    HBRUSH hBrush2 = CreateSolidBrush(RGB(190, 190, 190));
    SelectObject(hdc, hBrush2);
    POINT pt2[9];
    pt2[0].x = 65 + x1;
    pt2[0].y = 125 + y1;
    pt2[1].x = 135 + x1;
    pt2[1].y = 125 + y1;
    pt2[2].x = 130 + x1;
    pt2[2].y = 135 + y1;
    pt2[3].x = 127 + x1;
    pt2[3].y = 170 + y1;
    pt2[4].x = 100 + x1;
    pt2[4].y = 180 + y1;
    pt2[5].x = 73 + x1;
    pt2[5].y = 170 + y1;
    pt2[6].x = 70 + x1;
    pt2[6].y = 135 + y1;
    pt2[7].x = 65 + x1;
    pt2[7].y = 125 + y1;

    Polygon(hdc, pt2, 8);

    HPEN hPen4 = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    SelectObject(hdc, hPen4);
    HBRUSH hBrush3 = CreateSolidBrush(RGB(207, 184, 134));
    SelectObject(hdc, hBrush3);

    Rectangle(hdc, 72 + x1, 126 + y1, 100 + x1, 150 + y1);
    Rectangle(hdc, 100 + x1, 150 + y1, 127 + x1, 171 + y1);

    HPEN hPen5 = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    SelectObject(hdc, hPen5);
    HBRUSH hBrush4 = CreateSolidBrush(RGB(5, 5, 5));
    SelectObject(hdc, hBrush4);

    Rectangle(hdc, 72 + x1, 134 + y1, 100 + x1, 142 + y1);
    Rectangle(hdc, 100 + x1, 157 + y1, 127 + x1, 164 + y1);

    HPEN hPen6 = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    SelectObject(hdc, hPen6);
    HBRUSH hBrush5 = CreateSolidBrush(RGB(255, 5, 5));
    SelectObject(hdc, hBrush5);

    Rectangle(hdc, 100 + x1, 126 + y1, 116 + x1, 140 + y1);
    Rectangle(hdc, 115 + x1, 138 + y1, 129 + x1, 150 + y1);

    Rectangle(hdc, 73 + x1, 150 + y1, 89 + x1, 162 + y1);
    Rectangle(hdc, 87 + x1, 161 + y1, 100 + x1, 171 + y1);

    HPEN hPen7 = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    SelectObject(hdc, hPen7);
    HBRUSH hBrush6 = CreateSolidBrush(RGB(222, 226, 229));
    SelectObject(hdc, hBrush6);

    Rectangle(hdc, 89 + x1, 150 + y1, 100 + x1, 162 + y1);
    Rectangle(hdc, 100 + x1, 140 + y1, 115 + x1, 150 + y1);
    Rectangle(hdc, 115 + x1, 126 + y1, 130 + x1, 138 + y1);
    Rectangle(hdc, 74 + x1, 162 + y1, 87 + x1, 171 + y1);

    HPEN hPen8 = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    SelectObject(hdc, hPen8);
    HBRUSH hBrush7 = CreateSolidBrush(RGB(43, 87, 132));
    SelectObject(hdc, hBrush7);

    Rectangle(hdc, 89 + x1, 154 + y1, 100 + x1, 159 + y1);
    Rectangle(hdc, 100 + x1, 142 + y1, 115 + x1, 147 + y1);
    Rectangle(hdc, 115 + x1, 130 + y1, 130 + x1, 135 + y1);
    Rectangle(hdc, 74 + x1, 164 + y1, 87 + x1, 169 + y1);
}

void drawCadillac_1stScreen(HDC hdc) {
    drawCadillac(hdc, 0, 0);
    drawCadillac(hdc, 300, 0);
    drawCadillac(hdc, 0, 300);
    drawCadillac(hdc, 300, 0);
    drawCadillac(hdc, 150, 150);
    drawCadillac(hdc, 300, 300);
}

void drawCadillac_2ndScreen(HDC hdc) {
    int x1 = 10;
    do {
        drawCadillac(hdc, x1, 10);
        x1 += 200;
    } while (x1 <= 1200);
}

void drawCadillac_3rdScreen(HDC hdc) {
    int y1 = -50;
    do {
        drawCadillac(hdc, 10, y1);
        y1 += 150;
    } while (y1 <= 400);
}

void drawCadillac_4thScreen(HDC hdc) {
    int x1 = 10;
    int y1 = -50;
    do {
        drawCadillac(hdc, x1, y1);
        x1 += 100;
        y1 += 150;
    } while (y1 <= 400);
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
            
            if (numImage == 0)
                StClausAuto_1stScreen(hdc);
            if (numImage == 1)
                StClausAuto_2ndScreen(hdc);
            if (numImage == 2)
                StClausAuto_3rdScreen(hdc);
            if (numImage == 3)
                StClausAuto_4thScreen(hdc);

            if (numImage == 4)
                drawTruck_1stScreen(hdc);
            if (numImage == 5)
                drawTruck_2ndScreen(hdc);
            if (numImage == 6)
                drawTruck_3rdScreen(hdc);
            if (numImage == 7)
                drawTruck_4thScreen(hdc);

            if (numImage == 8)
                drawSnowWomen_1stScreen(hdc);
            if (numImage == 9)
                drawSnowWomen_2ndScreen(hdc);
            if (numImage == 10)
                drawSnowWomen_3rdScreen(hdc);
            if (numImage == 11)
                drawSnowWomen_4thScreen(hdc);

            if (numImage == 12)
                drawCadillac_1stScreen(hdc);
            if(numImage == 13)
                drawCadillac_2ndScreen(hdc);
            if(numImage == 14)
                drawCadillac_3rdScreen(hdc);
            if(numImage == 15)
                drawCadillac_4thScreen(hdc);

            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_KEYDOWN:
        numImage++;
        if (numImage >= 16) numImage = 0;
        InvalidateRect(hWnd, NULL, TRUE);
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
