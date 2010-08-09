#include "Shape.h"

namespace UI { namespace Core { namespace Shapes { 

    class RectangleShape : public Shape
    {
    public:
        RectangleShape (const POINT& start, const POINT& end, const LOGPEN& pen, const LOGBRUSH& brush );
        void Draw (const HDC& hdc);
    };

}}}