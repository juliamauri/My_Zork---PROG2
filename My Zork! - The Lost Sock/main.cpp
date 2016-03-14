#include <stdio.h>
#include <string.h>

#include "world.h"

int main()
{
	World Sock;

	strcpy_s(Sock.room[0].name, "hi");

	printf("%s", Sock.room[0].name);

	getchar();

	return 0;
}