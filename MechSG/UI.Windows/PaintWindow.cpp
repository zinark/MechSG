#include "PaintWindow.h"
#include <string>
#include <sstream>

#include <MMSystem.h>
using namespace UI::Core;
using namespace UI::Windows;
using namespace std;

void PaintWindow::OnWindowCreated()
{

}

PaintWindow::~PaintWindow(void)
{
}

void PaintWindow::OnKeyPressed( unsigned short keyCode )
{
    if (keyCode == VK_ESCAPE)
    if (MessageBox (_HWnd, "Do you quit?", "Quit", MB_YESNO) == IDYES)
    {
        PostQuitMessage(0);
    }

    InvalidateRect(_HWnd, 0, false);
}



void UI::Windows::PaintWindow::OnPaint( const HDC& hdc )
{
    unsigned long elapsed = timeGetTime();
    
    ostringstream streamElapsed;
    streamElapsed << "MilliSec = " << elapsed << "\r\n";
    string strElapsed = streamElapsed.str();
    


    __int64 countPerSecond = 0;
    QueryPerformanceFrequency((PLARGE_INTEGER) &countPerSecond);
    __int64 time = 0;
    QueryPerformanceCounter((PLARGE_INTEGER) &time);

    ostringstream streamPerformance;
    double timeScale = (double) 1.0 / (double) countPerSecond;
    streamPerformance << "CPS = " << (double) timeScale * time<< "\r\n";
    string strPerformance = streamPerformance.str();
    
    TextOut (hdc, 10, 10, strElapsed.c_str(), strElapsed.length());
    TextOut (hdc, 10, 30, strPerformance.c_str(), strPerformance.length());
    // InvalidateRect(_HWnd, 0, false);
}
