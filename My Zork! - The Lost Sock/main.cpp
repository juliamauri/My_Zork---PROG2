#include <stdio.h>
#include "World.h"
#include "MemLeaks.h"

World* Wd = nullptr;

int main()
{
	ReportMemoryLeaks();

	Wd = new World;

	Wd->Init();

	Wd->Loop();

	return 0;
}