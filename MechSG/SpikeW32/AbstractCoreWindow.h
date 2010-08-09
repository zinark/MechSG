#pragma once
#include <Windows.h>
namespace SpikeW32
{
    class AbstractCoreWindow
    {
    protected:
        HINSTANCE _HInstance;
        HWND _HWnd;

        int GetWidth () { return _Width;}
        int GetHeight () { return _Height;}

    private:
        int _ShowStyle;

        const WCHAR* _Title;
        const WCHAR* _Name;
        int _Width;
        int _Height;
        int _X;
        int _Y;
        HBRUSH _Background;

        virtual LRESULT CALLBACK WindowProcedure (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam ) = 0;
        static LRESULT CALLBACK MessageRouter (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

        void SetHWnd (HWND hWnd)
        {
            _HWnd = hWnd;
        }

    public:
        AbstractCoreWindow( const HINSTANCE& hInstance, const int& showStyle );
        virtual ~AbstractCoreWindow(void);

        void SetSize (const int& width, const int& height);
        void SetPosition (const int& x, const int& y);
        void SetTitle (const WCHAR* title);
        void SetName (const WCHAR* name );
        void SetBackgroundColor (const HBRUSH& brush);
        bool Create ();
        void Show ();

        
    };
}