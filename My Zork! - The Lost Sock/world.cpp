#include <stdio.h>
#include <stdlib.h>

#include "world.h"

World::World()
{
}

World::~World()
{
}

void World::CreateWorld() 
{
	entity.push_back(new Entity("Entity 1", "Rooms"));
	entity[0]->room.push_back(new Rooms("Bedroom", "Yeah... It's my bedroom...", "It smells a jerk..."));
	entity[0]->room.push_back(new Rooms("Living room", "Normal room that I use every day to contact the other world.", "Smells tasty... WTF?!? o_o"));
	entity[0]->room.push_back(new Rooms("Entrance hall", "Yeah... It's my bedroom...", "It smells a jerk..."));
	entity[0]->room.push_back(new Rooms("Kitchen", "Too much sugar everywhere ._.", "Hmm... I'm hungry :3"));
	entity[0]->room.push_back(new Rooms("Storeroom", "Amount of rope everywhere...", "It smells trash"));
	entity[0]->room.push_back(new Rooms("Machines room", "Too much metal", "Nosy!! OMG! PLS! STOP!"));
	entity[0]->room.push_back(new Rooms("Drying room", "Wind everywhere", "I feel cold"));
	entity[0]->room.push_back(new Rooms("Research room", "Papers everiwhere...", "I can see lights..."));
	entity[0]->room.push_back(new Rooms("Technology room", "Unknown technology... Waow *^*", "Too much security..."));
	entity[0]->room.push_back(new Rooms("Boss room", "Wires across the room", "I activated my senses arachnids..."));
	entity[0]->room.push_back(new Rooms("Store socks", "Socks everywhere!", "I supose that is the last room, pls!!"));


	entity.push_back(new Entity("Entity 2", "Exits"));
	entity[1]->exit.push_back(new Exits("Exit 1", "Bedroom and Living room", 'e', entity[0]->room[0], entity[0]->room[1]));
	entity[1]->exit.push_back(new Exits("Exit 2", "Living room and Entrance hall", 'n', entity[0]->room[1], entity[0]->room[2]));
	entity[1]->exit.push_back(new Exits("Exit 3", "Living room and Kitchen", 'e', entity[0]->room[1], entity[0]->room[3]));
	entity[1]->exit.push_back(new Exits("Exit 4", "Kitchen and Storeroom", 's', entity[0]->room[3], entity[0]->room[4]));
	entity[1]->exit.push_back(new Exits("Exit 5", "Machines room and Drying room", 's', entity[0]->room[5], entity[0]->room[6]));
	entity[1]->exit.push_back(new Exits("Exit 6", "Drying room and Research room", 'e', entity[0]->room[6], entity[0]->room[7]));
	entity[1]->exit.push_back(new Exits("Exit 7", "Research room and Technology room", 's', entity[0]->room[7], entity[0]->room[8]));
	entity[1]->exit.push_back(new Exits("Exit 8", "Research room and Boss room", 'e', entity[0]->room[7], entity[0]->room[9]));
	entity[1]->exit.push_back(new Exits("Exit 9", "Boss room and Store socks", 'n', entity[0]->room[9], entity[0]->room[10]));


	entity.push_back(new Entity("Entity 3", "Players"));
	entity[2]->player.push_back(player = new Players("Juli", "The Best", entity[0]->room[0]));
	

	entity.push_back(new Entity("Entity 4", "Items"));
	entity[3]->item.push_back(new Items("Joint", "You tavell a lot.."));
	entity[0]->room[1]->itemlist.push_back(entity[3]->item[0]);
	entity[3]->item.push_back(new Items("Candies", "Hmmm, delicios :3"));
	entity[2]->player[0]->itemlist.push_back(entity[3]->item[1]);
	entity[3]->item.push_back(new Items("Chocolate", "Hmmm, delicios :3"));
	entity[0]->room[3]->itemlist.push_back(entity[3]->item[2]);
	entity[3]->item.push_back(new Items("Bottle of water", "Very important for live.."));
	entity[0]->room[3]->itemlist.push_back(entity[3]->item[3]);
	entity[3]->item.push_back(new Items("Pills", "I'm sick ;("));
	entity[0]->room[0]->itemlist.push_back(entity[3]->item[4]);
	entity[3]->item.push_back(new Items("Perfume", "I'm glourious :D"));
	entity[0]->room[0]->itemlist.push_back(entity[3]->item[5]);

	entity[3]->item.push_back(new Items("Scissors", "Cut everithing"));
	entity[0]->room[0]->itemlist.push_back(entity[3]->item[6]);
	entity[3]->item.push_back(new Items("Lighter", "Burn everithing"));
	entity[0]->room[1]->itemlist.push_back(entity[3]->item[7]);
	entity[3]->item.push_back(new Items("Umbrellas", "It's raining men.."));
	entity[0]->room[2]->itemlist.push_back(entity[3]->item[8]);
	entity[3]->item.push_back(new Items("Knife", "I cut my finger :D"));
	entity[0]->room[3]->itemlist.push_back(entity[3]->item[9]);
	entity[3]->item.push_back(new Items("Gun", "Shot the air"));
	entity[0]->room[0]->itemlist.push_back(entity[3]->item[10]);

	entity[3]->item.push_back(new Items("Screwdriver", "Fix some bugs"));
	entity[0]->room[5]->itemlist.push_back(entity[3]->item[11]);
	entity[3]->item.push_back(new Items("Power supply", "More energy, please"));
	entity[0]->room[8]->itemlist.push_back(entity[3]->item[12]);
}

