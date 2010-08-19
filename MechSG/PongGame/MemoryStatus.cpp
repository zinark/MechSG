#include "MemoryStatus.h"
#include <windows.h>

MemoryStatus::MemoryStatus(void)
{
}


MemoryStatus::~MemoryStatus(void)
{
}

unsigned int MemoryStatus::GetFreeMemory()
{
	MEMORYSTATUS status;
	GlobalMemoryStatus(&status);
	return status.dwAvailPhys;
}
