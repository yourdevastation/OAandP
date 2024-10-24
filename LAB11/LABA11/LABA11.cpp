// LABA11.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "LABA11.h"

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
    LoadStringW(hInstance, IDC_LABA11, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LABA11));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LABA11));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LABA11);
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
enum Modes {
    image0,
    image1,
    image1_line,
    image1_with_colors,
    image2,
    image2_line,
    image2_with_colors,
    image3,
    image3_line,
    image3_lines,
    image3_with_colors,
    image4,
    image4_line,
    image4_lines,
    image4_with_colors,
    image5,
    image5_line,
    image5_lines,
    image5_with_colors,
    image6,
    image6_line,
    image6_lines,
    image6_with_colors,
    mode_none
};
enum Modes mode = image0;

void PictureFLineY(HDC hdc, void (*pfImage)(HDC hdc, int cx, int cy, COLORREF color)) {
    short x = 40;
    short y = 40;
    char i = 0;
    while (i < 6) {
        pfImage(hdc, x, y, RGB(255, 0, 0));
        y += 50;
        i++;
    }
}
void PictureFLineX(HDC hdc, void (*pfImage)(HDC hdc, int cx, int cy, COLORREF color)) {
    short x = 40;
    short y = 40;
    char j = 0;
    while (j < 10) {
        pfImage(hdc, x, y, RGB(255, 0, 0));
        x += 50;
        j++;
    }
}
void PictureFLines(HDC hdc, void (*pfImage)(HDC hdc, int cx, int cy, COLORREF color)) {
    short y = 40;
    char i = 0;
    while (i < 6) {
        short x = 40;
        char j = 0;
        while (j < 10) {
            pfImage(hdc, x, y, RGB(60, 209, 206));
            x += 50;
            j++;
        }
        y += 50;
        i++;
    }

}
void PictureFColorLines(HDC hdc, void (*pfImage)(HDC hdc, int cx, int cy, COLORREF color)) {
    unsigned char r = 255;
    unsigned char g = 0;

    short y = 40;
    char i = 0;
    while (i < 6) {
        short x = 40;
        char j = 0;

        unsigned char b = 0;
        while (j < 10) {
            pfImage(hdc, x, y, RGB(r, g, b));
            x += 50;
            j++;

            b += 25;
        }
        y += 50;
        i++;

        r += 25;
        g += 50;
    }
}

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
void drawImage0(HDC hdc) {
    Image0(hdc, 40, 40, RGB(255, 0, 0));
    Image0(hdc, 140, 40, RGB(0, 255, 0));
    Image0(hdc, 240, 40, RGB(0, 0, 255));
    Image0(hdc, 240, 240, RGB(255, 255, 0));
    Image0(hdc, 40, 240, RGB(255, 0, 255));
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
void drawImage1(HDC hdc) {
    Image1(hdc, 40, 40, RGB(250, 50, 150));
    Image1(hdc, 100, 40, RGB(125, 125, 5));
    Image1(hdc, 160, 40, RGB(0, 150, 150));
    Image1(hdc, 40, 100, RGB(175, 5, 175));
    Image1(hdc, 100, 100, RGB(200, 200, 0));
    Image1(hdc, 160, 100, RGB(5, 225, 225));
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
void drawImage2(HDC hdc) {
    Image2(hdc, 40, 40, RGB(150, 0, 100));
    Image2(hdc, 100, 40, RGB(170, 10, 40));
    Image2(hdc, 160, 40, RGB(65, 190, 20));
    Image2(hdc, 40, 200, RGB(210, 135, 90));
    Image2(hdc, 100, 200, RGB(60, 20, 240));
    Image2(hdc, 160, 200, RGB(100, 250, 130));
    Image2(hdc, 100, 120, RGB(30, 180, 180));
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
void drawImage3(HDC hdc) {
    Image3(hdc, 40, 40, RGB(90, 0, 190));
    Image3(hdc, 100, 40, RGB(0, 50, 150));
    Image3(hdc, 160, 40, RGB(20, 120, 0));
    Image3(hdc, 70, 100, RGB(200, 130, 60));
    Image3(hdc, 100, 160, RGB(100, 70, 40));
    Image3(hdc, 130, 100, RGB(180, 230, 90));
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
void drawImage4(HDC hdc) {
    Image4(hdc, 40, 40, RGB(0, 100, 50));
    Image4(hdc, 100, 100, RGB(110, 70, 50));
    Image4(hdc, 160, 160, RGB(220, 110, 50));
    Image4(hdc, 220, 100, RGB(50, 25, 250));
    Image4(hdc, 280, 40, RGB(80, 210, 50));
    Image4(hdc, 160, 40, RGB(20, 90, 150));
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
void drawImage5(HDC hdc) {
    Image5(hdc, 40, 40, RGB(0, 100, 50));
    Image5(hdc, 100, 100, RGB(110, 70, 50));
    Image5(hdc, 160, 160, RGB(220, 110, 50));
    Image5(hdc, 220, 100, RGB(50, 25, 250));
    Image5(hdc, 280, 40, RGB(80, 210, 50));
    Image5(hdc, 160, 40, RGB(20, 90, 150));
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
void drawImage6(HDC hdc) {
    Image6(hdc, 40, 40, RGB(0, 100, 50));
    Image6(hdc, 100, 100, RGB(110, 70, 50));
    Image6(hdc, 160, 160, RGB(220, 110, 50));
    Image6(hdc, 220, 100, RGB(50, 25, 250));
    Image6(hdc, 280, 40, RGB(80, 210, 50));
    Image6(hdc, 160, 40, RGB(20, 90, 150));
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
            switch (mode) {
                case image0:
                    drawImage0(hdc);
                    break;
                case image1:
                    drawImage1(hdc);
                    break;
                case image1_line:
                    PictureFLineY(hdc, Image1);
                    break;
                case image1_with_colors:
                    PictureFColorLines(hdc, Image1);
                    break;
                case image2:
                    drawImage2(hdc);
                    break;
                case image2_line:
                    PictureFLineY(hdc, Image2);
                    break;
                case image2_with_colors:
                    PictureFColorLines(hdc, Image2);
                    break;
                case image3:
                    drawImage3(hdc);
                    break;
                case image3_line:
                    PictureFLineX(hdc, Image3);
                    break;
                case image3_lines:
                    PictureFLines(hdc, Image3);
                    break;
                case image3_with_colors:
                    PictureFColorLines(hdc, Image3);
                    break;
                case image4:
                    drawImage4(hdc);
                    break;
                case image4_line:
                    PictureFLineX(hdc, Image4);
                    break;
                case image4_lines:
                    PictureFLines(hdc, Image4);
                    break;
                case image4_with_colors:
                    PictureFColorLines(hdc, Image4);
                    break;
                case image5:
                    drawImage5(hdc);
                    break;
                case image5_line:
                    PictureFLineX(hdc, Image5);
                    break;
                case image5_lines:
                    PictureFLines(hdc, Image5);
                    break;
                case image5_with_colors:
                    PictureFColorLines(hdc, Image5);
                    break;
                case image6:
                    drawImage6(hdc);
                    break;
                case image6_line:
                    PictureFLineX(hdc, Image6);
                    break;
                case image6_lines:
                    PictureFLines(hdc, Image6);
                    break;
                case image6_with_colors:
                    PictureFColorLines(hdc, Image6);
                    break;


            }

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_KEYDOWN:
        mode = (enum Modes)(mode + 1);
        if (mode == mode_none) mode = image0;
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
