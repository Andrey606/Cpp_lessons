#include "CATSelectWindow.h"

#define no_init_all
#include <Windows.h>
#include <Commctrl.h>
#include <iostream>
#include <atlstr.h>

#include <wchar.h>

#define WM_SET_ICON_PATH WM_USER+10
#define WM_TEXT_HEADER WM_USER+11
#define WM_TEXT_TOP_MSG WM_USER+12
#define WM_TEXT_BOTTOM_MSG WM_USER+13

#define WM_SUBSCRIBE WM_USER+14

#define IDC_EXIT_BUTTON 101
#define IDC_CANCEL_BUTTON 102
#define IDC_PUSHLIKE_BUTTON 103

void createText(HWND hwnd, CString text, CString tFont, double tLineHeight, double tWeight, int tR, int tG, int tB, RECT r, int align=DT_CENTER)
{
	HDC dc = GetDC(hwnd);
	HFONT font;
	HGDIOBJ old;

	font = CreateFont(tLineHeight, 0, 0, 0, tWeight, ANSI_CHARSET, 0U, 0U, 0U, 0U, 0U, 0U, 0U, tFont);
	old = SelectObject(dc, font);

	HBRUSH hBrush;
	hBrush = CreateSolidBrush(RGB(241, 0, 0));
	SelectObject(dc, hBrush);

	SetBkMode(dc, TRANSPARENT);
	SetTextColor(dc, RGB(tR, tG, tB));

	DrawText(dc, text, lstrlen(text), &r, DT_SINGLELINE | align | DT_VCENTER);

	SelectObject(dc, old);
	ReleaseDC(hwnd, dc);
	DeleteObject(font);
}

void createRoundRect(HWND hwnd, int x0, int y0, int width, int height, int round, COLORREF color)
{
	HDC hdc = GetDC(hwnd);
	HBRUSH hBrush;
	HPEN hPen;
	hBrush = CreateSolidBrush(color);
	SelectObject(hdc, hBrush);
	hPen = CreatePen(2, 2, color);
	SelectObject(hdc, hPen);
	RoundRect(hdc, x0, y0, x0 + width, y0 + height, round, round);
}

void createLine(HWND hwnd, int x1, int y1, int x2, int y2, int tR, int tG, int tB)
{
	HDC hdc = GetDC(hwnd);

	HPEN LinePen = CreatePen(PS_SOLID, 1, RGB(tR, tG, tB));
	SelectObject(hdc, LinePen);
	MoveToEx(hdc, x1, y1, (LPPOINT)NULL);
	LineTo(hdc, x2, y2);

	ReleaseDC(hwnd, hdc);
}

void createList(HWND hwnd)
{
	const int d0y = 177;
	int dy = 0;

	TCHAR wrksp[7][20] =
	{
		TEXT("Workspace 1"), TEXT("Workspace 2"), TEXT("Workspace 3"), TEXT("Workspace 4"), TEXT("Workspace 5"), TEXT("Workspace 6"), TEXT("Workspace 7")
	};

	COLORREF colorArr[4] = { RGB(42, 87, 248), RGB(57, 211, 221), RGB(157, 209, 90), RGB(229, 134, 45)};

	for (size_t i = 0; i < 7; i++)
	{
		createLine(hwnd, 16, d0y + dy, 581, d0y + dy, 198, 204, 217);
		createRoundRect(hwnd, 24, 188 + dy, 16, 16, 0, colorArr[i % 4]);
		createText(hwnd, wrksp[i], "Roboto", 16.41, 400, 27, 40, 57, { 48, 187 + dy, 277 + 48, 19 + 187 + dy }, DT_LEFT);
		createText(hwnd, "Adam Keating", "Roboto", 16.41, 400, 27, 40, 57, { 478, 188 + dy, 88 + 478, 16 + 188 + dy }, DT_RIGHT);
		createLine(hwnd, 16, d0y + 39 + dy, 581, d0y + 39 + dy, 198, 204, 217);

		dy += 39;
	}
}

