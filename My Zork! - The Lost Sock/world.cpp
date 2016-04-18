#include <stdio.h>
#include <stdlib.h>

#include "world.h"

World::World()
{
}

World::~World()
{

	unsigned int sizeentitites = entity.size();
	
	for (int clear = sizeentitites-1; clear >= 0; clear--)
	{
		entity[clear]->name.~My_String();
		entity[clear]->desc.~My_String();

		int size = entity[clear]->item.size();
		for (int i = size - 1; i >= 0; i--)
		{
			if (entity[clear]->item[i]->objectsarea == true)
			{
				int sizeoa = entity[clear]->item[i]->item.size();
				if (sizeoa == 0){}
				else
				{
					for (int j = sizeoa - 1; j >= 0; j--)
					{
						entity[clear]->item[i]->item[j]->name.~My_String();
						entity[clear]->item[i]->item[j]->desc.~My_String();
						entity[clear]->item[i]->item[j]->item.~Vector();
						entity[clear]->item[i]->item[j]->player.~Vector();
						entity[clear]->item[i]->item[j]->room.~Vector();
						entity[clear]->item[i]->item[j]->exit.~Vector();
					}
				}
			}
			entity[clear]->item[i]->name.~My_String();
			entity[clear]->item[i]->desc.~My_String();
			entity[clear]->item[i]->item.~Vector();
			entity[clear]->item[i]->player.~Vector();
			entity[clear]->item[i]->room.~Vector();
			entity[clear]->item[i]->exit.~Vector();
		}
		entity[clear]->item.~Vector();

		size = entity[clear]->player.size();
		for (int i = size - 1; i >= 0; i--)
		{
			entity[clear]->player[i]->p = nullptr;
			entity[clear]->player[i]->pos = nullptr;
			entity[clear]->player[i]->itemequip = nullptr;

			entity[clear]->player[i]->name.~My_String();
			entity[clear]->player[i]->desc.~My_String();
			entity[clear]->player[i]->item.~Vector();
			entity[clear]->player[i]->player.~Vector();
			entity[clear]->player[i]->room.~Vector();
			entity[clear]->player[i]->exit.~Vector();
		}
		entity[clear]->player.~Vector();

		size = entity[clear]->exit.size();
		for (int i = size - 1; i >= 0; i--)
		{
			entity[clear]->exit[i]->origin = nullptr;
			entity[clear]->exit[i]->destiny = nullptr;

			entity[clear]->exit[i]->name.~My_String();
			entity[clear]->exit[i]->desc.~My_String();
			entity[clear]->exit[i]->item.~Vector();
			entity[clear]->exit[i]->player.~Vector();
			entity[clear]->exit[i]->room.~Vector();
			entity[clear]->exit[i]->exit.~Vector();
		}
		entity[clear]->exit.~Vector();

		size = entity[clear]->room.size();
		for (int i = size - 1; i >= 0; i--)
		{
			entity[clear]->room[i]->name.~My_String();
			entity[clear]->room[i]->desc.~My_String();
			entity[clear]->room[i]->descexit.~My_String();
			entity[clear]->room[i]->item.~Vector();
			entity[clear]->room[i]->player.~Vector();
			entity[clear]->room[i]->room.~Vector();
			entity[clear]->room[i]->exit.~Vector();
		}
		entity[clear]->room.~Vector();
	}

	joint = nullptr;
	candies = nullptr;
	chocolate = nullptr;
	bottlewater = nullptr;
	pills = nullptr;
	perfume = nullptr;
	backpack = nullptr;
	scissors = nullptr;
	lighter = nullptr;
	umbrellas = nullptr;
	knife = nullptr;
	gun = nullptr;
	screwdriver = nullptr;
	powersupply = nullptr;

	player = nullptr;

	bedroom = nullptr;
	living = nullptr;
	entrance = nullptr;
	kitchen = nullptr;
	store = nullptr;
	machines = nullptr;
	drying = nullptr;
	research = nullptr;
	technology = nullptr;
	bossroom = nullptr;
	storesocks = nullptr;
}

