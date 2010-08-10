#include "MenuWindow.h"
#include "../UI.Main/resource.h"
#include "Shapes/inc/LineShape.h"
#include "Shapes/inc/EllipseShape.h"
#include "Shapes/inc/RectangleShape.h"
#include "Shapes/inc/CubeShape.h"

using namespace UI::Core;
using namespace UI::Windows;

void MenuWindow::InitDrawingDefaults() 
{
    _CurrentShape = 0;

    _LastShapeID = ID_SHAPES_LINE;
    _LastPenColorID = ID_PEN_BLACK;
    _LastPenStyleID = ID_PEN_SOLID;
    _LastBrushColorID = ID_BRUSH_RED;
    _LastBrushStyleID = ID_BRUSH_SOLID;

    _ColorRed = RGB (240, 90, 90);
    _ColorBlack = RGB (40, 40, 40);

    _StartPoint.x = 0;
    _StartPoint.y = 0;
    _EndPoint.x = 0;
    _EndPoint.y = 0;

    _SelectedBrush.lbColor = _ColorRed;
    _SelectedBrush.lbStyle = BS_SOLID;

    _SelectedPen.lopnColor = _ColorBlack;
    _SelectedPen.lopnStyle = PS_SOLID;
    _SelectedPen.lopnWidth.x = 1;
    _SelectedPen.lopnWidth.y = 1;

    _CurrentShape = new LineShape (_StartPoint, _EndPoint, _SelectedPen, _SelectedBrush);

    _GhostShapeVisible = false;
}

MenuWindow::MenuWindow( const HINSTANCE& hInst, const int& showStyle ) : AbstractWindow (hInst, showStyle)
{
    LOGBRUSH logBrush;
    logBrush.lbStyle = BS_SOLID;
    logBrush.lbColor = RGB (200, 200, 200);
    SetBackgroundColor(logBrush);

    HMENU menu = LoadMenu (_HInstance, MAKEINTRESOURCE (IDR_MENU));
    SetMenu (menu);

    InitDrawingDefaults();
}

void MenuWindow::OnWindowCreated()
{
    CheckMenuItem(_HMenu, _LastShapeID, MF_CHECKED);
    CheckMenuItem(_HMenu, _LastPenColorID, MF_CHECKED);
    CheckMenuItem(_HMenu, _LastPenStyleID, MF_CHECKED);
    CheckMenuItem(_HMenu, _LastBrushColorID, MF_CHECKED);
    CheckMenuItem(_HMenu, _LastBrushStyleID, MF_CHECKED);
}


