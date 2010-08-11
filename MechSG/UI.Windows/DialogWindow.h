#pragma once
#include "AbstractWindow.h"

using namespace UI::Core;

namespace UI { namespace Windows {

    class DialogWindow : public AbstractWindow
    {
    public:
        DialogWindow(const HINSTANCE& hInst, const int& showStyle);
        ~DialogWindow(void);
        void OnMenuCommand(unsigned short parameter);
        void OnWindowCreated();

    protected:
        static BOOL CALLBACK DialogProcedure (HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
    };

}}