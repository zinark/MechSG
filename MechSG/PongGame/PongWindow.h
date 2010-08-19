#pragma once
#include <Windows.h>
#include <AbstractWindow.h>
#include <DynamicSprite.h>
#include <vector>
#include "PongLogic.h"
#include <Vector2D.h>
using namespace UI::Core;
using namespace std;

class PongWindow : public AbstractWindow
{
private:
	int _MouseX;
	int _MouseY;
	DynamicSprite* _Ball;
	PongLogic _Logic;
	
	int _CPUPadY;
	int _CpuScore;
	int _PlayerScore;

public:
	PongWindow(const HINSTANCE& hInst, const int& showStyle);
	~PongWindow(void);
	void OnWindowCreated();
	void OnKeyPressed(unsigned short keyCode);
	void OnMouseMove(int x, int y);
	void Loop (int fps, unsigned int memory);
};

