#pragma once
#include <Windows.h>
namespace UI { namespace Windows { namespace Shapes { 
    
    class Shape
    {
    protected:
        POINT _StartPoint;
        POINT _EndPoint;

        HPEN _HandlePen;
        HBRUSH _HandleBrush;

    public:
        Shape (const POINT& start, const POINT& end, const LOGPEN& pen, const LOGBRUSH& brush );
        virtual ~Shape ();
        void SetStartPoint (const POINT& point);
        void SetEndPoint (const POINT& point);
        virtual void Draw (const HDC& hdc) = 0;
    };

}}}