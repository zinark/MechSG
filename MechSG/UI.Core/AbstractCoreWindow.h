#pragma once
#include <Windows.h>
namespace UI { namespace Core {

	class AbstractCoreWindow
	{
	protected:
		HINSTANCE _HInstance;
		HWND _HWnd;
		HMENU _HMenu;

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
		LOGBRUSH _BackgroundBrush;
		

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
		void SetBackgroundColor (const LOGBRUSH& brush);
		void SetMenu (const HMENU& menu);
		void SetMouseVisible (bool state);
		void ToBorderless ();
		bool Create ();
		void Show ();

		HWND& GetHWnd ()
		{
			return _HWnd;
		}

		HINSTANCE GetHInstance ()
		{
			return _HInstance;
		}

	};
}}