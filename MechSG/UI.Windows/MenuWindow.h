#pragma once
#include <Windows.h>
#include "AbstractWindow.h"
using namespace UI::Core;

namespace UI { namespace Windows
{
    class MenuWindow : public AbstractWindow
    {
    public:
        MenuWindow(const HINSTANCE& hInst, const int& showStyle);
        virtual ~MenuWindow(void);

    protected:
        void OnWindowCreated ();
        void OnKeyPressed(unsigned int keyCode);
        void OnMenuCommand(unsigned int parameter);
    };
}}