void World::Command() 
{
	Vector<My_String*> commands;
	My_String* command = nullptr;
	My_String* command2 = nullptr;
	My_String* command3 = nullptr;
	int size;

	commands.push_back(new My_String);

	printf("Write the command: ");
	commands[0]->write();

	commands[0]->tokens(" ", commands);
	size = commands.size();

	if (size == 3)
	{
		command = commands[0];
		command2 = commands[1];
		command3 = commands[2];
	}
	else if (size == 2)
	{
		command = commands[0];
		command2 = commands[1];
	}
	else if (size == 1)
	{
		command = commands[0];
	}
	else
	{
		printf("Introduce a good command...\n\n");
		Command();
	}

	if (*command == "look" && command3 == nullptr)
	{
		if (command2 == nullptr)
			Command();
			//player->Look(NULL);
		else if (*command2 == "north" || *command2 == "south" || *command2 == "east" || *command2 == "west")
			Command();
			//player->Look(*command2.c_str());
		else if (*command2 == "n" || *command2 == "s" || *command2 == "e" || *command2 == "w")
			Command();
			//player->Look(*command2.c_str());
		else
		{
			printf("Introduce a good command...\n\n");
			Command();
		}
	}
	else if (*command == "go")
	{
		if (command2 == nullptr)
		{
			printf("Introduce a good command...\n\n");
			Command();
		}
		else
		{
			if (*command2 == "north" || *command2 == "south" || *command2 == "east" || *command2 == "west")
				Command();
			//player->Movement(*command2.c_str());
			else if (*command2 == "n" || *command2 == "s" || *command2 == "e" || *command2 == "w")
				Command();
			//player->Movement(*command2.c_str());
			else
			{
				printf("Introduce a good command...\n\n");
				Command();
			}
		}
	}
	else if (*command == "open")
	{
		if (command2 == nullptr)
		{
			printf("Introduce a good command...\n\n");
			Command();
		}
		else
		{
			if (command3 == nullptr)
			{
				if (*command2 == "door" || *command2 == "gate")
					Command();
				//player->OpenDoor(NULL);
				else
				{
					printf("Introduce a good command...\n\n");
					Command();
				}
			}
			else
			{
				if ((*command2 == "north" || *command2 == "south" || *command2 == "east" || *command2 == "west") && (*command3 == "door" || *command3 == "gate"))
					Command();
				//player->OpenDoor(*command2.c_str());
				else if ((*command2 == "n" || *command2 == "s" || *command2 == "e" || *command2 == "w") && (*command3 == "door" || *command3 == "gate"))
					Command();
				//player->OpenDoor(*command2.c_str());
				else
				{
					printf("Introduce a good command...\n\n");
					Command();
				}
			}
		}
	}
	else if (*command == "close")
	{
		if (command2 == nullptr)
		{
			printf("Introduce a good command...\n\n");
			Command();
		}
		else
		{
			if (command3 == nullptr)
			{
				if (*command2 == "door" || *command2 == "gate")
					Command();
				//player->CloseDoor(NULL);
				else
				{
					printf("Introduce a good command...\n\n");
					Command();
				}
			}
			else
			{
				if ((*command2 == "north" || *command2 == "south" || *command2 == "east" || *command2 == "west") && (*command3 == "door" || *command3 == "gate"))
					Command();
				//player->CloseDoor(*command2.c_str());
				else if ((*command2 == "n" || *command2 == "s" || *command2 == "e" || *command2 == "w") && (*command3 == "door" || *command3 == "gate"))
					Command();
				//player->CloseDoor(*command2.c_str());
				else
				{
					printf("Introduce a good command...\n\n");
					Command();
				}
			}
		}
	}
	else if (*command == "quit" && command2 == nullptr)
	{
		Command();
		//loop = false;
	}
	else if (*command == "help" && command2 == nullptr)
	{
		Command();
		//Help();
	}
	else if (*command == "enter" && command3 == nullptr)
	{
		if (command2 == nullptr)
		{
			printf("Introduce a good command...\n\n");
			Command();
		}
		else
		{
			if (*command2 == "portal")
				Command();
			//player->ChangeWorld();
			else
			{
				printf("Introduce a good command...\n\n");
				Command();
			}
		}
	}
	else
	{
		printf("Introduce a good command...\n\n");
		Command();
	}
}


void World::Help() const{
	system("cls");

	printf("Commands enabled:\n");
	printf("- look: for printing description room and possible exits.\n");
	printf("- look + direction: for printing description of possible exits content.\n");
	printf("- go + direction: for moving at rooms.");
	printf("- enter + portal: for passing the portal.");
	printf("- open/close + door/gate: for opening or closing doors/gates when you tryied to pass.\n");
	printf("- open/close + direction + door/gate: for opening or closing doors/gates directly with direction.\n");
	printf("- quit: to exit the game.\n");
	printf("- help: for ptinting the help commands.\n");
	printf("*Direction: north(or n), south(or s), east(or e), west(or w).\n\n");
}

void World::Init(){
	CreateWorld();

	Help();

	printf("Lore: You are a simple human who praise Lord Gaben");
	printf("\n\n");

	printf("Pulse any key to continue...");
	getchar();
	system("cls");
}

void World::Loop(){
	
	do{
		player->pos->Desc();

		Command();

		printf("Pulse any key to continue...");
		getchar();

		system("cls");

	} while (loop != false);
}