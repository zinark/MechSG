#include "../inc/Shape.h"

using namespace UI::Core::Shapes;

Shape::Shape( const POINT& start, const POINT& end, const LOGPEN& pen, const LOGBRUSH& brush )
{
    _StartPoint = start;
    _EndPoint = end;
    _HandlePen = CreatePenIndirect(&pen);
    _HandleBrush = CreateBrushIndirect(&brush);
}

UI::Core::Shapes::Shape::~Shape()
{
    DeleteObject (_HandlePen);
    DeleteObject (_HandleBrush);
}

void UI::Core::Shapes::Shape::SetStartPoint( const POINT& point )
{
    _StartPoint = point;
}

void UI::Core::Shapes::Shape::SetEndPoint( const POINT& point )
{
    _EndPoint = point;
}
