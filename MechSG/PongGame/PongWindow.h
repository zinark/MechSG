#pragma once
#include <Windows.h>
#include <AbstractWindow.h>
#include <DynamicSprite.h>
using namespace UI::Core;

class PongWindow : public AbstractWindow
{
private:
	int _MouseX;
	int _MouseY;
	DynamicSprite* _Ball;
public:
	PongWindow(const HINSTANCE& hInst, const int& showStyle);
	~PongWindow(void);
	void OnWindowCreated();
	void OnKeyPressed(unsigned short keyCode);
	void OnMouseMove(int x, int y);
	void Loop (int fps, unsigned int memory);
};

