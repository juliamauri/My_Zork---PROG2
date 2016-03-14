#include <stdio.h>

#include "world.h"
#include "players.h"



void Players::Movement(char dir)
{
	switch (dir)
	{
	case 'n':
		if (p->room[pos - 1].n != 0)
		{
			pos = p->room[pos - 1].n;
		}
		else
		{
			printf("Door doesn't exist.\n\n");
			p->Command();
		}
		break;

	case 's':
		if (p->room[pos - 1].s != 0)
		{
			pos = p->room[pos - 1].s;
		}
		else
		{
			printf("Door doesn't exist.\n\n");
			p->Command();
		}
		break;

	case 'e':
		if (p->room[pos - 1].e != 0)
		{
			pos = p->room[pos - 1].e;
		}
		else
		{
			printf("Door doesn't exist.\n\n");
			p->Command();
		}
		break;

	case 'w':
		if (p->room[pos - 1].w != 0)
		{
			pos = p->room[pos - 1].w;
		}
		else
		{
			printf("Door doesn't exist.\n\n");
			p->Command();
		}
		break;

	default:
		break;
	}
	printf("\n");
}