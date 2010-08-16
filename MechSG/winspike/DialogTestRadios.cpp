#include "DialogTestRadios.h"
#include <Windows.h>
#include <string>
using namespace std;

DialogTestRadios::DialogTestRadios(void)
{
}


DialogTestRadios::~DialogTestRadios(void)
{
}

BOOL CALLBACK ColorsDialogWindowProcedure ( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int selected = IDC_RADIO_RED;

	if (message == WM_CLOSE)
	{
		PostQuitMessage(0);
	}

	if (message == WM_INITDIALOG)
	{
		CheckRadioButton(hWnd, IDC_RADIO_RED, IDC_RADIO_BLACK, IDC_RADIO_RED);
	}

	if (message == WM_COMMAND)
	{
		if (LOWORD (wParam) == IDC_RADIO_RED) selected = IDC_RADIO_RED;
		if (LOWORD (wParam) == IDC_RADIO_GREEN) selected = IDC_RADIO_GREEN;
		if (LOWORD (wParam) == IDC_RADIO_YELLOW) selected = IDC_RADIO_YELLOW;
		if (LOWORD (wParam) == IDC_RADIO_BLACK) selected = IDC_RADIO_BLACK;

		CheckRadioButton(hWnd, IDC_RADIO_RED, IDC_RADIO_BLACK, selected);

		if (LOWORD(wParam) == IDOK)
		{
			string selections[4] = {"RED", "GREEN", "YELLOW", "BLACK"};

			char msg[256];
			int id = selected - IDC_RADIO_RED;
			sprintf(msg, "Result = %d %s\0", selected, selections[id].c_str());
			MessageBox (hWnd, msg, "Hehe", MB_OK);
		}

	}
	return false;
}

void DialogTestRadios::Start(HINSTANCE hInstance, int showStyle)
{
	HWND hWinColors = CreateDialog (hInstance, MAKEINTRESOURCE (IDD_DIALOG1), 0, ColorsDialogWindowProcedure);
	ShowWindow (hWinColors, showStyle);
	UpdateWindow(hWinColors);


	MSG msg;
	ZeroMemory (&msg, sizeof(msg));
	while (GetMessage (&msg, 0,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage (&msg);
	}
}
