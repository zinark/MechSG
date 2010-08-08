#include <Windows.h>
#include "Application.h"
#include "Window.h"
using namespace SpikeW32;

HBRUSH SampleColor ()
{
    LOGBRUSH lb;
    lb.lbColor = RGB (100, 90, 90);
    lb.lbStyle = BS_SOLID;
    return CreateBrushIndirect(&lb);
}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE, char* cmdLine, int showStyle)
{
    Window window (hInstance, showStyle);
    window.SetTitle (L"XWin");
    window.SetName(L"XWinClass");
    window.SetPosition (0, 0);
    window.SetSize (800, 600);
    
    // window.SetBackgroundColor (SampleColor ());
    if (!window.Create ()) return false;
    
    window.Show ();
    Application ().Start ();
}