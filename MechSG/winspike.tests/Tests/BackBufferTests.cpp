#include <gtest/gtest.h>
#include <Windows.h>
#include <PerformanceWindow.h>
#include <BackBuffer.h>
#include "../../ui.Core/Application.h"

using namespace UI::Core;

BackBuffer* buffer = 0;

class Loop : public ApplicationAction
{
public:
	void operator () ()
	{
		buffer->Draw ();
	}
};

TEST (BackBuffer, Structure)
{
	PerformanceWindow window(NULL, 1);
	buffer = new BackBuffer (window.GetHWnd(), 200, 200);
	window.Create();
	window.Show();
	Application ().Start (Loop());
	delete buffer;
}