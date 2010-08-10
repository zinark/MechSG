#include "../inc/EllipseShape.h"

using namespace UI::Windows::Shapes;

EllipseShape::EllipseShape( const POINT& start, const POINT& end, const LOGPEN& pen, const LOGBRUSH& brush )
    : Shape (start, end, pen, brush)
{

}

void EllipseShape::Draw( const HDC& hdc )
{
    HPEN oldHandlePen = (HPEN) SelectObject (hdc, _HandlePen);
    HBRUSH oldHandleBrush = (HBRUSH) SelectObject (hdc, _HandleBrush);

    Ellipse (hdc, _StartPoint.x, _StartPoint.y, _EndPoint.x, _EndPoint.y);

    SelectObject (hdc, oldHandlePen);
    SelectObject (hdc, oldHandleBrush);
}
