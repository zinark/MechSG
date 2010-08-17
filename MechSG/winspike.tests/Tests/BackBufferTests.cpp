#include <gtest/gtest.h>
#include <Windows.h>
#include <PerformanceWindow.h>
#include <BackBuffer.h>

TEST (BackBuffer, Structure)
{
	PerformanceWindow window(NULL, 1);
	BackBuffer buffer (window.GetHWnd(), 200, 200);
}