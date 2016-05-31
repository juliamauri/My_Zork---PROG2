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
		if (localition->ObjectsinRoom != false)
		{
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
		else
			printf("Any objects at room..\n\n");
	}
	Wd->Command();
}

void Players::Movement(char dir)
{

	bool door_exits = FindExit(dir);
	Rooms* temp = nullptr;

	if (door_exits != false){
		if (((Exits*)exit_node->data)->door)
		{

			temp = ((Exits*)exit_node->data)->origin;
			((Exits*)exit_node->data)->origin = ((Exits*)exit_node->data)->destiny;
			((Exits*)exit_node->data)->destiny = temp;
			localition = ((Exits*)exit_node->data)->origin;

			if (((Exits*)exit_node->data)->dir_dest == 'n') ((Exits*)exit_node->data)->dir_dest = 's';
			else if (((Exits*)exit_node->data)->dir_dest == 's') ((Exits*)exit_node->data)->dir_dest = 'n';
			else if (((Exits*)exit_node->data)->dir_dest == 'e') ((Exits*)exit_node->data)->dir_dest = 'w';
			else if (((Exits*)exit_node->data)->dir_dest == 'w') ((Exits*)exit_node->data)->dir_dest = 'e';

			movclose = true;

			printf("You across the door!\n");
		}
		else
		{
			printf("The door is closed..\n\n");
			lasttrieddoor = ((Exits*)exit_node->data)->dir_dest;
			movclose = false;
			Wd->Command();
		}
	}
	else
	{
		printf("Door doesn't exist.\n\n");
		Wd->Command();
	}
	
	temp = nullptr;
	
}

void Players::ChangeWorld()
{
	if (localition == ((Exits*)Wd->entities[14])->origin && ((Exits*)Wd->entities[14])->dir_dest == 'n'){
		localition = ((Exits*)Wd->entities[15])->origin;
		printf("You acroos the portal!\n\n");
	}
	else if (localition == ((Exits*)Wd->entities[15])->origin && ((Exits*)Wd->entities[15])->dir_dest == 's'){
		localition = ((Exits*)Wd->entities[14])->origin;
		printf("You acroos the portal!\n\n");
	}
	else{
		printf("What!?!?\n\n"); 
		Wd->Command();
	}
}

// Open/Close door functions, with some if and values, that changed while player moving, etc. It works for best using the doors.
void Players::OpenDoor(char dir)
{
	if (dir)
		lasttrieddoor = dir;

	if (lasttrieddoor)
	{
		bool door_exits = FindExit(dir);

		if (door_exits != false)
		{
			((Exits*)exit_node->data)->door = true;
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

	Wd->Command();
	
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
		bool door_exits = FindExit(dir);

		if (door_exits != false)
		{
			((Exits*)exit_node->data)->door = false;
			PrintOCDoor(lasttrieddoor, false);
			movclose = false;
		}
		else
			printf("You aren't closing any door...\n\n");
	}
	else
		printf("You didn't try close any door...\n\n");
	
	Wd->Command();

}

void Players::PDItem(char command,const char* i)
{
	My_String item1(i);
	bool flag_item = true;
	item_node = localition->contains.end();
	itemcarry = contains.size();
	
	switch (command)
	{
	case 'p':
		if (localition->ObjectsinRoom != false)
		{
			while (item_node->data != nullptr)
			{
				if (item1 == ((Items*)item_node->data)->name.c_str())
				{
					if (itemcarry < max_itemcarry)
					{
						flag_item = true;
						contains.pushback(item_node->data);
						localition->contains.erase(item_node);
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
				if (item_node->previous != nullptr)
					item_node = item_node->previous;
				else
					break;
			}
			if (flag_item == false)
			{
				printf("This item not exist in these room...\n\n");
				break;
			}
		}
		else
			printf("Any objects at room..\n\n");
		break;
	case 'd':
		item_node = contains.end();

		while (item_node->data != nullptr)
		{
			if (item1 == ((Items*)item_node->data)->name.c_str())
			{
				flag_item = true;
				localition->contains.pushback(item_node->data);
				contains.erase(item_node);
				printf("You drop the item %s at room of your inventory!\n\n", item1.c_str());
				break;
			}
			else
				flag_item = false;
			if (item_node->previous != nullptr)
				item_node = item_node->previous;
			else
				break;
		}
		if (flag_item == false)
			printf("I am not carring this item...\n\n");
		break;
	}
	Wd->Command();
}
void Players::Inventory()
{
	uint i = 0;
	uint j = 0;

	itemcarry = contains.size();
	item_node = contains.end();

	if (contains.empty() != true)
	{
		printf("\n You are carring: \n");
		while (item_node->data != nullptr)
		{
			printf("%i-", i++ + 1);
			((Items*)item_node->data)->Desc();
			if (((Items*)item_node->data)->objectsarea == true){
				((Items*)item_node->data)->itemcarry = ((Items*)item_node->data)->contains.size();
				Node<Entity*>* carryitem_node = ((Items*)item_node->data)->contains.end();
				if (((Items*)item_node->data)->contains.empty() != true)
				{
					while (carryitem_node->data != nullptr)
					{
						printf("%i.%i-", i + 1, j++ + 1);
						((Items*)carryitem_node->data)->Desc();
						printf("\n-------\n");
						if (carryitem_node->previous != nullptr)
							carryitem_node = carryitem_node->previous;
						else
							break;
					}
				}
				printf("Total space of object: %i/%i\n\n", ((Items*)item_node->data)->itemcarry, ((Items*)item_node->data)->max_itemcarry);
			}
			printf("\n-----------------\n");
			if (item_node->previous != nullptr)
				item_node = item_node->previous;
			else
				break;
		}
		printf("Total space of you: %i/%i\n\n", itemcarry, max_itemcarry);
	}
	else
		printf("You aren't carring any object..");

	Wd->Command();
}
/*
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
*/
/*
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

	uint count_exits = 0;

	exit_node = exit_list.end();
	while (exit_node->data != nullptr)
	{
		if (((Exits*)exit_node->data)->origin == localition && ((Exits*)exit_node->data)->dir_dest == dir)
			ret = true;
			
		if (ret == false && count_exits < NUM_EXITS - 1)//NUM_EXITS -1(total of previous)
		{
			exit_node = exit_node->previous;
			count_exits++;
		}
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