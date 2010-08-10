#include "../inc/LineShape.h"

using namespace UI::Windows::Shapes;

LineShape::LineShape( const POINT& start, const POINT& end, const LOGPEN& pen, const LOGBRUSH& brush )
    : Shape (start, end, pen, brush)
{

}

void LineShape::Draw( const HDC& hdc )
{
    HPEN oldHandlePen = (HPEN) SelectObject (hdc, _HandlePen);
    HBRUSH oldHandleBrush = (HBRUSH) SelectObject (hdc, _HandleBrush);

    MoveToEx (hdc, _StartPoint.x, _StartPoint.y, 0);
    LineTo(hdc, _EndPoint.x, _EndPoint.y );

    SelectObject (hdc, oldHandlePen);
    SelectObject (hdc, oldHandleBrush);
}
