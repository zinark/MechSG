#include "DialogComboBox.h"
#include "resource.h"

DialogComboBox::DialogComboBox(void)
{

}


DialogComboBox::~DialogComboBox(void)
{

}

static HWND hComboBox = 0;
static HWND hTxtToAdd = 0;
static HWND hAddButton = 0;

BOOL CALLBACK DialogCallback ( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_INITDIALOG)
	{
		hTxtToAdd = GetDlgItem (hWnd, IDC_TXT_TOADD);
		hComboBox = GetDlgItem (hWnd, IDC_COMBO);
		hAddButton = GetDlgItem (hWnd, IDB_ADD);
		SetWindowText (hTxtToAdd, "Null Entry");
		return true;
	}

	if (message == WM_COMMAND)
	{
		switch (LOWORD (wParam))
		{
		case IDB_ADD:
			char msg[256];
			GetWindowText (hTxtToAdd, msg, 256);
			SendMessage (hComboBox, CB_ADDSTRING, 0, (LPARAM) msg);
			SendMessage (hComboBox, CB_SELECTSTRING, 0, (LPARAM) msg);
			break;
		}

		switch (HIWORD (wParam))
		{
		case CBN_SELENDOK:
			char msg[256];
			int index = SendMessage (hComboBox, CB_GETCURSEL, 0, 0);
			SendMessage (hComboBox, CB_GETLBTEXT, (WPARAM) index, (LPARAM) msg);
			MessageBox (hWnd, msg, msg, MB_OK);
			break;
		}
		return true;
	}


	if (message == WM_CLOSE || message == WM_DESTROY)
	{
		EndDialog(hWnd, 0);
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	}

	return false;
}

void DialogComboBox::Start( HINSTANCE hInst, int showStyle )
{
	HWND hDialog = CreateDialog (hInst, MAKEINTRESOURCE (IDD_COMBOS), NULL, DialogCallback);

	ShowWindow (hDialog, showStyle);
	UpdateWindow (hDialog);

	MSG msg;
	ZeroMemory (&msg, sizeof(msg));
	while (GetMessage (&msg, 0,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage (&msg);
	}
}
