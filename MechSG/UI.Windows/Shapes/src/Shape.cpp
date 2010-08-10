#include "../inc/Shape.h"

using namespace UI::Windows::Shapes;

Shape::Shape( const POINT& start, const POINT& end, const LOGPEN& pen, const LOGBRUSH& brush )
{
    _StartPoint = start;
    _EndPoint = end;
    _HandlePen = CreatePenIndirect(&pen);
    _HandleBrush = CreateBrushIndirect(&brush);
}

Shape::~Shape()
{
    DeleteObject (_HandlePen);
    DeleteObject (_HandleBrush);
}

void Shape::SetStartPoint( const POINT& point )
{
    _StartPoint = point;
}

void Shape::SetEndPoint( const POINT& point )
{
    _EndPoint = point;
}
