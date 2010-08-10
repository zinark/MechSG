#include "Shape.h"

namespace UI { namespace Windows { namespace Shapes { 

    class CubeShape : public Shape
    {
    public:
        CubeShape (const POINT& start, const POINT& end, const LOGPEN& pen, const LOGBRUSH& brush );
        void Draw (const HDC& hdc);
    };

}}}