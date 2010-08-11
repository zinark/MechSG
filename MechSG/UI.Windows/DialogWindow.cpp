#include "DialogWindow.h"
#include "..\UI.Main\resource.h"
using namespace UI::Windows;

DialogWindow::DialogWindow(const HINSTANCE& hInst, const int& showStyle)
    : AbstractWindow (hInst, showStyle)
{
    SetMenu (LoadMenu (_HInstance, MAKEINTRESOURCE (IDR_DIALOGMENU)));
}


DialogWindow::~DialogWindow(void)
{
}

void DialogWindow::OnMenuCommand( unsigned short parameter )
{
    if (parameter == ID_DIALOGS_MODALDIALOG)
    {
        DialogBox (_HInstance, MAKEINTRESOURCE (IDD_ABOUTBOX), _HWnd, DialogProcedure);
    }
}

void DialogWindow::OnWindowCreated()
{

}

BOOL CALLBACK DialogWindow::DialogProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    if (message == WM_COMMAND)
    {
        if (LOWORD (wParam) == IDOK)
        {
            EndDialog (hWnd, 0);
            return true;
        }
    }
    return false;
}
