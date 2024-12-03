// LAB18.cpp : Определяет точку входа для приложения.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "framework.h"
#include "LAB18.h"

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
    LoadStringW(hInstance, IDC_LAB18, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB18));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB18));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB18);
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
int numImage = 0;
int counter = 0;
void triangle(HDC hdc, int cx, int cy, int size) 
{
    static HPEN hPen = NULL;
    if (hPen == NULL) {
        hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
    }
    SelectObject(hdc, hPen);
    MoveToEx(hdc, cx, cy + size, NULL);
    LineTo(hdc, cx + size, cy - size);
    LineTo(hdc, cx - size, cy - size);
    LineTo(hdc, cx, cy + size);

    char strC[5];
    sprintf(strC, "%d", counter);
    TCHAR strWin[5];
    OemToChar(strC, strWin);
    TextOut(hdc, cx, cy, (LPCWSTR)strWin, _tcslen(strWin));
}
void recursiveImage1_1(HDC hdc, int cx, int cy, int size)
{
    counter++;
    triangle(hdc, cx, cy, size);
    if (size > 10) {
        recursiveImage1_1(hdc, cx - size, cy - size, size / 2);
        recursiveImage1_1(hdc, cx + size, cy - size, size / 2);
    }


}
void recursiveImage1_2(HDC hdc, int cx, int cy, int size)
{
    counter++;
    triangle(hdc, cx, cy, size);
    if (size > 10) {
        recursiveImage1_2(hdc, cx - size, cy - size, size / 2);
        recursiveImage1_2(hdc, cx, cy + size, size / 2);
    }


}
void recursiveImage1_3(HDC hdc, int cx, int cy, int size)
{
    counter++;
    triangle(hdc, cx, cy, size);
    if (size > 10) {
        recursiveImage1_3(hdc, cx - size, cy - size, size / 2);
        recursiveImage1_3(hdc, cx + size, cy - size, size / 2);
        recursiveImage1_3(hdc, cx, cy + size, size / 2);
    }
}

