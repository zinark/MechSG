#pragma once
#include "AbstractCoreWindow.h"
#include <Windows.h>
#include "CallbackRegistry.h"
using namespace UI::Core;

namespace UI { namespace Core
{
    enum MouseButton
    {
        Left, Right, Middle
    };

    class AbstractWindow : public AbstractCoreWindow
    {
    private:
        // CallbackRegistry _CallbackRegistry;
    
    public:
        AbstractWindow (const HINSTANCE& hInst, const int& showStyle);
        virtual ~AbstractWindow(void);
        virtual LRESULT CALLBACK WindowProcedure( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

    protected:
        PAINTSTRUCT _PaintStruct;

        virtual void OnWindowCreated () = 0;
        virtual void OnWindowDestroyed () {}

        virtual void OnKeyPressed (unsigned short keyCode) {}
        virtual void OnMousePressed (int x, int y, MouseButton mouseButton) {}
        virtual void OnMouseReleased (int x, int y, MouseButton mouseButton) {}
        virtual void OnMouseMove (int x, int y)  {}
        virtual void OnPaint (const HDC& hdc) {}
        virtual void OnWindowClose () {};
        virtual void OnMenuCommand (unsigned short parameter) {}

        void RePaint (const bool& drawBackground);
    };
}
}