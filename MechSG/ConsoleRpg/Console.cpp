#include "Console.h"

CRPG::Console::Console(void)
{
}


CRPG::Console::~Console(void)
{
}

void CRPG::Console::Out( string text )
{
    cout << text << endl;
}

void CRPG::Console::ReadLine()
{
    string input;
    cin >> input;
}
