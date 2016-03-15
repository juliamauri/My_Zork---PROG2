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
			printf("You across the door!\n");
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
			printf("You across the door!\n");
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
			printf("You across the door!\n");
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
			printf("You across the door!\n");
		}
		else
		{
			printf("Door doesn't exist.\n\n");
			p->Command();
		}
		break;
	}
	printf("\n");
}

void Players::ChangeWorld(){
	if (pos == 5){
		pos = 6;
		printf("You acroos the portal!\n\n");
	}
	else if (pos == 6){
		pos = 5;
		printf("You acroos the portal!\n\n");
	}
	else{
		printf("What!?!?\n\n"); 
		p->Command();
	}
}