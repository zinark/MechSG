#pragma once
#include <Windows.h>

namespace SpikeW32
{
    class Window
    {
    private:
        HINSTANCE _ApplicationInstanceHandle;
        HWND _WindowHandle;
        int _ShowStyle;

        const WCHAR* _Title;
        const WCHAR* _Name;
        int _Width;
        int _Height;
        int _X;
        int _Y;

        static LRESULT CALLBACK WindowProcedure (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

    public:
        
        Window( const HINSTANCE& hInstance, const int& showStyle );
        ~Window(void);
        
        void SetSize (const int& width, const int& height);
        void SetPosition (const int& x, const int& y);
        void SetTitle (const WCHAR* title);
        void SetName (const WCHAR* name );
        bool Create ();
        void Show ();
    };
}