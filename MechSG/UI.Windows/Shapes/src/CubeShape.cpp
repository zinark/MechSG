#include "../inc/CubeShape.h"

using namespace UI::Windows::Shapes;

CubeShape::CubeShape( const POINT& start, const POINT& end, const LOGPEN& pen, const LOGBRUSH& brush )
    : Shape (start, end, pen, brush)
{

}

void CubeShape::Draw( const HDC& hdc )
{
    LOGBRUSH logbrush;
    logbrush.lbStyle = BS_NULL;
    HBRUSH nullBrush = CreateBrushIndirect(&logbrush);
    
    HPEN oldHandlePen = (HPEN) SelectObject (hdc, _HandlePen);
    HBRUSH oldHandleBrush = (HBRUSH) SelectObject (hdc, nullBrush);

    const int depth = 50;
    Rectangle (hdc, _StartPoint.x + depth, _StartPoint.y + depth, _EndPoint.x + depth, _EndPoint.y + depth);
    Rectangle (hdc, _StartPoint.x, _StartPoint.y, _EndPoint.x, _EndPoint.y);
    
    MoveToEx (hdc, _StartPoint.x, _StartPoint.y, 0); LineTo (hdc, _StartPoint.x + depth, _StartPoint.y + depth);
    MoveToEx (hdc, _EndPoint.x, _StartPoint.y, 0); LineTo (hdc, _EndPoint.x + depth, _StartPoint.y + depth);
    MoveToEx (hdc, _EndPoint.x, _EndPoint.y, 0); LineTo (hdc, _EndPoint.x + depth, _EndPoint.y + depth);
    MoveToEx (hdc, _StartPoint.x, _EndPoint.y, 0); LineTo (hdc, _StartPoint.x + depth, _EndPoint.y + depth);
    

    SelectObject (hdc, oldHandleBrush);
    SelectObject (hdc, oldHandlePen);
}
