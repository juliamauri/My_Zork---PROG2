#include <stdio.h>
#include <stdlib.h>

#include "World.h"
#include "Exits.h"
#include "Players.h"
#include "Rooms.h"
#include "My_String.h"



void Players::Look(char dir)
{
	if (dir){


		bool door_exits = FindExit(dir);
		
		if (door_exits == true)
			((Exits*)exit_node->data)->destiny->DescExit();
		else
			printf("Door doesn't exist.\n\n");
	}
	else {
		system("cls");
		localition->Desc();
		exit_node = exit_list.end();
		while (exit_node->data != nullptr)
		{
			if (((Exits*)exit_node->data)->origin == localition)
			{
				if (((Exits*)exit_node->data)->dir_dest == 'n') printf("There are way at north!\n\n");
				if (localition == ((Exits*)Wd->entities[15])->origin && ((Exits*)Wd->entities[15])->dir_dest == 's') printf("There are portal at north!\n\n");
				if (((Exits*)exit_node->data)->dir_dest == 's') printf("There are way at south!\n\n");
				if (localition == ((Exits*)Wd->entities[14])->origin && ((Exits*)Wd->entities[14])->dir_dest == 'n') printf("There are portal at south!\n\n");
				if (((Exits*)exit_node->data)->dir_dest == 'e') printf("There are way at east!\n\n");
				if (((Exits*)exit_node->data)->dir_dest == 'w') printf("There are way at west!\n\n");
			}
			if (exit_node->previous != nullptr)
				exit_node = exit_node->previous;
			else
				break;
		}
		printf("Items:\n\n");
		uint i = 0;
		item_node = localition->contains.end();
		while (item_node->data != nullptr)
		{
			printf("%i-", i++ + 1);
			((Items*)item_node->data)->Desc();
			printf("-----------------\n\n");

			if (item_node->previous != nullptr)
				item_node = item_node->previous;
			else
				break;
		}
	}
	Wd->Command();
}
/*
void Players::Movement(char dir)
{

	short num_ext = FindExit(dir);
	Rooms* temp = nullptr;

	if (num_ext != -1){
		if (p->entity[1]->exit[num_ext]->door){
			temp = p->entity[1]->exit[num_ext]->origin;
			p->entity[1]->exit[num_ext]->origin = p->entity[1]->exit[num_ext]->destiny;
			p->entity[1]->exit[num_ext]->destiny = temp;
			pos = p->entity[1]->exit[num_ext]->origin;

			if (p->entity[1]->exit[num_ext]->dir_dest == 'n') p->entity[1]->exit[num_ext]->dir_dest = 's';
			else if (p->entity[1]->exit[num_ext]->dir_dest == 's') p->entity[1]->exit[num_ext]->dir_dest = 'n';
			else if (p->entity[1]->exit[num_ext]->dir_dest == 'e') p->entity[1]->exit[num_ext]->dir_dest = 'w';
			else if (p->entity[1]->exit[num_ext]->dir_dest == 'w') p->entity[1]->exit[num_ext]->dir_dest = 'e';

			movclose = true;

			printf("You across the door!\n");
		}
		else
		{
			printf("The door is closed..\n\n");
			lasttrieddoor = p->entity[1]->exit[num_ext]->dir_dest;
			movclose = false;
			p->Command();
		}
	}
	else
	{
		printf("Door doesn't exist.\n\n");
		p->Command();
	}
	
	temp = nullptr;
	
}

void Players::ChangeWorld()
{
	if (pos == p->entity[1]->exit[3]->origin && p->entity[1]->exit[3]->dir_dest == 'n'){
		pos = p->entity[1]->exit[4]->origin;
		printf("You acroos the portal!\n\n");
	}
	else if (pos == p->entity[1]->exit[4]->origin && p->entity[1]->exit[4]->dir_dest == 's'){
		pos = p->entity[1]->exit[3]->origin;
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
				p->entity[1]->exit[num_ext]->door = true;
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
				p->entity[1]->exit[num_ext]->door = false;
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
	My_String item1(i);
	bool flag_item = true;
	pos->numberitems = pos->item.size();
	itemcarry = item.size();
	

	switch (command)
	{
	case 'p':
		for (unsigned int i = 0; i < pos->numberitems; i++)
		{
			if (item1 == pos->item[i]->name.c_str())
			{
				if (itemcarry < max_itemcarry)
				{
					flag_item = true;
					item.push_back(pos->item[i]);
					pos->item.resize(pos->item[i]);
					printf("The item %s is in your inventory!\n\n", item1.c_str());
					break;
				}
				else
				{
					printf("You are full of item capacity...\n\n");
					break;
				}
			}
			else
				flag_item = false;
		}
		if (flag_item == false)
			printf("This item not exist in these room...\n\n");
		break;
	case 'd':
		for (unsigned int i = 0; i < itemcarry; i++)
		{
			if (item1 == item[i]->name.c_str())
			{
				flag_item = true;
				pos->item.push_back(item[i]);
				item.resize(item[i]);
				printf("You drop the item %s at room of your inventory!\n\n", item1.c_str());
				break;
			}
			else
				flag_item = false;
		}
		if (flag_item == false)
			printf("I am not carring this item...\n\n");
		break;
	}
	p->Command();
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
	My_String item1(i);
	bool flag_item = true;
	itemcarry = item.size();

	switch (command)
	{
	case 'e':
		if (itemequip == nullptr)
		{
			for (unsigned int i = 0; i < itemcarry; i++)
			{
				if (item1 == item[i]->name.c_str())
				{
					flag_item = true;
					itemequip = item[i];
					item.resize(item[i]);
					printf("You get the item %s equiped!\n\n", item1.c_str());
					break;
				}
				else
					flag_item = false;
			}
		}
		else
			printf("You have an item equipped...\n\n");

		if (flag_item == false)
			printf("I am not carring this item...\n\n");
		break;
	case 'u':
		if (itemequip == nullptr)
		{
			printf("You haven't an item equipped...\n\n");
		}
		else
		{
			if (itemcarry < max_itemcarry)
			{
				item.push_back(itemequip);
				itemequip = nullptr;
				printf("The item %s is in your inventory and unequip!\n\n", item1.c_str());
				break;
			}
			else
			{
				printf("You are full of item capacity...\n\n");
				break;
			}
		}
		break;
	}
	p->Command();
}

void Players::PGItem(char command, const char* i1, const char* i2)
{
	My_String item1(i2);
	My_String item2(i1);
	bool flag_item1 = true;
	bool flag_item2 = true;
	itemcarry = item.size();

	switch (command)
	{
	case 'p':
		for (unsigned int i = 0; i < itemcarry; i++)
		{
			if (item1 == item[i]->name.c_str())
			{
				flag_item1 = true;
				if (item[i]->objectsarea == true)
				{
					item[i]->itemcarry = item[i]->item.size();
					if (item[i]->itemcarry < item[i]->max_itemcarry)
					{
						for (unsigned int j = 0; j < itemcarry; j++)
						{
							if (item2 == item[j]->name.c_str())
							{
								flag_item2 = true;
								item[i]->item.push_back(item[j]);
								item.resize(item[j]);
								printf("You put the item %s at %s!\n\n", item2.c_str(), item1.c_str());
								break;
							}
							else
								flag_item2 = false;
						}
					}
					else
					{
						printf("This item is full of capacity...\n\n");
						break;
					}
				}
				else
				{
					printf("This item can't carry other items...\n\n");
					break;
				}
			}
			else
				flag_item1 = false;
			if (flag_item1 == true) break;
		}

		if (flag_item1 == false)
			printf("I am not carring the item %s...\n\n", item1.c_str());
		else if (flag_item2 == false)
			printf("I am not carring the item %s...\n\n", item2.c_str());
		break;
	case 'g':
		if (itemcarry < max_itemcarry)
		{
			for (unsigned int i = 0; i < itemcarry; i++)
			{
				if (item1 == item[i]->name.c_str())
				{
					flag_item1 = true;
					if (item[i]->objectsarea == true)
					{
						item[i]->itemcarry = item[i]->item.size();
						for (unsigned int j = 0; j < item[i]->itemcarry; j++)
						{
							if (item2 == item[i]->item[j]->name.c_str())
							{
								flag_item2 = true;
								item.push_back(item[i]->item[j]);
								item[i]->item.resize(item[i]->item[j]);
								printf("You get the item %s from %s!\n\n", item2.c_str(), item1.c_str());
								break;
							}
							else
								flag_item2 = false;
						}
					}
					else
					{
						printf("This item can't carry other items...\n\n");
						break;
					}
				}
				else
					flag_item1 = false;
			}
		}
		else
			printf("You are full of capacity in your inventory...\n\n");

		if (flag_item1 == false)
			printf("I am not carring the item %s...\n\n", item1.c_str());
		else if (flag_item2 == false)
			printf("The item %s isn't carring the item %s...\n\n",item1.c_str(), item2.c_str());
		break;
	}
	p->Command();
}

void Players::UpdateStats()
{
	itemcarry = item.size();

	for (unsigned int i = 0; i < itemcarry; i++)
	{
		if (item[i]->objectsarea == true)
		{
			attack += item[i]->attack;
			defense += item[i]->defense;
			hp += item[i]->hp;
		}
	}
	if (itemequip == nullptr){}
	else
	{
		if (itemequip->consumable == false)
		{
			attack += itemequip->attack;
			defense += itemequip->defense;
			hp += itemequip->hp;
		}
	}
}

void Players::PrintStats()
{
	UpdateStats();

	printf("\nYour Stats:\n");
	printf("Attack: %i\n", attack);
	printf("Defense: %i\n",defense);
	printf("HP: %i\n\n",hp);
	p->Command();
}
*/
//Find exit of conection with doors
bool Players::FindExit(char dir)
{
	bool ret = false;

	exit_node = exit_list.end();
	while (exit_node->data != nullptr)
	{
		if (((Exits*)exit_node->data)->origin == localition && ((Exits*)exit_node->data)->dir_dest == dir)
			ret = true;
			
		if (ret == false)
			exit_node = exit_node->previous;
		else
			break;
	}
	return ret;
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

void Players::SetExits()
{
	exit_list = Wd->FindAll(EXIT);

	exit_node = exit_list.end();
}