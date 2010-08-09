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

void DrawingWindowTest( HINSTANCE hInstance, int showStyle ) 
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

void SimpleWindowTest( HINSTANCE hInstance, int showStyle ) 
{
    Window w (hInstance, showStyle);
    w.SetName(L"A"); w.SetTitle(L"B");
    w.SetBackgroundColor(SampleColor());
    w.SetSize(320, 240);
    w.SetPosition(0,0);
    if (w.Create())
    {
        w.Show ();
        Application ().Start();
    }
}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE, char* cmdLine, int showStyle)
{
    ImageWindow iw (hInstance, showStyle);
    iw.SetTitle(L"MAIN");
    iw.SetName(L"CMAIN");
    iw.SetSize(800, 600);
    iw.SetPosition(10, 10);
    iw.SetBackgroundColor(SampleColor());
    iw.Create();
    iw.Show();
    Application ().Start();
}