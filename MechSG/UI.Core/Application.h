#pragma once
#include <Windows.h>

namespace UI { namespace Core
{
    class Application
    {
    public:
        Application(void);
        ~Application(void);
        static void Start ();
    };
}}