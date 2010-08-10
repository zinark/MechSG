#pragma once

namespace UI { namespace Core
{
    class MyFunctor 
    {
    public:
        void operator () ();
    };

    class CallbackRegistry
    {
    public:
        CallbackRegistry(void);
        ~CallbackRegistry(void);
        void Register (unsigned int messageName, MyFunctor f);
    };

}}