void createScrollBar(HWND hwnd)
{
	CreateWindowEx(0L, TEXT("SCROLLBAR"), NULL, WS_CHILD | WS_VISIBLE | SBS_VERT, 0, 0, 15, 300, hwnd, NULL, NULL, NULL);
	HWND scrollArea = CreateWindowEx(0L, TEXT("SCROLLBAR"),	NULL, WS_CHILD | WS_VISIBLE | SBS_VERT, 0, 0, 15, 300, hwnd,	NULL, NULL, NULL);

	createText(scrollArea, "scrollArea", "Roboto", 16.41, 400, 27, 40, 57, { 0, 0, 50 + 0, 50 + 0 });
}

void createComboBox(HWND hwnd)
{
	int xpos = 52;            // Horizontal position of the window.
	int ypos = 69;            // Vertical position of the window.
	int nwidth = 536;          // Width of the window
	int nheight = 36;         // Height of the window
	HWND hwndParent = hwnd; // Handle to the parent window

	HWND hWndComboBox = CreateWindow(WC_COMBOBOX, TEXT(""),
		CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
		xpos, ypos, nwidth, nheight, hwndParent, NULL, NULL,
		NULL);

	TCHAR Planets[3][20] =
	{
		TEXT("File1, A.1.prt"), TEXT("File1, A.2.prt"), TEXT("File1, A.3.prt")
	};

	TCHAR A[16];
	int  k = 0;

	memset(&A, 0, sizeof(A));
	for (k = 0; k <= 2; k += 1)
	{
		wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)Planets[k]);

		// Add string to combobox.
		SendMessage(hWndComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A);
	}

	// Send the CB_SETCURSEL message to display an initial item 
	//  in the selection field  
	SendMessage(hWndComboBox, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
}

