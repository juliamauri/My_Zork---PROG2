#include <stdio.h>
#include "world.h"

int main()
{
	World Sock;

	Sock.CreateWorld();

	Sock.Loop();

	return 0;
}