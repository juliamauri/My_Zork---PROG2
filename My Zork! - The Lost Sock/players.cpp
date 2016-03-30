#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "world.h"
#include "exits.h"
#include "players.h"

void Players::Look(char dir)const{
	//look directions
	if (strcmp(&dir, "") == 0){
		system("cls");
		p->room[pos - 1].Desc();

		if (p->room[pos - 1].n != 0) printf("There are way at north!\n\n");
		if (pos == 6) printf("There are portal at north!\n\n");
		if (p->room[pos - 1].s != 0) printf("There are way at south!\n\n");
		if (pos == 5) printf("There are portal at south!\n\n");
		if (p->room[pos - 1].e != 0) printf("There are way at east!\n\n");
		if (p->room[pos - 1].w != 0) printf("There are way at west!\n\n");
	}
	else {
		short num_dir = p->room[pos - 1].DirNum(dir);

		if (num_dir != 0)
			p->room[num_dir - 1].DescExit();
		else
			printf("Door doesn't exist.\n\n");
	}
	p->Command();
}

void Players::Movement(char dir)
{

	short num_dir = p->room[pos - 1].DirNum(dir);

	if (num_dir != 0)
	{
		if (p->exit[FindExit(num_dir)].door != false){
			pos = num_dir;
			movclose = true;
			printf("You across the door!\n");
		}
		else{
			printf("The door is closed..\n\n");
			lastcloseddoor = dir;
			movclose = false;
			p->Command();
		}
		lastnumdoor = FindExit(pos);
	}
	else
	{
			printf("Door doesn't exist.\n\n");
		p->Command();
	}
	printf("\n");
}

void Players::ChangeWorld(){
	if (pos == 5){
		pos = 6;
		printf("You acroos the portal!\n\n");
		lastnumdoor = FindExit(pos);
	}
	else if (pos == 6){
		pos = 5;
		printf("You acroos the portal!\n\n");
		lastnumdoor = FindExit(pos);
	}
	else{
		printf("What!?!?\n\n"); 
		p->Command();
	}
}

// Open/Close door functions, with some if and values, that changed while player moving, etc. It works for best using the doors.

void Players::OpenDoor(char otherdir){
	if (p->exit[lastnumdoor].origin == pos || p->exit[lastnumdoor].destiny == pos || lastnumdoor == pos){
		if (otherdir)
			lastcloseddoor = otherdir;
		
		short num_dir = p->room[pos - 1].DirNum(lastcloseddoor);

		if (num_dir != 0){
			p->exit[FindExit(num_dir)].door = true;
			PrintOCDoor(lastcloseddoor, true);

			if (lastcloseddoor == 'n') lastcloseddoor = 's';
			else if (lastcloseddoor == 's') lastcloseddoor = 'n';
			else if (lastcloseddoor == 'e') lastcloseddoor = 'w';
			else if (lastcloseddoor == 'w') lastcloseddoor = 'e';
		}
		else
			printf("What are you trying?\n\n");
	}
	else{
		printf("You don't still at same room and door that you tried last time...\n\n");
		
	}
	p->Command();
}

void Players::CloseDoor(char otherdir){
	if (p->exit[lastnumdoor].origin == pos || p->exit[lastnumdoor].destiny == pos){
		
		if (movclose == false && lastcloseddoor == 's') lastcloseddoor = 'n';
		else if (movclose == false && lastcloseddoor == 'n') lastcloseddoor = 's';
		else if (movclose == false && lastcloseddoor == 'w') lastcloseddoor = 'e';
		else if (movclose == false && lastcloseddoor == 'e') lastcloseddoor = 'w';
		
		if (otherdir)
			lastcloseddoor = otherdir;
		
		short num_dir = p->room[pos - 1].DirNum(lastcloseddoor);

		if (num_dir != 0){
			p->exit[FindExit(num_dir)].door = false;
			PrintOCDoor(lastcloseddoor, false);
			movclose = false;
		}
		else
			printf("What are you trying?\n\n");
	}
	else{
		printf("You don't still at same room and door that you tried last time...\n\n");			
	}
	p->Command();
}

//Find exit of conection with doors
short Players::FindExit(short num_room)const{
	for (short i = 0; i < NUM_CONNECTIONS; ++i){
		if ((pos == p->exit[i].origin || pos == p->exit[i].destiny) && (num_room == p->exit[i].origin || num_room == p->exit[i].destiny))
			return i;
	}
}

void Players::PrintOCDoor(short dir, bool OpenClose)const{
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