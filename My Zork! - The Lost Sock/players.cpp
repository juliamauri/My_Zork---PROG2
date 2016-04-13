#include <stdio.h>
#include <stdlib.h>

#include "world.h"
#include "exits.h"
#include "players.h"
#include "rooms.h"
/*
void Players::Look(char dir)
{
	if (dir){
		short num_ext = FindExit(dir);

		if (num_ext != -1)
			p->exit[num_ext].destiny->DescExit();
		else
			printf("Door doesn't exist.\n\n");
	}
	else {
		system("cls");
		pos->Desc();
		for (short i = 0; i < NUM_CONNECTIONS; ++i){
			if (p->exit[i].origin == pos){
				if (p->exit[i].dir_dest == 'n') printf("There are way at north!\n\n");
				if (pos == p->exit[4].origin && p->exit[4].dir_dest == 's') printf("There are portal at north!\n\n");
				if (p->exit[i].dir_dest == 's') printf("There are way at south!\n\n");
				if (pos == p->exit[3].origin && p->exit[3].dir_dest == 'n') printf("There are portal at south!\n\n");
				if (p->exit[i].dir_dest == 'e') printf("There are way at east!\n\n");
				if (p->exit[i].dir_dest == 'w') printf("There are way at west!\n\n");
			}
		}
	}
	p->Command();
}

void Players::Movement(char dir)
{

	short num_ext = FindExit(dir);
	Rooms* temp = nullptr;

	if (num_ext != -1){
		if (p->exit[num_ext].door){
			temp = p->exit[num_ext].origin;
			p->exit[num_ext].origin = p->exit[num_ext].destiny;
			p->exit[num_ext].destiny = temp;
			pos = p->exit[num_ext].origin;

			if (p->exit[num_ext].dir_dest == 'n') p->exit[num_ext].dir_dest = 's';
			else if (p->exit[num_ext].dir_dest == 's') p->exit[num_ext].dir_dest = 'n';
			else if (p->exit[num_ext].dir_dest == 'e') p->exit[num_ext].dir_dest = 'w';
			else if (p->exit[num_ext].dir_dest == 'w') p->exit[num_ext].dir_dest = 'e';

			movclose = true;

			printf("You across the door!\n");
		}
		else
		{
			printf("The door is closed..\n\n");
			lasttrieddoor = p->exit[num_ext].dir_dest;
			movclose = false;
			p->Command();
		}
	}
	else
	{
		printf("Door doesn't exist.\n\n");
		p->Command();
	}
}

void Players::ChangeWorld()
{
	if (pos == p->exit[3].origin && p->exit[3].dir_dest == 'n'){
		pos = p->exit[4].origin;
		printf("You acroos the portal!\n\n");
	}
	else if (pos == p->exit[4].origin && p->exit[4].dir_dest == 's'){
		pos = p->exit[3].origin;
		printf("You acroos the portal!\n\n");
	}
	else{
		printf("What!?!?\n\n"); 
		p->Command();
	}
}

// Open/Close door functions, with some if and values, that changed while player moving, etc. It works for best using the doors.
void Players::OpenDoor(char dir)
{

	if (dir)
		lasttrieddoor = dir;

	if (lasttrieddoor)
	{
		short num_ext = FindExit(lasttrieddoor);

		if (num_ext != -1)
		{
				p->exit[num_ext].door = true;
				PrintOCDoor(lasttrieddoor, true);

				if (lasttrieddoor == 'n') lasttrieddoor = 's';
				else if (lasttrieddoor == 's') lasttrieddoor = 'n';
				else if (lasttrieddoor == 'e') lasttrieddoor = 'w';
				else if (lasttrieddoor == 'w') lasttrieddoor = 'e';
		}
		else
			printf("You aren't opening any door...\n\n");
	}
	else
		printf("You didn't try open any door...\n\n");

	p->Command();
	
}

void Players::CloseDoor(char dir)
{

	if (movclose == false && lasttrieddoor == 's') lasttrieddoor = 'n';
	else if (movclose == false && lasttrieddoor == 'n') lasttrieddoor = 's';
	else if (movclose == false && lasttrieddoor == 'w') lasttrieddoor = 'e';
	else if (movclose == false && lasttrieddoor == 'e') lasttrieddoor = 'w';

	if (dir)
		lasttrieddoor = dir;

	if (lasttrieddoor)
	{
		short num_ext = FindExit(lasttrieddoor);

		if (num_ext != -1)
		{
				p->exit[num_ext].door = false;
				PrintOCDoor(lasttrieddoor, false);
				movclose = false;
		}
		else
			printf("You aren't closing any door...\n\n");
	}
	else
		printf("You didn't try close any door...\n\n");
	
	p->Command();

}

//Find exit of conection with doors
short Players::FindExit(char dir)const
{
	for (short i = 0; i < NUM_CONNECTIONS; ++i){
		if (p->exit[i].origin == pos && p->exit[i].dir_dest == dir)
			return i;
	}
	return -1;
}

void Players::PrintOCDoor(short dir, bool OpenClose)const
{
	switch (dir)
	{
	case 'n':
		if (OpenClose)
			printf("The north door is now open!\n\n");
		else
			printf("The north door is now close!\n\n");
		break;
	case 's':
		if (OpenClose)
			printf("The south door is now open!\n\n");
		else
			printf("The south door is now close!\n\n");
		break;
	case 'e':
		if (OpenClose)
			printf("The east door is now open!\n\n");
		else
			printf("The east door is now close!\n\n");
		break;
	case 'w':
		if (OpenClose)
			printf("The west door is now open!\n\n");
		else
			printf("The west door is now close!\n\n");
		break;
	}
}
*/