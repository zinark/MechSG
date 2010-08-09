#pragma once
#include "AbstractWindow.h"
using namespace SpikeW32;
namespace SpikeW32
{
    class Window : public AbstractWindow
    {
    public:
        Window (const HINSTANCE& hInst, const int& showStyle);
        virtual ~Window(void);
        void OnKeyPressed(unsigned int keyCode);
    };
}
