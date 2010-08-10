#include "MenuWindow.h"
#include "../UI.Main/resource.h"
#include "Shapes/inc/LineShape.h"
#include "Shapes/inc/EllipseShape.h"
#include "Shapes/inc/RectangleShape.h"

using namespace UI::Core;
using namespace UI::Windows;

MenuWindow::MenuWindow( const HINSTANCE& hInst, const int& showStyle ) : AbstractWindow (hInst, showStyle)
{
    LOGBRUSH logBrush;
    logBrush.lbStyle = BS_SOLID;
    logBrush.lbColor = RGB (200, 200, 200);
    SetBackgroundColor(logBrush);

    HMENU menu = LoadMenu (_HInstance, MAKEINTRESOURCE (IDR_MENU));
    SetMenu (menu);

    _CurrentShape = 0;
}

MenuWindow::~MenuWindow(void)
{

}

void MenuWindow::OnMenuCommand( unsigned short parameter )
{
    if (parameter == ID_FILE_EXIT)
    {
        DestroyWindow(_HWnd);
        return;
    }

    if (parameter == ID_SHAPES_LINE)
    {
        _CurrentShape = new LineShape (_StartPoint, _EndPoint, _SelectedPen, _SelectedBrush);
        CheckMenuItem(_HMenu, ID_SHAPES_LINE, MF_CHECKED);
        return;
    }

    if (parameter = ID_SHAPES_ELLIPSE)
    {
        _CurrentShape = new EllipseShape (_StartPoint, _EndPoint, _SelectedPen, _SelectedBrush);
        CheckMenuItem(_HMenu, ID_SHAPES_ELLIPSE, MF_CHECKED);
        return;
    }

    if (parameter = ID_SHAPES_RECTANGLE)
    {
        _CurrentShape = new RectangleShape (_StartPoint, _EndPoint, _SelectedPen, _SelectedBrush);
        CheckMenuItem(_HMenu, ID_SHAPES_RECTANGLE, MF_CHECKED);
        return;
    }

}

void MenuWindow::OnMouseReleased( int x, int y, MouseButton mouseButton )
{

}

void MenuWindow::OnMouseMove( int x, int y )
{

}

void MenuWindow::OnMousePressed( int x, int y, MouseButton mouseButton )
{

}

void MenuWindow::OnKeyPressed( unsigned short keyCode )
{
}

void MenuWindow::OnWindowCreated()
{
    CheckMenuItem(_HMenu, ID_SHAPES_RECTANGLE, MF_CHECKED);
    CheckMenuItem(_HMenu, ID_PEN_BLACK, MF_CHECKED);
    CheckMenuItem(_HMenu, ID_PEN_SOLID, MF_CHECKED);
    CheckMenuItem(_HMenu, ID_BRUSH_BLACK, MF_CHECKED);
    CheckMenuItem(_HMenu, ID_BRUSH_SOLID, MF_CHECKED);
}
