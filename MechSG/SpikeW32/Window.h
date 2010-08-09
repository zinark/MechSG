#pragma once
#include <Windows.h>
namespace SpikeW32
{
    enum MouseButton
    {
        Left, Right, Middle
    };

    class Window
    {
    protected:
        HINSTANCE _ApplicationInstanceHandle;
        HWND _hWnd;

    private:
        int _ShowStyle;

        const WCHAR* _Title;
        const WCHAR* _Name;
        int _Width;
        int _Height;
        int _X;
        int _Y;
        HBRUSH _Background;

        LRESULT CALLBACK WindowProcedure (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );
        static LRESULT CALLBACK MessageRouter (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

        void SetHWnd (HWND hWnd)
        {
            _hWnd = hWnd;
        }

    public:
        Window( const HINSTANCE& hInstance, const int& showStyle );
        virtual ~Window(void);

        void SetSize (const int& width, const int& height);
        void SetPosition (const int& x, const int& y);
        void SetTitle (const WCHAR* title);
        void SetName (const WCHAR* name );
        void SetBackgroundColor (const HBRUSH& brush);
        bool Create ();
        void Show ();

    protected:
        virtual void OnKeyPressed (unsigned int keyCode) {}
        virtual void OnMousePressed (int x, int y, MouseButton mouseButton) {}
        virtual void OnMouseReleased (int x, int y, MouseButton mouseButton) {}
        virtual void OnMouseMove (int x, int y) {}
    };
}