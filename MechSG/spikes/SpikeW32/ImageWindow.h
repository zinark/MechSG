#pragma once
#include "AbstractWindow.h"
#include <vector>
using namespace std;
using namespace SpikeW32;

namespace SpikeW32
{
    class ImageWindow : public AbstractWindow
    {
    private:

    public:
        ImageWindow (const HINSTANCE& hInst, const int& showStyle) : AbstractWindow (hInst, showStyle)
        {
        }
        ~ImageWindow(void);

    protected:
        void OnWindowCreated ();
        void OnMousePressed(int x, int y, MouseButton mouseButton);
        void OnMouseReleased(int x, int y, MouseButton mouseButton);
        void OnMouseMove(int x, int y);
        void OnPaint(const HDC& hdc);
        void OnKeyPressed(unsigned int keyCode);
    };
}
