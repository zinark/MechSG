#pragma once
#include "AbstractWindow.h"
#include <vector>
using namespace std;
using namespace SpikeW32;

namespace SpikeW32
{
    class DrawingWindow : public AbstractWindow
    {
    private:
        vector<RECT> _Rectangles;
        RECT _CurrentRectangle;
        bool _CanDrawRectangle;

    public:
        DrawingWindow (const HINSTANCE& hInst, const int& showStyle) : AbstractWindow (hInst, showStyle)
        {
            _CanDrawRectangle = false;
        }
        ~DrawingWindow(void);

    protected:
        void OnMousePressed(int x, int y, MouseButton mouseButton);
        void OnMouseReleased(int x, int y, MouseButton mouseButton);
        void OnMouseMove(int x, int y);
        void OnPaint(const HDC& hdc);
        void OnKeyPressed(unsigned int keyCode);
    };
}
