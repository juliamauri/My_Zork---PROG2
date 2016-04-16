#include <stdio.h>
#include <stdlib.h>

#include "world.h"
#include "exits.h"
#include "players.h"
#include "rooms.h"


void Players::Look(char dir)
{
	if (dir){
		short num_ext = FindExit(dir);

		if (num_ext != -1)
			exit[num_ext]->destiny->DescExit();
		else
			printf("Door doesn't exist.\n\n");
	}
	else {
		system("cls");
		pos->Desc();
		for (unsigned int i = 0; i < ext_size; ++i){
			if (exit[i]->origin == pos)
			{
				if (exit[i]->dir_dest == 'n') printf("There are way at north!\n\n");
				if (pos == exit[4]->origin && exit[4]->dir_dest == 's') printf("There are portal at north!\n\n");
				if (exit[i]->dir_dest == 's') printf("There are way at south!\n\n");
				if (pos == exit[3]->origin && exit[3]->dir_dest == 'n') printf("There are portal at south!\n\n");
				if (exit[i]->dir_dest == 'e') printf("There are way at east!\n\n");
				if (exit[i]->dir_dest == 'w') printf("There are way at west!\n\n");
			}
		}
		pos->numberitems = pos->item.size();
		printf("Items:\n\n");
		for (unsigned int i = 0; i < pos->numberitems; i++){
			printf("%i-", i + 1);
			pos->item[i]->Desc();
			printf("-----------------\n\n");
		}
	}
	p->Command();
}

void Players::Movement(char dir)
{

	short num_ext = FindExit(dir);
	Rooms* temp = nullptr;

	if (num_ext != -1){
		if (exit[num_ext]->door){
			temp = exit[num_ext]->origin;
			exit[num_ext]->origin = exit[num_ext]->destiny;
			exit[num_ext]->destiny = temp;
			pos = exit[num_ext]->origin;

			if (exit[num_ext]->dir_dest == 'n') exit[num_ext]->dir_dest = 's';
			else if (exit[num_ext]->dir_dest == 's') exit[num_ext]->dir_dest = 'n';
			else if (exit[num_ext]->dir_dest == 'e') exit[num_ext]->dir_dest = 'w';
			else if (exit[num_ext]->dir_dest == 'w') exit[num_ext]->dir_dest = 'e';

			movclose = true;

			printf("You across the door!\n");
		}
		else
		{
			printf("The door is closed..\n\n");
			lasttrieddoor = exit[num_ext]->dir_dest;
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
	if (pos == exit[3]->origin && exit[3]->dir_dest == 'n'){
		pos = exit[4]->origin;
		printf("You acroos the portal!\n\n");
	}
	else if (pos == exit[4]->origin && exit[4]->dir_dest == 's'){
		pos = exit[3]->origin;
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
				exit[num_ext]->door = true;
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
				exit[num_ext]->door = false;
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

void Players::PDItem(const char* item)
{

}

void Players::Inventory()
{
	itemcarry = item.size();

	printf("\n You are carring: \n");
	for (unsigned int i = 0;i < itemcarry;i++)
	{
		printf("%i-", i+1);
		item[i]->Desc();
		if (item[i]->objectsarea == true){
			item[i]->itemcarry = item[i]->item.size();
			for (unsigned int j = 0; j < item[i]->itemcarry; j++)
			{
				printf("%i.%i-", i+1,j + 1);
				item[i]->item[j]->Desc();
				printf("\n-------\n");
			}
			printf("Total space of object: %i/%i\n\n", item[i]->itemcarry, item[i]->max_itemcarry);
		}
		printf("\n-----------------\n");
	}
	printf("Total space of you: %i/%i\n\n", itemcarry, max_itemcarry);
	p->Command();
}

void Players::EUItem(const char* item){

}

void Players::PGItem(const char* item1, const char* item2)
{

}
//Find exit of conection with doors
short Players::FindExit(char dir)const
{
	for (unsigned int i = 0; i < ext_size; ++i){
		
		if (exit[i]->origin == pos && exit[i]->dir_dest == dir)
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
