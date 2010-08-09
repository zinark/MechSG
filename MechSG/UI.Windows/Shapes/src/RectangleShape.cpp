#include "../inc/RectangleShape.h"

using namespace UI::Core::Shapes;

RectangleShape::RectangleShape( const POINT& start, const POINT& end, const LOGPEN& pen, const LOGBRUSH& brush )
    : Shape (start, end, pen, brush)
{

}

void RectangleShape::Draw( const HDC& hdc )
{
    HPEN oldHandlePen = (HPEN) SelectObject (hdc, _HandlePen);
    HBRUSH oldHandleBrush = (HBRUSH) SelectObject (hdc, _HandleBrush);

    Rectangle (hdc, _StartPoint.x, _StartPoint.y, _EndPoint.x, _EndPoint.y);

    SelectObject (hdc, oldHandlePen);
    SelectObject (hdc, oldHandleBrush);
}