int CATSelectWindow::Build()
{
	ptrFunk = nullptr;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpfnWndProc = [](HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)->LRESULT
	{
		static func ptrFunk2 = nullptr;

		static HWND hwndParent = GetForegroundWindow();

		static struct Image
		{
			HBITMAP hBitmap;
			LONG width, height;
		} image;
		static HDC hdcMemSurface;

		// rect
		static RECT r, sr;

		// lines 
		static HPEN LinePen;

		// buttons
		static HBRUSH defaultbrush = NULL;
		static HBRUSH hotbrush = NULL;
		static HBRUSH selectbrush = NULL;

		static HBRUSH defaultbrush_cancel = NULL;
		static HBRUSH hotbrush_cancel = NULL;
		static HBRUSH selectbrush_cancel = NULL;

		static HBRUSH defaultbrush_exit = NULL;
		static HBRUSH hotbrush_exit = NULL;
		static HBRUSH selectbrush_exit = NULL;

		static int sx, sy;

		switch (uMsg)
		{
		case WM_MOUSEHOVER:
		{
			//MessageBox(hwnd, "Enter", "Info", MB_OK);
			return 0;
		}
		break;

		case WM_SUBSCRIBE:
		{
			ptrFunk2 = (func)lParam;
		}
		break;

		case WM_SIZE:
		{
			sx = LOWORD(lParam); //ширина
			sy = HIWORD(lParam); //высота
		}
		break;

		case WM_NOTIFY:
		{
			LPNMHDR some_item = (LPNMHDR)lParam;
			LPNMCUSTOMDRAW item = (LPNMCUSTOMDRAW)some_item;

			//---------------------------------
			HFONT font = CreateFont(14.06, 0, 0, 0, 400, ANSI_CHARSET, 0U, 0U, 0U, 0U, 0U, 0U, 0U, TEXT("Roboto"));
			HGDIOBJ old = SelectObject(item->hdc, font);

			if (some_item->idFrom == IDC_PUSHLIKE_BUTTON && some_item->code == NM_CUSTOMDRAW)
			{
				if (item->uItemState & CDIS_SELECTED)
				{
					//Select our color when the button is selected
					if (selectbrush == NULL)
						selectbrush = CreateSolidBrush(RGB(33, 150, 243));

					//Create pen for button border
					HPEN pen = CreatePen(PS_NULL, 0, RGB(0, 0, 0));

					//Select our brush into hDC
					HGDIOBJ old_pen = SelectObject(item->hdc, pen);
					HGDIOBJ old_brush = SelectObject(item->hdc, selectbrush);

					//If you want rounded button, then use this, otherwise use FillRect().
					RoundRect(item->hdc, item->rc.left, item->rc.top, item->rc.right, item->rc.bottom, 0, 0);

					//Clean up
					SelectObject(item->hdc, old_pen);
					SelectObject(item->hdc, old_brush);
					DeleteObject(pen);

					//Now, I don't want to do anything else myself (draw text) so I use this value for return:
					return CDRF_DODEFAULT;
				}
				else
				{
					if (item->uItemState & CDIS_HOT) //Our mouse is over the button
					{
						//Select our color when the mouse hovers our button
						if (hotbrush == NULL)
							hotbrush = CreateSolidBrush(RGB(57, 166, 244));

						HPEN pen = CreatePen(PS_NULL, 0, RGB(0, 0, 0));

						HGDIOBJ old_pen = SelectObject(item->hdc, pen);
						HGDIOBJ old_brush = SelectObject(item->hdc, hotbrush);

						RoundRect(item->hdc, item->rc.left, item->rc.top, item->rc.right, item->rc.bottom, 0, 0);

						SelectObject(item->hdc, old_pen);
						SelectObject(item->hdc, old_brush);
						DeleteObject(pen);

						return CDRF_DODEFAULT;
					}

					//Select our color when our button is doing nothing
					if (defaultbrush == NULL)
						defaultbrush = CreateSolidBrush(RGB(33, 150, 243));

					HPEN pen = CreatePen(PS_NULL, 0, RGB(0, 0, 0));

					HGDIOBJ old_pen = SelectObject(item->hdc, pen);
					HGDIOBJ old_brush = SelectObject(item->hdc, defaultbrush);

					RoundRect(item->hdc, item->rc.left, item->rc.top, item->rc.right, item->rc.bottom, 0, 0);

					//---------------------------------
					COLORREF crText = SetTextColor(item->hdc, RGB(0, 0, 255));

					SelectObject(item->hdc, old_pen);
					SelectObject(item->hdc, old_brush);
					DeleteObject(pen);

					return CDRF_DODEFAULT;
				}
			}
			else if (some_item->idFrom == IDC_CANCEL_BUTTON && some_item->code == NM_CUSTOMDRAW)
			{
				if (item->uItemState & CDIS_SELECTED)
				{
					//Select our color when the button is selected
					if (selectbrush_cancel == NULL)
						selectbrush_cancel = CreateSolidBrush(RGB(255, 255, 255));

					//Create pen for button border
					HPEN pen = CreatePen(PS_INSIDEFRAME, 0, RGB(220, 220, 220));

					//Select our brush into hDC
					HGDIOBJ old_pen = SelectObject(item->hdc, pen);
					HGDIOBJ old_brush = SelectObject(item->hdc, selectbrush_cancel);

					//If you want rounded button, then use this, otherwise use FillRect().
					RoundRect(item->hdc, item->rc.left, item->rc.top, item->rc.right, item->rc.bottom, 0, 0);

					//Clean up
					SelectObject(item->hdc, old_pen);
					SelectObject(item->hdc, old_brush);
					DeleteObject(pen);

					//Now, I don't want to do anything else myself (draw text) so I use this value for return:
					return CDRF_DODEFAULT;
				}
				else
				{
					if (item->uItemState & CDIS_HOT) //Our mouse is over the button
					{
						//Select our color when the mouse hovers our button
						if (hotbrush_cancel == NULL)
							hotbrush_cancel = CreateSolidBrush(RGB(249, 249, 249));

						HPEN pen = CreatePen(PS_INSIDEFRAME, 0, RGB(220, 220, 220));

						HGDIOBJ old_pen = SelectObject(item->hdc, pen);
						HGDIOBJ old_brush = SelectObject(item->hdc, hotbrush_cancel);

						RoundRect(item->hdc, item->rc.left, item->rc.top, item->rc.right, item->rc.bottom, 0, 0);

						SelectObject(item->hdc, old_pen);
						SelectObject(item->hdc, old_brush);
						DeleteObject(pen);

						return CDRF_DODEFAULT;
					}

					//Select our color when our button is doing nothing
					if (defaultbrush_cancel == NULL)
						defaultbrush_cancel = CreateSolidBrush(RGB(255, 255, 255));

					HPEN pen = CreatePen(PS_INSIDEFRAME, 0, RGB(220, 220, 220));

					HGDIOBJ old_pen = SelectObject(item->hdc, pen);
					HGDIOBJ old_brush = SelectObject(item->hdc, defaultbrush_cancel);

					RoundRect(item->hdc, item->rc.left, item->rc.top, item->rc.right, item->rc.bottom, 0, 0);

					SelectObject(item->hdc, old_pen);
					SelectObject(item->hdc, old_brush);
					DeleteObject(pen);

					return CDRF_DODEFAULT;
				}
			}
			else if (some_item->idFrom == IDC_EXIT_BUTTON && some_item->code == NM_CUSTOMDRAW)
			{
				if (item->uItemState & CDIS_SELECTED)
				{
					//Select our color when the button is selected
					if (selectbrush_exit == NULL)
						selectbrush_exit = CreateSolidBrush(RGB(255, 255, 255));

					//Create pen for button border
					HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));

					//Select our brush into hDC
					HGDIOBJ old_pen = SelectObject(item->hdc, pen);
					HGDIOBJ old_brush = SelectObject(item->hdc, selectbrush_exit);

					//If you want rounded button, then use this, otherwise use FillRect().
					RoundRect(item->hdc, item->rc.left, item->rc.top, item->rc.right, item->rc.bottom, 0, 0);

					//Clean up
					SelectObject(item->hdc, old_pen);
					SelectObject(item->hdc, old_brush);
					DeleteObject(pen);

					//Now, I don't want to do anything else myself (draw text) so I use this value for return:
					return CDRF_DODEFAULT;
				}
				else
				{
					if (item->uItemState & CDIS_HOT) //Our mouse is over the button
					{
						//Select our color when the mouse hovers our button
						if (hotbrush_exit == NULL)
							hotbrush_exit = CreateSolidBrush(RGB(249, 249, 249));

						HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));

						HGDIOBJ old_pen = SelectObject(item->hdc, pen);
						HGDIOBJ old_brush = SelectObject(item->hdc, hotbrush_exit);

						RoundRect(item->hdc, item->rc.left, item->rc.top, item->rc.right, item->rc.bottom, 0, 0);

						SelectObject(item->hdc, old_pen);
						SelectObject(item->hdc, old_brush);
						DeleteObject(pen);

						return CDRF_DODEFAULT;
					}

					//Select our color when our button is doing nothing
					if (defaultbrush_exit == NULL)
						defaultbrush_exit = CreateSolidBrush(RGB(255, 255, 255));

					HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));

					HGDIOBJ old_pen = SelectObject(item->hdc, pen);
					HGDIOBJ old_brush = SelectObject(item->hdc, defaultbrush_exit);

					RoundRect(item->hdc, item->rc.left, item->rc.top, item->rc.right, item->rc.bottom, 0, 0);

					SelectObject(item->hdc, old_pen);
					SelectObject(item->hdc, old_brush);
					DeleteObject(pen);

					return CDRF_DODEFAULT;
				}
			}

			return CDRF_DODEFAULT;
		}
		break;

		// buttons handler
		case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{
			case IDC_CANCEL_BUTTON:
			{
				//createList(hwnd);
			}
			break;
			case IDC_PUSHLIKE_BUTTON:
			{
				if (ptrFunk2)
					ptrFunk2();
			}
			break;
			case IDC_EXIT_BUTTON:
			{
				EnableWindow(hwndParent, TRUE);
				SendMessage(hwnd, WM_CLOSE, 0, 0);
			}
			break;
			}
		}
		break;

		case WM_NCHITTEST:
		{
			LRESULT currentArea = DefWindowProc(hwnd, uMsg, wParam, lParam);
			if (HTCLIENT == currentArea)
				return HTCAPTION;
			return currentArea;
		}
		break;

		// create components
		case WM_CREATE:
		{
			EnableWindow(hwndParent, FALSE);

			RECT rect;
			GetWindowRect(hwnd, &rect);
			sx = rect.right - rect.left;
			sy = rect.bottom - rect.top;

			createComboBox(hwnd);
			createScrollBar(hwnd);
			

			
			//createLine(hwnd, 10, 200, 500, 200, 255, 0, 0);

			HWND Exit_Button = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("✕"), // ✖ × ⨉ ✕ ❌
				WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
				562, 13 - 3, 24, 24, hwnd, (HMENU)IDC_EXIT_BUTTON, NULL, NULL);
			if (Exit_Button == NULL)
			{
				MessageBox(NULL, TEXT("Button Creation Failed!"), TEXT("Error!"), MB_ICONEXCLAMATION);
				exit(EXIT_FAILURE);
			}

			HWND Cancel_Button = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("Cancel"),
				WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
				16, (sy - 22 - 18), 69, 22, hwnd, (HMENU)IDC_CANCEL_BUTTON, NULL, NULL);
			if (Cancel_Button == NULL)
			{
				MessageBox(NULL, TEXT("Button Creation Failed!"), TEXT("Error!"), MB_ICONEXCLAMATION);
				exit(EXIT_FAILURE);
			}

			HWND Pushlike_Button = CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("Share for Rewiew"),
				WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX | BS_PUSHLIKE,
				(sx - 122 - 16), (sy - 22 - 18), 122, 22, hwnd, (HMENU)IDC_PUSHLIKE_BUTTON, NULL, NULL);
			if (Pushlike_Button == NULL)
			{
				MessageBox(NULL, TEXT("Button Creation Failed!"), TEXT("Error!"), MB_ICONEXCLAMATION);
				exit(EXIT_FAILURE);
			}

			SendMessage(Cancel_Button, WM_SETFONT, (LPARAM)GetStockObject(DEFAULT_GUI_FONT), true);
			SendMessage(Exit_Button, WM_SETFONT, (LPARAM)GetStockObject(DEFAULT_GUI_FONT), true);
			SendMessage(Pushlike_Button, WM_SETFONT, (LPARAM)GetStockObject(DEFAULT_GUI_FONT), true);

			const HDC hdcWin = GetDC(hwnd);
			hdcMemSurface = CreateCompatibleDC(hdcWin);
			ReleaseDC(hwnd, hdcWin);

			return 0;
		}
		break;

		case WM_CLOSE:
		{
			DestroyWindow(hwnd);
			return 0;
		}
		break;

		case WM_DESTROY:
		{
			DeleteObject(defaultbrush);
			DeleteObject(selectbrush);
			DeleteObject(hotbrush);
			DeleteObject(defaultbrush_cancel);
			DeleteObject(selectbrush_cancel);
			DeleteObject(hotbrush_cancel);
			DeleteObject(defaultbrush_exit);
			DeleteObject(selectbrush_exit);
			DeleteObject(hotbrush_exit);

			defaultbrush = NULL;
			selectbrush = NULL;
			hotbrush = NULL;
			defaultbrush_cancel = NULL;
			selectbrush_cancel = NULL;
			hotbrush_cancel = NULL;
			defaultbrush_exit = NULL;
			selectbrush_exit = NULL;
			hotbrush_exit = NULL;

			DestroyWindow(hwnd);

			const HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hwnd, -6);
			UnregisterClass(LPCWSTR("newWinndow"), hInstance);

			return 0;
		}
		break;

		case WM_SET_ICON_PATH:
		{
			LPCTSTR iconPath = (LPCTSTR)lParam;
			const HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hwnd, -6);

			// image
			image.hBitmap = (HBITMAP)LoadImage(
				hInstance,
				iconPath,
				IMAGE_BITMAP,
				0, 0,
				LR_LOADFROMFILE | LR_CREATEDIBSECTION
			);

			BITMAP bitmapInfo;
			GetObject(image.hBitmap, sizeof(bitmapInfo), &bitmapInfo);
			image.width = bitmapInfo.bmWidth;
			image.height = bitmapInfo.bmHeight;

			const HDC hdc = GetDC(hwnd);

			// icon
			SelectObject(hdcMemSurface, image.hBitmap);
			BitBlt(
				hdc,
				14, 7,
				image.width, image.height,
				hdcMemSurface,
				0, 0,
				SRCCOPY
			);

			return 0;
		}
		break;

		case WM_TEXT_HEADER:
		{
			LPCTSTR str = (LPCTSTR)lParam;
			HDC dc = GetDC(hwnd);
			RECT rc;
			HFONT font;
			HGDIOBJ old;

			font = CreateFont(21.86, 0, 0, 0, 500, ANSI_CHARSET, 0U, 0U, 0U, 0U, 0U, 0U, 0U, TEXT("Avenir Next"));
			old = SelectObject(dc, font);

			GetClientRect(hwnd, &rc);
			rc.left = 74;
			rc.top = 14;
			rc.right = 300;
			rc.bottom = rc.top + 22;
			SetBkMode(dc, TRANSPARENT);
			SetTextColor(dc, RGB(29, 40, 56));

			DrawText(dc, str, lstrlen(str), &rc, DT_CENTER);

			SelectObject(dc, old);
			ReleaseDC(hwnd, dc);
			DeleteObject(font);
			return 0;
		}
		break;

		case WM_TEXT_BOTTOM_MSG:
		{
			LPCTSTR str = (LPCTSTR)lParam;
			HDC dc = GetDC(hwnd);
			RECT rc;
			HFONT font;
			HGDIOBJ old;

			font = CreateFont(18.75, 0, 0, 0, 400, ANSI_CHARSET, 0U, 0U, 0U, 0U, 0U, 0U, 0U, TEXT("Roboto"));
			old = SelectObject(dc, font);

			GetClientRect(hwnd, &rc);
			rc.left = 0;
			rc.top = 113;
			rc.right = 600;
			rc.bottom = rc.top + 19;
			SetBkMode(dc, TRANSPARENT);
			SetTextColor(dc, RGB(29, 40, 56));

			DrawText(dc, str, lstrlen(str), &rc, DT_CENTER);

			SelectObject(dc, old);
			ReleaseDC(hwnd, dc);
			DeleteObject(font);
			return 0;
		}
		break;

		case WM_TEXT_TOP_MSG:
		{
			LPCTSTR str = (LPCTSTR)lParam;
			HDC dc = GetDC(hwnd);
			RECT rc;
			HFONT font;
			HGDIOBJ old;

			font = CreateFont(18.75, 0, 0, 0, 400, ANSI_CHARSET, 0U, 0U, 0U, 0U, 0U, 0U, 0U, TEXT("Roboto"));
			old = SelectObject(dc, font);

			GetClientRect(hwnd, &rc);
			rc.left = 0;
			rc.top = 82;
			rc.right = 600;
			rc.bottom = rc.top + 19;
			SetBkMode(dc, TRANSPARENT);
			SetTextColor(dc, RGB(242, 139, 47));

			DrawText(dc, str, lstrlen(str), &rc, DT_CENTER);

			SelectObject(dc, old);
			ReleaseDC(hwnd, dc);
			DeleteObject(font);
			return 0;
		}
		break;

		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			const HDC hdc = BeginPaint(hwnd, &ps);

			createList(hwnd);

			// text
			createText(hwnd, "File", "Roboto", 16.41, 400, 50, 65, 82, { 16, 66, 27+16, 36+66 });

			// 1 lines
			createLine(hwnd, 0, 118, sx, 118, 198, 204, 217);

			// 2 lines
			createLine(hwnd, 60, 0, 60, 49, 198, 204, 217);
			createLine(hwnd, 0, 49, sx, 49, 198, 204, 217);

			// rect
			r.top = sy-58;
			r.left = 0;
			r.right = sx;
			r.bottom = sy;
			FillRect(hdc, &r, HBRUSH(CreateSolidBrush(RGB(241, 242, 246))));

			LinePen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
			SelectObject(hdc, LinePen);
			// rect
			MoveToEx(hdc, 0, 0, (LPPOINT)NULL);
			LineTo(hdc, 0, sy);
			MoveToEx(hdc, 0, 0, (LPPOINT)NULL);
			LineTo(hdc, sx, 0);
			MoveToEx(hdc, 0, sy-1, (LPPOINT)NULL);
			LineTo(hdc, sx, sy-1);
			MoveToEx(hdc, sx-1, sy, (LPPOINT)NULL);
			LineTo(hdc, sx-1, 0);

			EndPaint(hwnd, &ps);
			return 0;
		}
		break;
		}

		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	};
	wc.lpszClassName = LPCWSTR("newWinndow");
	wc.lpszMenuName = nullptr;
	wc.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClassEx(&wc))
		return EXIT_FAILURE;

	hwnd = CreateWindow(wc.lpszClassName, TEXT("Share for Review in Colab"), WS_POPUP, 400, 300, width, height, nullptr, nullptr, wc.hInstance, nullptr);
	if (hwnd == INVALID_HANDLE_VALUE)
		return EXIT_FAILURE;

	UpdateWindow(hwnd);
	ShowWindow(hwnd, SW_SHOW);

	return static_cast<int>(msg.wParam);
}


