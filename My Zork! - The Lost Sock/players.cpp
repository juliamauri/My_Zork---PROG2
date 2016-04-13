#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "world.h"
#include "exits.h"
#include "players.h"
#include "rooms.h"
/*
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
*/
void Players::Movement(char dir)
{

	short num_ext = FindExit(dir);
	Rooms* temp = nullptr;

	if (dir == p->exit[num_ext].dir_dest){
		temp = p->exit[num_ext].origin;
		p->exit[num_ext].origin = p->exit[num_ext].destiny;
		p->exit[num_ext].destiny = temp;
		fpos = p->exit[num_ext].origin;

		if (p->exit[num_ext].dir_dest == 'n') p->exit[num_ext].dir_dest = 's';
		else if (p->exit[num_ext].dir_dest == 's') p->exit[num_ext].dir_dest = 'n';
		else if (p->exit[num_ext].dir_dest == 'e') p->exit[num_ext].dir_dest = 'w';
		else if (p->exit[num_ext].dir_dest == 'w') p->exit[num_ext].dir_dest = 'e';
	}

	/*
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
	*/
}

void Players::ChangeWorld(){
	if (fpos == p->exit[3].origin && p->exit[3].dir_dest == 'n'){
		fpos = p->exit[4].origin;
		printf("You acroos the portal!\n\n");
		//lastnumdoor = FindExit(pos);
	}
	else if (fpos == p->exit[4].origin && p->exit[4].dir_dest == 's'){
		fpos = p->exit[3].origin;
		printf("You acroos the portal!\n\n");
		//lastnumdoor = FindExit(pos);
	}
	else{
		printf("What!?!?\n\n"); 
		p->Command();
	}
}

// Open/Close door functions, with some if and values, that changed while player moving, etc. It works for best using the doors.
/*
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
*/
//Find exit of conection with doors
short Players::FindExit(char dir){
	for (short i = 0; i < NUM_CONNECTIONS; ++i){
		if (p->exit[i].origin == fpos && p->exit[i].dir_dest == dir)
			return i;
	}
}
/*
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
*/