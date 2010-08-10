#include "Shape.h"
using namespace UI::Windows::Shapes;

namespace UI { namespace Windows { namespace Shapes { 

    class LineShape : public Shape
    {
    public:
        LineShape (const POINT& start, const POINT& end, const LOGPEN& pen, const LOGBRUSH& brush );
        void Draw (const HDC& hdc);
    };

}}}