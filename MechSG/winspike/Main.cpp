#include <Windows.h>
#include "resource.h"
#include <iostream>
#include <string>
#include "DialogTestRadios.h"
#include "DialogEnterText.h"
#include "DialogComboBox.h"
using namespace std;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE TEMP, char* cmdLine, int showStyle)
{
	//DialogEnterText ().Start (hInstance, showStyle);
	//DialogTestRadios ().Start (hInstance, showStyle);
	DialogComboBox ().Start (hInstance, showStyle);
}