void World::CreateWorld() 
{
	
	entity.push_back(new Entity("Entity 1", "Rooms"));
	entity[0]->room.push_back(bedroom = new Rooms("Bedroom", "Yeah... It's my bedroom...", "It smells a jerk..."));
	entity[0]->room.push_back(living = new Rooms("Living room", "Normal room that I use every day to contact the other world.", "Smells tasty... WTF?!? o_o"));
	entity[0]->room.push_back(entrance = new Rooms("Entrance hall", "Yeah... It's my bedroom...", "It smells a jerk..."));
	entity[0]->room.push_back(kitchen = new Rooms("Kitchen", "Too much sugar everywhere ._.", "Hmm... I'm hungry :3"));
	entity[0]->room.push_back(store = new Rooms("Storeroom", "Amount of rope everywhere...", "It smells trash"));
	entity[0]->room.push_back(machines = new Rooms("Machines room", "Too much metal", "Nosy!! OMG! PLS! STOP!"));
	entity[0]->room.push_back(drying = new Rooms("Drying room", "Wind everywhere", "I feel cold"));
	entity[0]->room.push_back(research = new Rooms("Research room", "Papers everiwhere...", "I can see lights..."));
	entity[0]->room.push_back(technology = new Rooms("Technology room", "Unknown technology... Waow *^*", "Too much security..."));
	entity[0]->room.push_back(bossroom = new Rooms("Boss room", "Wires across the room", "I activated my senses arachnids..."));
	entity[0]->room.push_back(storesocks = new Rooms("Store socks", "Socks everywhere!", "I supose that is the last room, pls!!"));


	entity.push_back(new Entity("Entity 2", "Exits"));
	entity[1]->exit.push_back(new Exits("Exit 1", "Bedroom and Living room", 'e', bedroom, living));
	entity[1]->exit.push_back(new Exits("Exit 2", "Living room and Entrance hall", 'n', living, entrance));
	entity[1]->exit.push_back(new Exits("Exit 3", "Living room and Kitchen", 'e', living, kitchen));
	entity[1]->exit.push_back(new Exits("Exit 4", "Kitchen and Storeroom", 's', kitchen, store));
	entity[1]->exit.push_back(new Exits("Exit 5", "Machines room and Drying room", 's', machines, drying));
	entity[1]->exit.push_back(new Exits("Exit 6", "Drying room and Research room", 'e', drying, research));
	entity[1]->exit.push_back(new Exits("Exit 7", "Research room and Technology room", 's', research, technology));
	entity[1]->exit.push_back(new Exits("Exit 8", "Research room and Boss room", 'e', research, bossroom));
	entity[1]->exit.push_back(new Exits("Exit 9", "Boss room and Store socks", 'n', bossroom, storesocks));
	

	entity.push_back(new Entity("Entity 3", "Players"));
	entity[2]->player.push_back(player = new Players("Juli", "The Best", entity[1]->exit.size(),1,2,10));
	player->room.push_back(player->pos = bedroom);
	player->p = this;
	
	
	entity.push_back(new Entity("Entity 4", "Items"));
	entity[3]->item.push_back(joint = new Items("joint", "You tavell a lot..",true, 0, -3));
	living->item.push_back(joint);
	entity[3]->item.push_back(candies = new Items("candies", "Hmmm, delicios :3",true, 0, 0, 2));
	player->item.push_back(candies);
	entity[3]->item.push_back(chocolate = new Items("chocolate", "Hmmm, delicios :3",true, 0, 0, 5));
	kitchen->item.push_back(chocolate);
	entity[3]->item.push_back(bottlewater = new Items("bottle of water", "Very important for live..",true, 1, 0, 1));
	kitchen->item.push_back(bottlewater);
	entity[3]->item.push_back(pills = new Items("pills", "I'm sick ;(",true, 0, 0, 10));
	bedroom->item.push_back(pills);
	entity[3]->item.push_back(perfume = new Items("perfume", "I'm glourious :D",true));
	bedroom->item.push_back(perfume);

	entity[3]->item.push_back(backpack = new Items("backpack", "More place for items :D",false, 0, 3, 0, true, 5));
	bedroom->item.push_back(backpack);

	entity[3]->item.push_back(scissors = new Items("scissors", "Cut everithing",false, 2));
	living->item.push_back(scissors);
	entity[3]->item.push_back(lighter = new Items("lighter", "Burn everithing", false, 4));
	living->item.push_back(lighter);
	entity[3]->item.push_back(umbrellas = new Items("umbrellas", "It's raining men..", false, 1));
	entrance->item.push_back(umbrellas);
	entity[3]->item.push_back(knife = new Items("knife", "I cut my finger :D", false, 5));
	kitchen->item.push_back(knife);
	entity[3]->item.push_back(gun = new Items("gun", "Shot the air", false, 6));
	bedroom->item.push_back(gun);

	entity[3]->item.push_back(screwdriver = new Items("screwdriver", "Fix some bugs", false, 2));
	machines->item.push_back(screwdriver);
	entity[3]->item.push_back(powersupply = new Items("power supply", "More energy, please",false));
	technology->item.push_back(powersupply);
}

