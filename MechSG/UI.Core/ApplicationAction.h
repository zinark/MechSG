#pragma once
#include "Application.h"

namespace UI { namespace Core
{
	class Application;

	class ApplicationAction
	{
	protected:
		Application* _OwnerApplication;

	public:
		virtual void operator () () = 0;
		void SetOwnerApplication (Application* app)
		{
			_OwnerApplication = app;
		}

		Application* GetOwnerApplication ()
		{
			return _OwnerApplication;
		}

		ApplicationAction () {}
		virtual ~ApplicationAction () {};
	};


}}