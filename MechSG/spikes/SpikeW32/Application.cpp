#include "Application.h"

using namespace SpikeW32;

Application::Application(void)
{
}


Application::~Application(void)
{
}

void Application::Start()
{
    MSG msg;
    ZeroMemory (&msg, sizeof(msg));
    while (GetMessage (&msg, 0,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage (&msg);
    }
}
