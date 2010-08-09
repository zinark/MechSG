#include "Shape.h"
using namespace UI::Core::Shapes;

namespace UI { namespace Core { namespace Shapes { 

    class LineShape : public Shape
    {
    public:
        LineShape (const POINT& start, const POINT& end, const LOGPEN& pen, const LOGBRUSH& brush );
        void Draw (const HDC& hdc);
    };

}}}