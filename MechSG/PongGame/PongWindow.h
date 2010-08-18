#pragma once
#include <Windows.h>
#include <AbstractWindow.h>
using namespace UI::Core;

class PongWindow : public AbstractWindow
{
private:
	int _MouseX;
	int _MouseY;
public:
	PongWindow(const HINSTANCE& hInst, const int& showStyle);
	~PongWindow(void);
	void OnWindowCreated();
	void OnKeyPressed(unsigned short keyCode);
	void OnMouseMove(int x, int y);
	void Loop (int fps);
};

