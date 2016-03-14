#include <stdio.h>

#include "world.h"

int main()
{
	int lel = 1;
	World Sock;

	Sock.CreateWorld();

	//printf("%s", Sock.room[0].name);

	do{
		Sock.Movement();
	} while (lel != 0);

	getchar();

	return 0;
}