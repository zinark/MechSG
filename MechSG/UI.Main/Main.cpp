#include <Windows.h>
#include <vector>
#include "Application.h"
#include "CaseWindow.h"
#include "resource.h"

using namespace std;
using namespace UI::Windows;
using namespace UI::Core;

BOOL CALLBACK DialogProcedure ( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_COMMAND)
	{
		if (LOWORD (wParam) == IDOK)
		{
			EndDialog(hWnd, 0);
			PostQuitMessage(0);
		}
	}

	if (message == WM_CLOSE)
	{
		DestroyWindow(hWnd);
		PostQuitMessage(0);
	}

	return false;
}

void DialogBasedTest( HINSTANCE hInstance, int showStyle ) 
{
	HWND hWnd = CreateDialog (hInstance, MAKEINTRESOURCE (IDD_DIALOG1), 0, DialogProcedure);
	ShowWindow (hWnd, showStyle);
	Application().Start();
}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE TEMP, char* cmdLine, int showStyle)
{
	DialogBasedTest (hInstance, showStyle);
}