void World::Command() 
{
	Vector<My_String*> commands;
	My_String* command = nullptr;
	My_String* command2 = nullptr;
	My_String* command3 = nullptr;
	My_String* command4 = nullptr;
	unsigned int size = NULL;

	commands.push_back(new My_String);

	printf("Write the command: ");
	commands[0]->write();

	commands[0]->tokens(" ", commands);
	size = commands.size();

	if (size == 4)
	{
		command = commands[0];
		command2 = commands[1];
		command3 = commands[2];
		command4 = commands[3];
	}
	else if (size == 3)
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
			player->Look(NULL);
		else if (*command2 == "north" || *command2 == "south" || *command2 == "east" || *command2 == "west")
			player->Look(*command2->c_str());
		else if (*command2 == "n" || *command2 == "s" || *command2 == "e" || *command2 == "w")
			player->Look(*command2->c_str());
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
				player->Movement(*command2->c_str());
			else if (*command2 == "n" || *command2 == "s" || *command2 == "e" || *command2 == "w")
				player->Movement(*command2->c_str());
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
					player->OpenDoor(NULL);
				else
				{
					printf("Introduce a good command...\n\n");
					Command();
				}
			}
			else
			{
				if ((*command2 == "north" || *command2 == "south" || *command2 == "east" || *command2 == "west") && (*command3 == "door" || *command3 == "gate"))
					player->OpenDoor(*command2->c_str());
				else if ((*command2 == "n" || *command2 == "s" || *command2 == "e" || *command2 == "w") && (*command3 == "door" || *command3 == "gate"))
					player->OpenDoor(*command2->c_str());
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
					player->CloseDoor(NULL);
				else
				{
					printf("Introduce a good command...\n\n");
					Command();
				}
			}
			else
			{
				if ((*command2 == "north" || *command2 == "south" || *command2 == "east" || *command2 == "west") && (*command3 == "door" || *command3 == "gate"))
					player->CloseDoor(*command2->c_str());
				else if ((*command2 == "n" || *command2 == "s" || *command2 == "e" || *command2 == "w") && (*command3 == "door" || *command3 == "gate"))
					player->CloseDoor(*command2->c_str());
				else
				{
					printf("Introduce a good command...\n\n");
					Command();
				}
			}
		}
	}
	else if ((*command == "pick" || *command == "drop") && command3 == nullptr)
	{
		if (command2 == nullptr)
		{
			printf("Introduce a good command...\n\n");
			Command();
		}
		else
		{
			player->PDItem(*command->c_str(),command2->c_str());
		}
	}
	else if ((*command == "inventory" || *command == "inv" || *command == "i") && command2 == nullptr)
	{
		player->Inventory();
	}
	else if ((*command == "equip" || *command == "unequip") && command3 == nullptr)
	{
		if (command2 == nullptr)
		{
			printf("Introduce a good command...\n\n");
			Command();
		}
		else
		{
			player->EUItem(*command->c_str(), command2->c_str());
		}
	}
	else if (*command == "put")
	{
		if (command4 == nullptr)
		{
			printf("Introduce a good command...\n\n");
			Command();
		}
		else
		{
			if (*command3 == "into")
				player->PGItem(*command->c_str(), command2->c_str(), command4->c_str());
			else 
			{
				printf("Introduce a good command...\n\n");
				Command();
			}
		}
	}
	else if (*command == "get")
	{
		if (command4 == nullptr)
		{
			printf("Introduce a good command...\n\n");
			Command();
		}
		else
		{
			if (*command3 == "from")
				player->PGItem(*command->c_str(), command2->c_str(), command4->c_str());
			else
			{
				printf("Introduce a good command...\n\n");
				Command();
			}
		}
	}
	else if (*command == "stats" && command2 == nullptr)
	{
		player->PrintStats();
	}
	else if (*command == "quit" && command2 == nullptr)
	{
		loop = false;
	}
	else if (*command == "help" && command2 == nullptr)
	{
		Help();
	}
	else if (*command == "enter" && command3 == nullptr)
	{
		if (command4 == nullptr)
		{
			printf("Introduce a good command...\n\n");
			Command();
		}
		else
		{
			if (*command2 == "portal")
				player->ChangeWorld();
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

	for (unsigned int i = 0; i < size; i++)
		commands[i]->~My_String();
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