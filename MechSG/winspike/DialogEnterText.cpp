#include "DialogEnterText.h"
#include "resource.h"

DialogEnterText::DialogEnterText(void)
{
}


DialogEnterText::~DialogEnterText(void)
{
}

BOOL CALLBACK DialogWindowProcedure ( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_CLOSE)
	{
		EndDialog (hWnd, 0);
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

void DialogEnterText::Start( HINSTANCE hInstance, int showStyle )
{
	HWND hWinColors = CreateDialog (hInstance, MAKEINTRESOURCE (IDD_MSGDIALOG), 0, DialogWindowProcedure);
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
