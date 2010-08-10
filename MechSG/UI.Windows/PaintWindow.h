#pragma once
#include <Windows.h>
#include "AbstractWindow.h"
using namespace UI::Core;

namespace UI { namespace Windows
{
    class PaintWindow : public AbstractWindow
    {
    public:
        PaintWindow(const HINSTANCE& hInst, const int& showStyle) : AbstractWindow (hInst, showStyle) {}
        virtual ~PaintWindow(void);

    protected:
        void OnWindowCreated ();
        void OnKeyPressed(unsigned short keyCode);
        void OnPaint(const HDC& hdc);
    };
}}