// LABA12.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "LABA12.h"

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
    LoadStringW(hInstance, IDC_LABA12, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LABA12));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LABA12));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LABA12);
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
#define NUM_IM_A 9

struct Image {
    int x;
    int y;
    int vx;
    int vy;
    COLORREF color;
};
struct Image im1 = { 100, 200, 10, 0, RGB(128, 128, 0) };
typedef struct Image IMAGE;
IMAGE im2 = { 400, 200, -10, 0, RGB(0, 100, 0) };
IMAGE im3 = { 200, 40, 0, 10, RGB(6, 200, 200) };
IMAGE im4 = { 200, 400, 0, -10, RGB(200, 6, 200) };
IMAGE im5[3] = {
    {500, 100, 10, 5, RGB(100, 0, 100)},
    {500, 100, 0, 10, RGB(0, 150, 150)},
    {500, 100, -10, 5, RGB(200, 200, 0)}
};
IMAGE imA[NUM_IM_A] = {
    {700, 300, 10, 0, RGB(255, 0, 255)},
    {700, 300, 9, 4, RGB(255, 0, 255)},
    {700, 300, 7, 7, RGB(255, 0, 255)},
    {700, 300, 4, 9, RGB(255, 0, 255)},
    {700, 300, 0, 10, RGB(255, 0, 255)},
    {700, 300, -4, 9, RGB(255, 0, 255)},
    {700, 300, -7, 7, RGB(255, 0, 255)},
    {700, 300, -9, 4, RGB(255, 0, 255)},
    {700, 300, -10, 0, RGB(255, 0, 255)},

};


void Image0(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[4] = {
        cx,        	cy + 20,
        cx + 20,	cy - 20,
        cx - 20,   	cy - 20,
        cx,        	cy + 20
    };
    Polyline(hdc, p, 4);
    DeleteObject(hPen);
}
void Image1(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[4]{
        cx,         cy - 20,
        cx + 20,    cy + 20,
        cx - 20,    cy + 20,
        cx,         cy - 20
    };
    Polyline(hdc, p, 4);
    DeleteObject(hPen);
}
void Image2(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[5]{
        cx,         cy + 20,
        cx + 20,    cy,
        cx,         cy - 20,
        cx - 20,    cy,
        cx,         cy + 20

    };
    Polyline(hdc, p, 5);
    DeleteObject(hPen);
}
void Image3(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[5]{
        cx,         cy + 20,
        cx + 20,    cy - 20,
        cx,         cy,
        cx - 20,    cy - 20,
        cx,         cy + 20,
    };
    Polyline(hdc, p, 5);
    DeleteObject(hPen);
}
void Image4(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[6]{
        cx - 20,    cy + 20,
        cx - 20,    cy - 20,
        cx + 20,    cy - 20,
        cx,         cy - 10,
        cx + 20,    cy,
        cx - 20,    cy
    };
    Polyline(hdc, p, 6);
    DeleteObject(hPen);
}
void Image5(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[6]{
        cx,         cy,
        cx + 20,    cy - 20,
        cx + 20,    cy + 20,
        cx - 20,    cy + 20,
        cx - 20,    cy - 20,
        cx,         cy

    };
    Polyline(hdc, p, 6);
    DeleteObject(hPen);
}
void Image6(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[9]{
        cx,         cy + 20,
        cx + 10,    cy - 10,
        cx + 10,    cy + 20,
        cx + 20,    cy + 20,
        cx + 20,    cy - 20,
        cx - 20,    cy - 20,
        cx - 20,    cy + 20,
        cx - 10,    cy + 20,
        cx - 10,    cy - 10,
        /*    cx,         cy + 20*/
    };
    Polygon(hdc, p, 9);
    DeleteObject(hPen);
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
            Image0(hdc, im1.x, im1.y, im1.color);
            Image1(hdc, im2.x, im2.y, im2.color);
            Image2(hdc, im3.x, im3.y, im3.color);
            Image3(hdc, im4.x, im4.y, im4.color);
            Image4(hdc, im5[0].x, im5[0].y, im5[0].color);
            Image4(hdc, im5[1].x, im5[1].y, im5[1].color);
            Image4(hdc, im5[2].x, im5[2].y, im5[2].color);

            int i = 0;
            while (i < NUM_IM_A) {
                Image5(hdc, imA[i].x, imA[i].y, imA[i].color);
                i++;
            }

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_CREATE:
        SetTimer(hWnd, 1, 20, 0);
        break;
    case WM_TIMER:
    {
        RECT rect;
        GetClientRect(hWnd, &rect);

        im1.x += im1.vx;
        im1.y += im1.vy;

        im2.x += im2.vx;
        im2.y += im2.vy;

        im3.x += im3.vx;
        im3.y += im3.vy;

        im4.x += im4.vx;
        im4.y += im4.vy;

        

        int i = 0;
        while (i < 3) {
            if (im5[i].x + 20 > rect.right) {
                im5[i].vx = -im5[i].vx;
                /*im5[i].x = rect.right;*/
            }
            if (im5[i].x - 20 < rect.left) {
                im5[i].vx = -im5[i].vx;
               /* im5[i].x = rect.left;*/
            }
            if (im5[i].y + 20 > rect.bottom) {
                im5[i].vy = -im5[i].vy;
                /*im5[i].y = rect.bottom;*/
            }
            if (im5[i].y - 20 < rect.top) {
                im5[i].vy = -im5[i].vy;
                /*im5[i].y = rect.top;*/
            }
            im5[i].x += im5[i].vx;
            im5[i].y += im5[i].vy;
            i++;
        }

        i = 0;
        while (i < NUM_IM_A) {
            if (imA[i].x + 20 > rect.right) {
                imA[i].vx = -imA[i].vx;
            }
            if (imA[i].x - 20 < rect.left) {
                imA[i].vx = -imA[i].vx;
            }
            if (imA[i].y + 20 > rect.bottom) {
                imA[i].vy = -imA[i].vy;
            }
            if (imA[i].y - 20 < rect.top) {
                imA[i].vy = -imA[i].vy;
            }

            imA[i].x += imA[i].vx;
            imA[i].y += imA[i].vy;
            i++;
        }
        InvalidateRect(hWnd, NULL, TRUE);
    }
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
