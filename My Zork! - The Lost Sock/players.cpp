#include <stdio.h>
#include <stdlib.h>

#include "world.h"
#include "exits.h"
#include "players.h"
#include "rooms.h"
#include "My_String.h"


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

void Players::PDItem(char command,const char* i)
{
	My_String item(i);
	pos->numberitems = pos->item.size();
	p->player->itemcarry = p->player->item.size();

	switch (command)
	{
	case 'p':
		for (unsigned int i = 0; i < pos->numberitems; i++)
		{
			if (item == pos->item[i]->name.c_str())
			{
				if (p->player->itemcarry < p->player->max_itemcarry)
				{
					p->player->item.push_back(pos->item[i]);
					pos->item.resize(pos->item[i]);
					printf("The item %s is in your inventory!\n\n", item.c_str());
					p->Command();
				}
				else
				{
					printf("You are full of item capacity...\n\n");
					p->Command();
				}
			}
		}
		printf("This item not exist in these room...\n\n");
		p->Command();
		break;
	case 'd':
		for (unsigned int i = 0; i < p->player->itemcarry; i++)
		{
			if (item == p->player->item[i]->name.c_str())
			{
				pos->item.push_back(p->player->item[i]);
				p->player->item.resize(p->player->item[i]);
				printf("You drop the item %s at room of your inventory!\n\n", item.c_str());
				p->Command();
			}
		}
		printf("I am not carring this item...\n\n");
		p->Command();
		break;
	}
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

void Players::EUItem(char command,const char* i){
	My_String item(i);
	p->player->itemcarry = p->player->item.size();

	switch (command)
	{
	case 'e':
		if (itemequip == nullptr)
		{
			for (unsigned int i = 0; i < p->player->itemcarry; i++)
			{
				if (item == p->player->item[i]->name.c_str())
				{
					itemequip = p->player->item[i];
					p->player->item.resize(p->player->item[i]);
					printf("You get the item %s equiped!\n\n", item.c_str());
					p->Command();
				}
			}
		}
		else
		{
			printf("You have an item equipped...\n\n");
			p->Command();
		}
		printf("I am not carring this item...\n\n");
		p->Command();
		break;
	case 'u':
		if (itemequip == nullptr)
		{
			printf("You haven't an item equipped...\n\n");
			p->Command();
		}
		else
		{
			if (p->player->itemcarry < p->player->max_itemcarry)
			{
				p->player->item.push_back(itemequip);
				itemequip = nullptr;
				printf("The item %s is in your inventory and unequip!\n\n", item.c_str());
				p->Command();
			}
			else
			{
				printf("You are full of item capacity...\n\n");
				p->Command();
			}
		}
		break;
	}
}

void Players::PGItem(char command, const char* i1, const char* i2)
{
	My_String item1(i2);
	My_String item2(i1);
	bool flag_item1 = true;
	bool flag_item2 = true;
	p->player->itemcarry = p->player->item.size();

	switch (command)
	{
	case 'p':
		for (unsigned int i = 0; i < p->player->itemcarry; i++)
		{
			if (item1 == p->player->item[i]->name.c_str())
			{
				if (p->player->item[i]->objectsarea == true)
				{
					p->player->item[i]->itemcarry = p->player->item[i]->item.size();
					if (p->player->item[i]->itemcarry < p->player->item[i]->max_itemcarry)
					{
						for (unsigned int j = 0; j < p->player->itemcarry; j++)
						{
							if (item2 == p->player->item[j]->name.c_str())
							{
								p->player->item[i]->item.push_back(p->player->item[j]);
								p->player->item.resize(p->player->item[j]);
								printf("You put the item %s at %s!\n\n", item2.c_str(), item1.c_str());
								p->Command();
							}
							else
							{
								flag_item1 = true;
								flag_item2 = false;
							}
						}
					}
					else
					{
						printf("This item is full of capacity...\n\n");
						p->Command();
					}
				}
				else
				{
					printf("This item can't carry other items...\n\n");
					p->Command();
				}
			}
			else
				flag_item1 = false;
		}
		if (flag_item1 == false)
			printf("I am not carring the item %s...\n\n", item1.c_str());
		else if (flag_item2 == false)
			printf("I am not carring the item %s...\n\n", item2.c_str());
		p->Command();
		break;
	case 'g':
		if (itemcarry < max_itemcarry)
		{
			for (unsigned int i = 0; i < p->player->itemcarry; i++)
			{
				if (item1 == p->player->item[i]->name.c_str())
				{
					if (p->player->item[i]->objectsarea == true)
					{
						p->player->item[i]->itemcarry = p->player->item[i]->item.size();
						for (unsigned int j = 0; j < p->player->item[i]->itemcarry; j++)
						{
							if (item2 == p->player->item[i]->item[j]->name.c_str())
							{
								p->player->item.push_back(p->player->item[i]->item[j]);
								p->player->item[i]->item.resize(p->player->item[i]->item[j]);
								printf("You get the item %s from %s!\n\n", item2.c_str(), item1.c_str());
								p->Command();
							}
							else
							{
								flag_item1 = true;
								flag_item2 = false;
							}
						}
					}
					else
					{
						printf("This item can't carry other items...\n\n");
						p->Command();
					}
				}
				else
					flag_item1 = false;
			}
		}
		else
		{
			printf("You are full of capacity in your inventory...\n\n");
			p->Command();
		}
		if (flag_item1 == false)
			printf("I am not carring the item %s...\n\n", item1.c_str());
		else if (flag_item2 == false)
			printf("The item %s isn't carring the item %s...\n\n",item1.c_str(), item2.c_str());
		p->Command();
		break;
	}
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