void MenuWindow::OnMenuCommand( unsigned short parameter )
{
    if (parameter == ID_FILE_EXIT)
    {
        DestroyWindow(_HWnd);
        return;
    }

    // SHAPES
    if (parameter == ID_SHAPES_LINE)
    {
        CheckMenuItem(_HMenu, _LastShapeID, MF_UNCHECKED);
        CheckMenuItem(_HMenu, parameter, MF_CHECKED);
        _LastShapeID = parameter;
        return;
    }

    if (parameter == ID_SHAPES_ELLIPSE)
    {
        CheckMenuItem(_HMenu, _LastShapeID, MF_UNCHECKED);
        CheckMenuItem(_HMenu, parameter, MF_CHECKED);
        _LastShapeID = parameter;
        return;
    }

    if (parameter == ID_SHAPES_RECTANGLE)
    {
        CheckMenuItem(_HMenu, _LastShapeID, MF_UNCHECKED);
        CheckMenuItem(_HMenu, parameter, MF_CHECKED);
        _LastShapeID = parameter;
        return;
    }

    if (parameter == ID_SHAPES_CUBE)
    {
        CheckMenuItem (_HMenu, _LastShapeID, MF_UNCHECKED);
        CheckMenuItem (_HMenu, parameter, MF_CHECKED);
        _LastShapeID = parameter;
        return;
    }


    // PEN STYLE
    if (parameter == ID_PEN_SOLID)
    {
        _SelectedPen.lopnStyle = PS_SOLID;
        CheckMenuItem(_HMenu, _LastPenStyleID, MF_UNCHECKED);
        CheckMenuItem(_HMenu, parameter, MF_CHECKED);
        _LastPenStyleID = parameter;
        return;
    }

    if (parameter == ID_PEN_DOTTED)
    {
        _SelectedPen.lopnStyle = PS_DOT;
        CheckMenuItem(_HMenu, _LastPenStyleID, MF_UNCHECKED);
        CheckMenuItem(_HMenu, parameter, MF_CHECKED);
        _LastPenStyleID = parameter;
        return;
    }

    if (parameter == ID_PEN_DASHED)
    {
        _SelectedPen.lopnStyle = PS_DASH;
        CheckMenuItem(_HMenu, _LastPenStyleID, MF_UNCHECKED);
        CheckMenuItem(_HMenu, parameter, MF_CHECKED);
        _LastPenStyleID = parameter;
        return;
    }

    // BRUSH STYLE
    if (parameter == ID_BRUSH_SOLID)
    {
        _SelectedBrush.lbStyle = BS_SOLID;
        CheckMenuItem(_HMenu, _LastBrushStyleID, MF_UNCHECKED);
        CheckMenuItem(_HMenu, parameter, MF_CHECKED);
        _LastBrushStyleID = parameter;
        return;
    }

    if (parameter == ID_BRUSH_NULL)
    {
        _SelectedBrush.lbStyle = BS_NULL;
        CheckMenuItem(_HMenu, _LastBrushStyleID, MF_UNCHECKED);
        CheckMenuItem(_HMenu, parameter, MF_CHECKED);
        _LastBrushStyleID = parameter;
        return;
    }

    if (parameter == ID_BRUSH_CROSS)
    {
        _SelectedBrush.lbStyle = BS_HATCHED;
        _SelectedBrush.lbHatch = HS_CROSS;
        CheckMenuItem(_HMenu, _LastBrushStyleID, MF_UNCHECKED);
        CheckMenuItem(_HMenu, parameter, MF_CHECKED);
        _LastBrushStyleID = parameter;
        return;
    }

    if (parameter == ID_BRUSH_DIAGONAL)
    {
        _SelectedBrush.lbStyle = BS_HATCHED;
        _SelectedBrush.lbHatch = HS_BDIAGONAL;
        CheckMenuItem(_HMenu, _LastBrushStyleID, MF_UNCHECKED);
        CheckMenuItem(_HMenu, parameter, MF_CHECKED);
        _LastBrushStyleID = parameter;
        return;
    }

    // PEN COLOR
    if (parameter == ID_PEN_BLACK)
    {
        _SelectedPen.lopnColor = _ColorBlack;
        CheckMenuItem (_HMenu, _LastPenColorID, MF_UNCHECKED);
        CheckMenuItem (_HMenu, parameter, MF_CHECKED);
        _LastPenColorID = parameter;
        return;
    }

    if (parameter == ID_PEN_RED)
    {
        _SelectedPen.lopnColor = _ColorRed;
        CheckMenuItem (_HMenu, _LastPenColorID, MF_UNCHECKED);
        CheckMenuItem (_HMenu, parameter, MF_CHECKED);
        _LastPenColorID = parameter;
        return;
    }

    //BRUSH COLOR
    if (parameter == ID_BRUSH_BLACK)
    {
        _SelectedBrush.lbColor = _ColorBlack;
        CheckMenuItem (_HMenu, _LastBrushColorID, MF_UNCHECKED);
        CheckMenuItem (_HMenu, parameter, MF_CHECKED);
        _LastBrushColorID = parameter;
        return;
    }

    if (parameter == ID_BRUSH_RED)
    {
        _SelectedBrush.lbColor = _ColorRed;
        CheckMenuItem (_HMenu, _LastBrushColorID, MF_UNCHECKED);
        CheckMenuItem (_HMenu, parameter, MF_CHECKED);
        _LastBrushColorID = parameter;
        return;
    }

    // FILE

    if (parameter == ID_FILE_UNDO)
    {
        if (_Shapes.size() <= 0) return;
        
        _Shapes.pop_back();
        _CurrentShape = 0;
        
        InvalidateRect(_HWnd, 0, true);
        return;
    }

}

void MenuWindow::OnMousePressed( int x, int y, MouseButton mouseButton )
{
    if (mouseButton != Left) return;

    if (_LastShapeID == ID_SHAPES_LINE)
    {
        _CurrentShape = new LineShape (_StartPoint, _EndPoint, _SelectedPen, _SelectedBrush);
    }
    
    if (_LastShapeID == ID_SHAPES_ELLIPSE)
    {
        _CurrentShape = new EllipseShape (_StartPoint, _EndPoint, _SelectedPen, _SelectedBrush);
    }
    
    if (_LastShapeID == ID_SHAPES_RECTANGLE)
    {
        _CurrentShape = new RectangleShape (_StartPoint, _EndPoint, _SelectedPen, _SelectedBrush);
    }

    if (_LastShapeID == ID_SHAPES_CUBE)
    {
        _CurrentShape = new CubeShape (_StartPoint, _EndPoint, _SelectedPen, _SelectedBrush);
    }

    SetCapture (_HWnd);
    _StartPoint.x = x;
    _StartPoint.y = y;
    _CurrentShape->SetStartPoint(_StartPoint);
    _GhostShapeVisible = true;
}

void MenuWindow::OnMouseReleased( int x, int y, MouseButton mouseButton )
{
    if (mouseButton != Left) return;

    ReleaseCapture();
    _EndPoint.x = x;
    _EndPoint.y = y;
    _CurrentShape->SetEndPoint(_EndPoint);
    _GhostShapeVisible = false;
    _Shapes.push_back(_CurrentShape);
    InvalidateRect(_HWnd, 0, false);
}

void MenuWindow::OnMouseMove( int x, int y )
{
    if (!_GhostShapeVisible) return;
    
    _EndPoint.x = x;
    _EndPoint.y = y;
    _CurrentShape->SetEndPoint(_EndPoint);
    InvalidateRect(_HWnd, 0, true);
}


void MenuWindow::OnKeyPressed( unsigned short keyCode )
{
}

MenuWindow::~MenuWindow(void)
{

}

void MenuWindow::OnPaint( const HDC& hdc )
{
    for (int i=0; i<_Shapes.size(); ++i)
    {
        _Shapes[i]->Draw(hdc);
    }
    
    if (_CurrentShape != 0)
        _CurrentShape->Draw(hdc);
}