CATSelectWindow::CATSelectWindow(char * iIdentifier) : msg(), hwnd(), hwndParent(GetForegroundWindow()), wc(), className(iIdentifier)
{

}

CATSelectWindow::~CATSelectWindow()
{
	DestroyWindow(hwnd);

	const HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hwnd, -6);
	UnregisterClass(LPCWSTR("newWinndow"), hInstance);
}

void CATSelectWindow::setIconPath(char * iconPath)
{
	CString DelVar(iconPath);
	SendMessage(hwnd, WM_SET_ICON_PATH, NULL, (LPARAM)((LPCTSTR)DelVar));
}

void CATSelectWindow::setTitle(char * text)
{
	CString DelVar(text);
	SendMessage(hwnd, WM_TEXT_HEADER, NULL, (LPARAM)((LPCTSTR)DelVar));
}

void CATSelectWindow::setTopText(char * text)
{
	CString DelVar(text);
	SendMessage(hwnd, WM_TEXT_TOP_MSG, NULL, (LPARAM)((LPCTSTR)DelVar));
}

void CATSelectWindow::setBottomText(char * text)
{
	CString DelVar(text);
	SendMessage(hwnd, WM_TEXT_BOTTOM_MSG, NULL, (LPARAM)((LPCTSTR)DelVar));
}

void CATSelectWindow::showWindow(bool show)
{
	if (show)
		ShowWindow(hwnd, SW_SHOW);
	else
		ShowWindow(hwnd, SW_HIDE);
}

void CATSelectWindow::setSize(int width, int height)
{
	this->width = width;
	this->height = height;
}

void CATSelectWindow::subscribe(func tFunk)
{
	this->ptrFunk = tFunk;
	SendMessage(hwnd, WM_SUBSCRIBE, NULL, (LPARAM)((LPCTSTR)tFunk));
}