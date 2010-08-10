#pragma once
#include <Windows.h>
#include "AbstractWindow.h"
#include "Shapes/inc/Shape.h"
#include <deque>
using namespace std;
using namespace UI::Core;
using namespace UI::Windows::Shapes;

namespace UI { namespace Windows
{
    class MenuWindow : public AbstractWindow
    {
    
    private:
        deque<Shape*> _Shapes;
        Shape* _CurrentShape;
        
        POINT _StartPoint;
        POINT _EndPoint;
        LOGBRUSH _SelectedBrush;
        LOGPEN _SelectedPen;

        unsigned int 
            _LastShapeID,
            _LastPenColorID,
            _LastPenStyleID,
            _LastBrushColorID,
            _LastBrushStyleID;

        COLORREF
            _ColorRed, _ColorBlack;

        void InitDrawingDefaults();

        bool _GhostShapeVisible;

    public:
        MenuWindow(const HINSTANCE& hInst, const int& showStyle);
        virtual ~MenuWindow(void);

    protected:
        void OnWindowCreated ();
        void OnKeyPressed(unsigned short keyCode);
        void OnMenuCommand(unsigned short parameter);
        
        void OnMousePressed(int x, int y, MouseButton mouseButton);
        void OnMouseMove(int x, int y);
        void OnMouseReleased(int x, int y, MouseButton mouseButton);
        void OnPaint(const HDC& hdc);
    };
}}