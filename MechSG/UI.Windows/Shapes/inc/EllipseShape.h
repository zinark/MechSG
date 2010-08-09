#include "Shape.h"

namespace UI { namespace Core { namespace Shapes { 

    class EllipseShape : public Shape
    {
    public:
        EllipseShape (const POINT& start, const POINT& end, const LOGPEN& pen, const LOGBRUSH& brush );
        void Draw (const HDC& hdc);
    };

}}}