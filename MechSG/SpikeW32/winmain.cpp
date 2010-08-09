#include <Windows.h>
#include "Application.h"
#include "Window.h"
#include "DrawingWindow.h"
#include "ImageWindow.h"
using namespace SpikeW32;

HBRUSH SampleColor ()
{
    LOGBRUSH lb;
    lb.lbColor = RGB (250, 250, 250);
    lb.lbStyle = BS_SOLID;
    return CreateBrushIndirect(&lb);
}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE, char* cmdLine, int showStyle)
{
    DrawingWindow imgWnd (hInstance, showStyle);
    imgWnd.SetTitle(L"Drawing");
    imgWnd.SetName (L"CDrawing");
    imgWnd.SetPosition (600,0);
    imgWnd.SetSize (600,400);
    imgWnd.SetBackgroundColor (SampleColor());
    
    if (imgWnd.Create())
    {
        imgWnd.Show();
        Application ().Start ();
    }
    
}