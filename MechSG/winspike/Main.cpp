#include <Windows.h>
#include "resource.h"
#include <iostream>
#include <string>
using namespace std;

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

BOOL CALLBACK DialogWindowProcedure ( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_CLOSE)
	{
		PostQuitMessage(0);
	}

	if (message == WM_INITDIALOG)
	{
		HWND hEditBox = GetDlgItem (hWnd, IDC_MSGTEXT);
		SetWindowText (hEditBox, "Enter a message");
		return true;
	}

	if (message == WM_COMMAND)
	{
		if (wParam == IDB_POSTMESSAGE)
		{
			char msg[256];
			GetWindowText (GetDlgItem (hWnd, IDC_MSGTEXT), msg, 256);
			MessageBox (hWnd, msg, msg, MB_OK);
		}
	}

	if (message == WM_DESTROY)
	{
		PostQuitMessage(0);
	}
	return false;
}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE TEMP, char* cmdLine, int showStyle)
{
	//HWND hWnd = CreateDialog (hInstance, MAKEINTRESOURCE (IDD_MSGDIALOG), 0, DialogWindowProcedure);
	//ShowWindow (hWnd, showStyle);
	//UpdateWindow(hWnd);

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