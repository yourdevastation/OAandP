// WindowsProject2.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "WindowsProject2.h"


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
    LoadStringW(hInstance, IDC_WINDOWSPROJECT2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT2));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT2);
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

            //roof
            MoveToEx(hdc, 100, 200, NULL);
            LineTo(hdc, 200, 150);
            LineTo(hdc, 300, 200);
            LineTo(hdc, 500, 200);
            LineTo(hdc, 400, 150);
            LineTo(hdc, 200, 150);

            //ftont wall
            MoveToEx(hdc, 100, 200, NULL);
            LineTo(hdc, 300, 200);
            LineTo(hdc, 300, 400);
            LineTo(hdc, 100, 400);
            LineTo(hdc, 100, 200);

            //front door
            MoveToEx(hdc, 165, 400, NULL);
            LineTo(hdc, 165, 250);
            LineTo(hdc, 235, 250);
            LineTo(hdc, 235, 400);

            //side wall
            MoveToEx(hdc, 300, 400, NULL);
            LineTo(hdc, 500, 400);
            LineTo(hdc, 500, 200);

            //window
            MoveToEx(hdc, 340, 250, NULL);
            LineTo(hdc, 340, 350);
            LineTo(hdc, 460, 350);
            LineTo(hdc, 460, 250);
            LineTo(hdc, 340, 250);

            MoveToEx(hdc, 400, 350, NULL);
            LineTo(hdc, 400, 250);

            MoveToEx(hdc, 400, 290, NULL);
            LineTo(hdc, 460, 290);

            //elochka
            HPEN hPen;
            hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
            SelectObject(hdc, hPen);

            MoveToEx(hdc, 600, 400, NULL);
            LineTo(hdc, 620, 370);
            LineTo(hdc, 550, 370);
            LineTo(hdc, 625, 310);
            LineTo(hdc, 570, 310);
            LineTo(hdc, 625, 270);
            LineTo(hdc, 600, 270);

            LineTo(hdc, 635, 240);

            LineTo(hdc, 670, 270);
            LineTo(hdc, 640, 270);
            LineTo(hdc, 700, 310);
            LineTo(hdc, 640, 310);
            LineTo(hdc, 720, 370);
            LineTo(hdc, 650, 370);
            LineTo(hdc, 670, 400);
            LineTo(hdc, 600, 400);

            /*DeleteObject(hPen);*/

                //cybertruck
                HPEN hPen2;
                HPEN hPen3;
                HPEN hPen4;
                HPEN hPen5;
                HPEN hPen6;
                HPEN hPen7;
                HBRUSH hBrush;
                HBRUSH hBrush2;

            hBrush = CreateSolidBrush(RGB(93, 100, 110));
            hBrush2 = CreateHatchBrush(HS_FDIAGONAL, RGB(166, 15, 183));
            hPen2 = CreatePen(PS_SOLID, 2, RGB(188, 197, 202));
            hPen3 = CreatePen(PS_SOLID, 1, RGB(3, 4, 8));
            hPen4 = CreatePen(PS_SOLID, 10, RGB(255, 20, 20));
            hPen5 = CreatePen(PS_SOLID, 10, RGB(153, 217, 234));
            hPen6 = CreatePen(PS_SOLID, 2, RGB(3, 4, 8));
            hPen7 = CreatePen(PS_SOLID, 5, RGB(113, 106, 85));

            SelectObject(hdc, hPen2);

            MoveToEx(hdc, 750, 350, NULL);
            LineTo(hdc, 740, 320);
            LineTo(hdc, 925, 270);
            LineTo(hdc, 1180, 290);
            LineTo(hdc, 775, 310);
            LineTo(hdc, 775, 320);
            LineTo(hdc, 740, 320);

            //front ligts
            SelectObject(hdc, hPen5);
            MoveToEx(hdc, 740, 317, NULL);
            LineTo(hdc, 760, 315);


            //window
            SelectObject(hdc, hPen3);
            MoveToEx(hdc, 820, 302, NULL);
            LineTo(hdc, 925, 275);
            LineTo(hdc, 1000, 280);
            LineTo(hdc, 1000, 295);
            LineTo(hdc, 820, 302);
               
            RECT rect = { 740, 320, 760, 350 };
            FillRect(hdc, &rect, hBrush);

            SelectObject(hdc, hPen2);
            MoveToEx(hdc, 760, 350, NULL);
            LineTo(hdc, 780, 325);
            LineTo(hdc, 850, 325);
            LineTo(hdc, 870, 350);
            LineTo(hdc, 1000, 350);
            LineTo(hdc, 1020, 325);
            LineTo(hdc, 1090, 325);
            LineTo(hdc, 1110, 340);
            LineTo(hdc, 1160, 335);
            LineTo(hdc, 1180, 290);

            //tail lights
            SelectObject(hdc, hPen4);
            MoveToEx(hdc, 1180, 290, NULL);
            LineTo(hdc, 1170, 295);

            //bottom
            SelectObject(hdc, hPen6);
            MoveToEx(hdc, 740, 350, NULL);
            LineTo(hdc, 745, 360);
            LineTo(hdc, 765, 375);
            LineTo(hdc, 790, 340);
            LineTo(hdc, 840, 340);
            LineTo(hdc, 865, 370);
            LineTo(hdc, 1010, 370);
            LineTo(hdc, 1025, 345);
            LineTo(hdc, 1080, 344);
            LineTo(hdc, 1110, 370);
            LineTo(hdc, 1150, 350);
            LineTo(hdc, 1160, 335);

            SelectObject(hdc, hPen7);
            SelectObject(hdc, hBrush2);
            Ellipse(hdc, 775, 335, 855, 415);
            Ellipse(hdc, 1015, 335, 1095, 415);

     /*       DeleteObject(hPen7);*/
   
            //brush1
            SelectObject(hdc, hPen);
            {
                int x1 = 150, y1 = 450;
                int x2 = 250, y2 = 550;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);
                x1 += 7;
            } while (x1 <= 350);
            }
            
            //brush2
            {
                int x1 = 420, y1 = 600;
                int x2 = 520, y2 = 600;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);
                x1 += 5;
                y1 -= 10;
            } while (x1 <= 520);

            x1 = 620, y1 = 600;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);
                x1 -= 5;
                y1 -= 10;
            } while (x1 >= 520);

            }

            //fence
            {
                HPEN hPenbrown;
                hPenbrown = CreatePen(PS_SOLID, 3, RGB(185, 122, 87));
                SelectObject(hdc, hPenbrown);

                int x1 = 100, y1 = 0;
                int x2 = 100, y2 = 100;
                do {
                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);
                    x1 += 10;
                    x2 += 10;

                } while (x1 <= 600);
            }

            {
                //car
                HPEN hPen = CreatePen(PS_SOLID, 2, RGB(128, 0, 0));
                SelectObject(hdc, hPen);

                HBRUSH hBrush;
                hBrush = CreateSolidBrush(RGB(255, 128, 67));
                SelectObject(hdc, hBrush);

                Rectangle(hdc, 800, 520, 1020, 560);

                MoveToEx(hdc, 840, 520, NULL);
                LineTo(hdc, 880, 480);
                LineTo(hdc, 980, 480);
                LineTo(hdc, 1020, 520);

                HPEN hPen2 = CreatePen(PS_SOLID, 7, RGB(0, 0, 128));
                SelectObject(hdc, hPen2);

                HBRUSH hBrush2 = CreateHatchBrush(HS_FDIAGONAL, RGB(255, 0, 0));
                SelectObject(hdc, hBrush2);

                Ellipse(hdc, 820, 535, 870, 575);
                Ellipse(hdc, 950, 535, 1000, 575);
            }
            {
                //myTree
                HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
                HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
                SelectObject(hdc, hPen);
                SelectObject(hdc, hBrush);

                int x1 = 650, y1 = 550;
                int x2 = 700, y2 = 570;

                do {
                    Ellipse(hdc, x1, y1, x2, y2);
                    x1 += 5;
                    y1 -= 10;
                    x2 += 2;
                    y2 -= 10;

                } while (x1 <= 700);

            }
            {
                HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
                HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
                SelectObject(hdc, hPen);
                SelectObject(hdc, hBrush);

                int x1 = 800, y1 = 570;
                int x2 = 750, y2 = 550;

                do {
                    Ellipse(hdc, x1, y1, x2, y2);
                    x1 -= 5;
                    y1 -= 10;
                    x2 -= 2;
                    y2 -= 10;

                } while (x1 >= 750);
                Ellipse(hdc, 710, 435, 740, 455);
            }
            {
                HPEN hPen = CreatePen(PS_SOLID, 2, RGB(128, 30, 0));
                HBRUSH hBrush2 = CreateSolidBrush(RGB(128, 64, 0));
                SelectObject(hdc, hBrush2);
                SelectObject(hdc, hPen);
                Ellipse(hdc, 717, 450, 733, 600);
                
                MoveToEx(hdc, 725, 550, NULL);
                LineTo(hdc, 670, 540);
                MoveToEx(hdc, 725, 520, NULL);
                LineTo(hdc, 680, 510);
                MoveToEx(hdc, 725, 500, NULL);
                LineTo(hdc, 700, 490);

                MoveToEx(hdc, 725, 550, NULL);
                LineTo(hdc, 780, 540);
                MoveToEx(hdc, 725, 520, NULL);
                LineTo(hdc, 770, 510);
                MoveToEx(hdc, 725, 500, NULL);
                LineTo(hdc, 750, 490);
            }
            //antenna
            {
                HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 162, 232));
                SelectObject(hdc, hPen);
                MoveToEx(hdc, 320, 320, NULL);
                LineTo(hdc, 320, 200);
                MoveToEx(hdc, 330, 320, NULL);
                LineTo(hdc, 330, 200);

                int x1 = 325, y1 = 230;
                int x2 = 325, y2 = 220;
                int x3 = 325, y3 = 230;
                int x4 = 325, y4 = 220;
                do{
                   

                    MoveToEx(hdc, x1, y1, NULL);
                    LineTo(hdc, x2, y2);
                    MoveToEx(hdc, x3, y3, NULL);
                    LineTo(hdc, x4, y4);

                    x1 -= 5;
                    y1 += 5;
                    x2 -= 5;
                    y2 -= 5;

                    x3 += 5;
                    y3 += 5;
                    x4 += 5;
                    y4 -= 5;
                

                }while(x1 >= 280);
            }
    
            {   //clouds
                HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 162, 232));
                HBRUSH hBrush = CreateSolidBrush(RGB(0, 162, 232));
                SelectObject(hdc, hPen);
                SelectObject(hdc, hBrush);

                Ellipse(hdc, 1000, 50, 1050, 70);
                Ellipse(hdc, 1040, 40, 1090, 60);
                Ellipse(hdc, 1080, 50, 1130, 70);
                Ellipse(hdc, 1030, 60, 1100, 80);


                Ellipse(hdc, 1200, 50, 1250, 70);
                Ellipse(hdc, 1240, 40, 1290, 60);
                Ellipse(hdc, 1280, 50, 1330, 70);
                Ellipse(hdc, 1230, 60, 1300, 80);
            }


          EndPaint(hWnd, &ps);
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
