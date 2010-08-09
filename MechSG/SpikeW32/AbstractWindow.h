#pragma once
#include "AbstractCoreWindow.h"
#include <Windows.h>
using namespace SpikeW32;

namespace SpikeW32
{
    enum MouseButton
    {
        Left, Right, Middle
    };

    class AbstractWindow : public AbstractCoreWindow
    {
    public:
        AbstractWindow (const HINSTANCE& hInst, const int& showStyle);
        virtual ~AbstractWindow(void);
        LRESULT CALLBACK WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

    protected:
        PAINTSTRUCT _PaintStruct;

        virtual void OnWindowCreated () {}
        virtual void OnWindowDestroyed () {}

        virtual void OnKeyPressed (unsigned int keyCode) {}
        virtual void OnMousePressed (int x, int y, MouseButton mouseButton) {}
        virtual void OnMouseReleased (int x, int y, MouseButton mouseButton) {}
        virtual void OnMouseMove (int x, int y) {}
        virtual void OnPaint (const HDC& hdc) {}
    };
}
