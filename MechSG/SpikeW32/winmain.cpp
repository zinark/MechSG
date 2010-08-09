#include <Windows.h>
#include "Application.h"
#include "Window.h"
using namespace SpikeW32;

HBRUSH SampleColor ()
{
    LOGBRUSH lb;
    lb.lbColor = RGB (120, 100, 90);
    lb.lbStyle = BS_SOLID;
    return CreateBrushIndirect(&lb);
}

class MainWindow : public Window
{
public:
    MainWindow (const HINSTANCE& hInst, const int& showStyle) : Window (hInst, showStyle)
    {

    }

    void MainWindow::OnMousePressed(int x, int y, MouseButton mb )
    {
        MessageBox (_hWnd, L"Mouse Pressed", L"HEHE", MB_OK);
    }
};

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE, char* cmdLine, int showStyle)
{
    MainWindow win (hInstance, showStyle);
    win.SetTitle (L"XWin");
    win.SetName(L"XWinClass");
    win.SetPosition (0, 0);
    win.SetSize (800, 600);
    win.SetBackgroundColor (SampleColor ());
    if (!win.Create ()) return false;
    
    Window toolbox (hInstance, showStyle);
    toolbox.SetTitle (L"Toolbox");
    toolbox.SetName(L"XToolboxClass");
    toolbox.SetPosition (805, 0);
    toolbox.SetSize (200, 400);
    toolbox.SetBackgroundColor (SampleColor ());
    if (!toolbox.Create ()) return false;
    
    win.Show ();
    toolbox.Show ();
    Application ().Start ();
}