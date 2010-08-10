#include "CallbackRegistry.h"

using namespace UI::Core;

CallbackRegistry::CallbackRegistry(void)
{
}


CallbackRegistry::~CallbackRegistry(void)
{
}

void UI::Core::CallbackRegistry::Register( unsigned int messageName, MyFunctor f )
{
    f();
}
