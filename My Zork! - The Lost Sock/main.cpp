#include <stdio.h>
#include "world.h"
#include "MemLeaks.h"

int main()
{
	ReportMemoryLeaks();

	World Sock;

	Sock.Init();

	Sock.Loop();

	return 0;
}