#include "MenuWindow.h"
using namespace UI::Core;
using namespace UI::Windows;
#include "../UI.Main/resource.h"

MenuWindow::MenuWindow( const HINSTANCE& hInst, const int& showStyle ) : AbstractWindow (hInst, showStyle)
{
    CheckMenuItem(_Menu, ID_SHAPES_RECTANGLE, MF_CHECKED);
    
    LOGBRUSH logBrush;
    logBrush.lbStyle = BS_SOLID;
    logBrush.lbColor = RGB (200, 200, 200);
    SetBackgroundColor(logBrush);

    HMENU menu = LoadMenu (_HInstance, MAKEINTRESOURCE (IDR_MENU));
    SetMenu (menu);
    
    CheckMenuItem(_Menu, ID_SHAPES_RECTANGLE, MF_CHECKED);
}

void UI::Windows::MenuWindow::OnMenuCommand( unsigned int parameter )
{
    if (parameter == ID_FILE_EXIT)
    {
        DestroyWindow(_HWnd);
    }
}

void MenuWindow::OnWindowCreated()
{
    
}

MenuWindow::~MenuWindow(void)
{

}

void MenuWindow::OnKeyPressed( unsigned int keyCode )
{
}