void sandglass(HDC hdc, int cx, int cy, int size)
{
    static HPEN hPen = NULL;
    if (hPen == NULL) {
        hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
    }
    SelectObject(hdc, hPen);
    MoveToEx(hdc, cx - size / 2, cy - size, NULL);
    LineTo(hdc, cx + size / 2, cy - size);
    LineTo(hdc, cx - size, cy + size);
    LineTo(hdc, cx + size, cy + size);
    LineTo(hdc, cx - size / 2, cy - size);
    char strC[5];
    sprintf(strC, "%d", counter);
    TCHAR strWin[5];
    OemToChar(strC, strWin);
    TextOut(hdc, cx, cy, (LPCWSTR)strWin, _tcslen(strWin));
}
void recursiveImage2_1(HDC hdc, int cx, int cy, int size)
{
    counter++;
    sandglass(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
        recursiveImage2_1(hdc, cx - size, cy + size, size / 2);
}
void recursiveImage2_2(HDC hdc, int cx, int cy, int size)
{
    counter++;
    sandglass(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    recursiveImage2_2(hdc, cx - size / 2, cy - size, size / 2);
}
void recursiveImage2_3(HDC hdc, int cx, int cy, int size)
{
    counter++;
    sandglass(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    recursiveImage2_3(hdc, cx - size / 2, cy - size, size / 2);
    recursiveImage2_3(hdc, cx + size / 2, cy - size, size / 2);
}
void recursiveImage2_4(HDC hdc, int cx, int cy, int size)
{
    counter++;
    sandglass(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    recursiveImage2_4(hdc, cx - size / 2, cy - size, size / 2);
    recursiveImage2_4(hdc, cx + size / 2, cy - size, size / 2);
    recursiveImage2_4(hdc, cx - size, cy + size, size / 2);
    recursiveImage2_4(hdc, cx + size, cy + size, size / 2);
}

void rhomb(HDC hdc, int cx, int cy, int size)
{
    static HPEN hPen = NULL;
    if (hPen == NULL) {
        hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
    }
    SelectObject(hdc, hPen);
    MoveToEx(hdc, cx, cy - size, NULL);
    LineTo(hdc, cx - size, cy);
    LineTo(hdc, cx, cy + size);
    LineTo(hdc, cx + size, cy);
    LineTo(hdc, cx, cy - size);

    char strC[5];
    sprintf(strC, "%d", counter);
    TCHAR strWin[5];
    OemToChar(strC, strWin);
    TextOut(hdc, cx, cy, (LPCWSTR)strWin, _tcslen(strWin));
}
void recursiveImage3_1(HDC hdc, int cx, int cy, int size)
{
    counter++;
    rhomb(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    recursiveImage3_1(hdc, cx + size, cy, size / 2);
}
void recursiveImage3_2(HDC hdc, int cx, int cy, int size)
{
    counter++;
    rhomb(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    recursiveImage3_2(hdc, cx + size, cy, size / 2);
    recursiveImage3_2(hdc, cx - size, cy, size / 2);
}
void recursiveImage3_3(HDC hdc, int cx, int cy, int size)
{
    counter++;
    rhomb(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    recursiveImage3_3(hdc, cx + size, cy, size / 2);
    recursiveImage3_3(hdc, cx - size, cy, size / 2);
    recursiveImage3_3(hdc, cx, cy + size, size / 2);
}
void recursiveImage3_4(HDC hdc, int cx, int cy, int size)
{
    counter++;
    rhomb(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    recursiveImage3_4(hdc, cx + size, cy, size / 2);
    recursiveImage3_4(hdc, cx - size, cy, size / 2);
    recursiveImage3_4(hdc, cx, cy - size, size / 2);
}
void recursiveImage3_5(HDC hdc, int cx, int cy, int size)
{
    counter++;
    rhomb(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    recursiveImage3_5(hdc, cx + size, cy, size / 2);
    recursiveImage3_5(hdc, cx - size, cy, size / 2);
    recursiveImage3_5(hdc, cx, cy - size, size / 2);
    recursiveImage3_5(hdc, cx, cy + size, size / 2);
}

void star(HDC hdc, int cx, int cy, int size)
{
    static HPEN hPen = NULL;
    if (hPen == NULL) {
        hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
    }
    SelectObject(hdc, hPen);
    MoveToEx(hdc, cx - size / 4, cy - size / 4, NULL);
    LineTo(hdc, cx, cy - size);
    LineTo(hdc, cx + size / 4, cy - size / 4);
    LineTo(hdc, cx + size, cy);
    LineTo(hdc, cx + size / 4, cy + size / 4);
    LineTo(hdc, cx, cy + size);
    LineTo(hdc, cx - size / 4, cy + size / 4);
    LineTo(hdc, cx - size, cy);
    LineTo(hdc, cx - size / 4, cy - size / 4);

    char strC[5];
    sprintf(strC, "%d", counter);
    TCHAR strWin[5];
    OemToChar(strC, strWin);
    TextOut(hdc, cx, cy, (LPCWSTR)strWin, _tcslen(strWin));
}
void recursiveImage4_1(HDC hdc, int cx, int cy, int size)
{
    counter++;
    star(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    recursiveImage4_1(hdc, cx + size, cy, size / 2);
}
void recursiveImage4_2(HDC hdc, int cx, int cy, int size)
{
    counter++;
    star(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    recursiveImage4_2(hdc, cx + size, cy, size / 2);
    recursiveImage4_2(hdc, cx - size, cy, size / 2);
}
void recursiveImage4_3(HDC hdc, int cx, int cy, int size)
{
    counter++;
    star(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    recursiveImage4_3(hdc, cx, cy + size, size / 2);
    recursiveImage4_3(hdc, cx, cy - size, size / 2);
}
void recursiveImage4_4(HDC hdc, int cx, int cy, int size)
{
    counter++;
    star(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    recursiveImage4_4(hdc, cx, cy + size, size / 2);
    recursiveImage4_4(hdc, cx, cy - size, size / 2);
    recursiveImage4_4(hdc, cx - size, cy, size / 2);
}

void arrow(HDC hdc, int cx, int cy, int size)
{
    static HPEN hPen = NULL;
    if (hPen == NULL) {
        hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
    }
    SelectObject(hdc, hPen);
    MoveToEx(hdc, cx, cy + size, NULL);
    LineTo(hdc, cx + size / 2, cy - size / 2);
    LineTo(hdc, cx - size, cy);
    LineTo(hdc, cx, cy);
    LineTo(hdc, cx, cy + size);

    char strC[5];
    sprintf(strC, "%d", counter);
    TCHAR strWin[5];
    OemToChar(strC, strWin);
    TextOut(hdc, cx, cy, (LPCWSTR)strWin, _tcslen(strWin));
}
void recursiveImage5_1(HDC hdc, int cx, int cy, int size)
{
    counter++;
    arrow(hdc, cx, cy, size);
    if (size < 60) {
        return;
    }
    recursiveImage5_1(hdc, cx - size / 4, cy + size / 4, size / 2);
    recursiveImage5_1(hdc, cx + size / 2, cy - size / 2, size / 2);
}
void recursiveImage5_2(HDC hdc, int cx, int cy, int size)
{
    counter++;
    arrow(hdc, cx, cy, size);
    if (size < 15) {
        return;
    }
    recursiveImage5_2(hdc, cx - size / 4, cy + size / 4, size / 2);
    recursiveImage5_2(hdc, cx + size / 2, cy - size / 2, size / 2);
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
            counter = 0;
            if (numImage == 0)
                recursiveImage1_1(hdc, 200, 200, 80);
            if (numImage == 1)
                recursiveImage1_2(hdc, 200, 200, 80);
            if (numImage == 2)
                recursiveImage1_3(hdc, 200, 200, 80);
            if (numImage == 3)
                recursiveImage2_1(hdc, 200, 200, 100);
            if (numImage == 4)
                recursiveImage2_2(hdc, 200, 200, 100);
            if (numImage == 5)
                recursiveImage2_3(hdc, 200, 200, 100);
            if (numImage == 6)
                recursiveImage2_4(hdc, 200, 200, 100);
            if (numImage == 7)
                recursiveImage3_1(hdc, 200, 200, 100);
            if (numImage == 8)
                recursiveImage3_2(hdc, 200, 200, 100);
            if (numImage == 9)
                recursiveImage3_3(hdc, 200, 200, 100);
            if (numImage == 10)
                recursiveImage3_4(hdc, 200, 200, 100);
            if (numImage == 11)
                recursiveImage3_5(hdc, 200, 200, 100);
            if (numImage == 12)
                recursiveImage4_1(hdc, 200, 200, 100);
            if (numImage == 13)
                recursiveImage4_2(hdc, 200, 200, 100);
            if (numImage == 14)
                recursiveImage4_3(hdc, 200, 200, 100);
            if (numImage == 15)
                recursiveImage4_4(hdc, 200, 200, 100);
            if (numImage == 16)
                recursiveImage5_1(hdc, 200, 200, 100);
            if (numImage == 17)
                recursiveImage5_2(hdc, 200, 200, 100);


            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_KEYDOWN:
        numImage++;
        if (numImage >= 18) numImage = 0;
        InvalidateRect(hWnd, NULL, TRUE);;
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
