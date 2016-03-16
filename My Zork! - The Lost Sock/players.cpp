#include <stdio.h>
#include <stdlib.h>

#include "world.h"
#include "exits.h"
#include "players.h"

void Players::Look(char dir){
	switch (dir)
	{
	case 'n':
		if (p->room[pos - 1].n != 0)
			p->room[p->room[pos - 1].n].DescExit();
		else
			printf("Door doesn't exist.\n\n");
		break;
	case 's':
		if (p->room[pos - 1].s != 0)
			p->room[p->room[pos - 1].s].DescExit();
		else
			printf("Door doesn't exist.\n\n");
		break;
	case 'e':
		if (p->room[pos - 1].e != 0)
			p->room[p->room[pos - 1].e].DescExit();
		else
			printf("Door doesn't exist.\n\n");
			break;
	case 'w':
		if (p->room[pos - 1].w != 0)
			p->room[p->room[pos - 1].w].DescExit();
		else
			printf("Door doesn't exist.\n\n");
		break;
	default:
		system("cls");
		p->room[pos - 1].Desc();

		if (p->room[pos - 1].n != 0) printf("There are way at north!\n\n");
		if (pos == 6) printf("There are portal at north!\n\n");
		if (p->room[pos - 1].s != 0) printf("There are way at south!\n\n");
		if (pos == 5) printf("There are portal at south!\n\n");
		if (p->room[pos - 1].e != 0) printf("There are way at east!\n\n");
		if (p->room[pos - 1].w != 0) printf("There are way at west!\n\n");
		break;
	}
	p->Command();
}

void Players::Movement(char dir)
{
	switch (dir)
	{
	case 'n':
		if (p->room[pos - 1].n != 0)
		{
			if (p->exit[FindExit(p->room[pos - 1].n)].door != false){
				pos = p->room[pos - 1].n;
				movclose[0] = true;
				printf("You across the door!\n");
			}
			else{
				printf("The door is closed..\n\n");
				lastcloseddoor = dir;
				lastnumdoor = FindExit(pos);
				p->Command();
			}
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
			if (p->exit[FindExit(p->room[pos - 1].s)].door != false){
				pos = p->room[pos - 1].s;
				movclose[1] = true;
				printf("You across the door!\n");
			}
			else{
				printf("The door is closed..\n\n");
				lastcloseddoor = dir;
				lastnumdoor = FindExit(pos);
				p->Command();
			}
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
			if (p->exit[FindExit(p->room[pos - 1].e)].door != false){
				pos = p->room[pos - 1].e;
				movclose[2] = true;
				printf("You across the door!\n");
			}
			else{
				printf("The door is closed..\n\n");
				lastcloseddoor = dir;
				lastnumdoor = FindExit(pos);
				p->Command();
			}
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
			if (p->exit[FindExit(p->room[pos - 1].w)].door != false){
				pos = p->room[pos - 1].w;
				movclose[3] = true;
				printf("You across the door!\n");
			}
			else{
				printf("The door is closed..\n\n");
				lastcloseddoor = dir;
				lastnumdoor = FindExit(pos);
				p->Command();
			}
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

void Players::OpenDoor(char otherdir){
	bool openmethod = true;
	if (p->exit[lastnumdoor].o == pos || p->exit[lastnumdoor].d == pos){
		if (otherdir){
			lastcloseddoor = otherdir;
			openmethod = false;
		}
		switch (lastcloseddoor)
		{
		case 'n':
			if (p->room[pos - 1].n != 0){
				p->exit[FindExit(p->room[pos - 1].n)].door = true;
				printf("The north door is now open!\n\n");
				if (openmethod) lastcloseddoor = 's';
			}
			else
				printf("What are you trying?\n\n");
			break;
		case 's':
			if (p->room[pos - 1].s != 0){
				p->exit[FindExit(p->room[pos - 1].s)].door = true;
				printf("The south door is now open!\n\n");
				if (openmethod) lastcloseddoor = 'n';
			}
			else
				printf("What are you trying?\n\n");
			break;
		case 'e':
			if (p->room[pos - 1].e != 0){
				p->exit[FindExit(p->room[pos - 1].e)].door = true;
				printf("The east door is now open!\n\n");
				if (openmethod) lastcloseddoor = 'w';
			}
			else
				printf("What are you trying?\n\n");
			break;
		case 'w':
			if (p->room[pos - 1].w != 0){
				p->exit[FindExit(p->room[pos - 1].w)].door = true;
				printf("The west door is now open!\n\n");
				if (openmethod) lastcloseddoor = 'e';
			}
			else
				printf("What are you trying?\n\n");
		break;
		}
	}
	else{
		printf("You don't still at same room and door that you tried last time...\n\n");
		
	}
	p->Command();
}

void Players::CloseDoor(char otherdir){
	if (p->exit[lastnumdoor].o == pos || p->exit[lastnumdoor].d == pos){
		if (otherdir)
			lastcloseddoor = otherdir;
		
		if (movclose[0] == false) lastcloseddoor = 's';
		if (movclose[1] == false) lastcloseddoor = 'n';
		if (movclose[2] == false) lastcloseddoor = 'w';
		if (movclose[3] == false) lastcloseddoor = 'e';
		
		if (movclose != false)
		switch (lastcloseddoor)
		{
		case 'n':
			if (p->room[pos - 1].n != 0){
				p->exit[FindExit(p->room[pos - 1].n)].door = false;
				printf("The north door is now close!\n\n");
			}
			else
				printf("What are you trying?\n\n");
			break;
		case 's':
			if (p->room[pos - 1].n != 0){
				p->exit[FindExit(p->room[pos - 1].s)].door = false;
				printf("The south door is now close!\n\n");
			}
			else
				printf("What are you trying?\n\n");
			break;
		case 'e':
			if (p->room[pos - 1].n != 0){
				p->exit[FindExit(p->room[pos - 1].e)].door = false;
				printf("The east door is now close!\n\n");
			}
			else
				printf("What are you trying?\n\n");
			break;
		case 'w':
			if (p->room[pos - 1].n != 0){
				p->exit[FindExit(p->room[pos - 1].w)].door = false;
				printf("The west door is now close!\n\n");
			}
			else
				printf("What are you trying?\n\n");
			break;
		}
	}
	else{
		printf("You don't still at same room and door that you tried last time...\n\n");			
	}
	p->Command();
}

int Players::FindExit(int num_room){
	for (int i = 0; i < NUM_CONNECTIONS; ++i){
		if ((pos == p->exit[i].o || pos == p->exit[i].d) && (num_room == p->exit[i].o || num_room == p->exit[i].d))
			return i;
		else 
			return -1;
	}
}