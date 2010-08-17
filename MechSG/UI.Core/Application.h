#pragma once
#include <Windows.h>

namespace UI { namespace Core
{
	class ApplicationAction
	{
	public:
		virtual void operator () () = 0;
	};

	class Application
	{
	public:
		Application(void);
		~Application(void);
		static void Start (ApplicationAction& action);
		static void Start ();
	};
}}