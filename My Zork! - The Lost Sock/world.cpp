#include <stdio.h>
#include <stdlib.h>

#include "World.h"
#include "Players.h"
#include "Rooms.h"
#include "Exits.h"
#include "Stats.h"
#include "Items.h"

World::World()
{}

World::~World()
{
	/*
	unsigned int sizeentities = entity.size();
	
	for (int clear = sizeentities - 1; clear >= 0; clear--)
	{
		int size = entity[clear]->item.size();
		for (int i = size - 1; i >= 0; i--)
		{
			delete entity[clear]->item[i];
		}
	

		size = entity[clear]->player.size();
		for (int i = size - 1; i >= 0; i--)
		{
			delete entity[clear]->player[i];
		}


		size = entity[clear]->exit.size();
		for (int i = size - 1; i >= 0; i--)
		{
			delete entity[clear]->exit[i];
		}


		size = entity[clear]->room.size();
		for (int i = size - 1; i >= 0; i--)
		{
			delete entity[clear]->room[i];
		}


		delete entity[clear];
	}
	*/
}

void World::CreateWorld()
{
	Rooms* bedroom = nullptr;
	Rooms* living = nullptr;
	Rooms* entrance = nullptr;
	Rooms* kitchen = nullptr;
	Rooms* store = nullptr;
	Rooms* machines = nullptr;
	Rooms* drying = nullptr;
	Rooms* research = nullptr;
	Rooms* technology = nullptr;
	Rooms* bossroom = nullptr;
	Rooms* storesocks = nullptr;

	Items* joint = nullptr;
	Items* candies = nullptr;
	Items* chocolate = nullptr;
	Items* bottlewater = nullptr;
	Items* pills = nullptr;
	Items* perfume = nullptr;
	Items* backpack = nullptr;
	Items* scissors = nullptr;
	Items* lighter = nullptr;
	Items* umbrellas = nullptr;
	Items* knife = nullptr;
	Items* gun = nullptr;
	Items* screwdriver = nullptr;
	Items* powersupply = nullptr;

	entities.push_back(bedroom = new Rooms("Bedroom", "Yeah... It's my bedroom...", "It smells a jerk...", ROOM));
	entities.push_back(living = new Rooms("Living room", "Normal room that I use every day to contact the other world.", "Smells tasty... WTF?!? o_o", ROOM));
	entities.push_back(entrance = new Rooms("Entrance hall", "Yeah... It's my bedroom...", "It smells a jerk...", ROOM));
	entities.push_back(kitchen = new Rooms("Kitchen", "Too much sugar everywhere ._.", "Hmm... I'm hungry :3", ROOM));
	entities.push_back(store = new Rooms("Storeroom", "Amount of rope everywhere...", "It smells trash", ROOM));
	entities.push_back(machines = new Rooms("Machines room", "Too much metal", "Nosy!! OMG! PLS! STOP!", ROOM));
	entities.push_back(drying = new Rooms("Drying room", "Wind everywhere", "I feel cold", ROOM));
	entities.push_back(research = new Rooms("Research room", "Papers everiwhere...", "I can see lights...", ROOM));
	entities.push_back(technology = new Rooms("Technology room", "Unknown technology... Waow *^*", "Too much security...", ROOM));
	entities.push_back(bossroom = new Rooms("Boss room", "Wires across the room", "I activated my senses arachnids...", ROOM));
	entities.push_back(storesocks = new Rooms("Store socks", "Socks everywhere!", "I supose that is the last room, pls!!", ROOM));
	//0 - 10

	entities.push_back(new Exits("Exit 1", "Bedroom and Living room", 'e', bedroom, living, EXIT));
	entities.push_back(new Exits("Exit 2", "Living room and Entrance hall", 'n', living, entrance, EXIT));
	entities.push_back(new Exits("Exit 3", "Living room and Kitchen", 'e', living, kitchen, EXIT));
	entities.push_back(new Exits("Exit 4", "Kitchen and Storeroom", 's', kitchen, store, EXIT));
	entities.push_back(new Exits("Exit 5", "Machines room and Drying room", 's', machines, drying, EXIT));
	entities.push_back(new Exits("Exit 6", "Drying room and Research room", 'e', drying, research, EXIT));
	entities.push_back(new Exits("Exit 7", "Research room and Technology room", 's', research, technology, EXIT));
	entities.push_back(new Exits("Exit 8", "Research room and Boss room", 'e', research, bossroom, EXIT));
	entities.push_back(new Exits("Exit 9", "Boss room and Store socks", 'n', bossroom, storesocks, EXIT));
	
	entities.push_back(player = new Players("Juli", "The Best", bedroom, PLAYER, 1, 2, 10));

	entities.push_back(joint = new Items("joint", "You tavell a lot..", ITEM, true, 0, -3));
	living->contains.pushback(joint);
	entities.push_back(candies = new Items("candies", "Hmmm, delicios :3", ITEM, true, 0, 0, 2));
	player->contains.pushback(candies);
	entities.push_back(chocolate = new Items("chocolate", "Hmmm, delicios :3", ITEM, true, 0, 0, 5));
	kitchen->contains.pushback(chocolate);
	entities.push_back(bottlewater = new Items("waterbottle", "Very important for live..", ITEM, true, 1, 0, 1));
	kitchen->contains.pushback(bottlewater);
	entities.push_back(pills = new Items("pills", "I'm sick ;(", ITEM, true, 0, 0, 10));
	bedroom->contains.pushback(pills);
	entities.push_back(perfume = new Items("perfume", "I'm glourious :D", ITEM, true));
	bedroom->contains.pushback(perfume);

	entities.push_back(backpack = new Items("backpack", "More place for items :D", ITEM, false, 0, 3, 0, true, 5));
	bedroom->contains.pushback(backpack);

	entities.push_back(scissors = new Items("scissors", "Cut everithing", ITEM, false, 2));
	living->contains.pushback(scissors);
	entities.push_back(lighter = new Items("lighter", "Burn everithing", ITEM, false, 4));
	living->contains.pushback(lighter);
	entities.push_back(umbrellas = new Items("umbrellas", "It's raining men..", ITEM, false, 1));
	entrance->contains.pushback(umbrellas);
	entities.push_back(knife = new Items("knife", "I cut my finger :D", ITEM, false, 5));
	kitchen->contains.pushback(knife);
	entities.push_back(gun = new Items("gun", "Shot the air", ITEM, false, 6));
	bedroom->contains.pushback(gun);

	entities.push_back(screwdriver = new Items("screwdriver", "Fix some bugs", ITEM, false, 2));
	machines->contains.pushback(screwdriver);
	entities.push_back(powersupply = new Items("powersupply", "More energy, please", ITEM, false));
	technology->contains.pushback(powersupply);

	player->SetExits();
}

void World::Command() 
{
	Vector<My_String*> commands(true);
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
	/*
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
	*/
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
		if (command2 == nullptr)
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
		delete commands[i];

}

void World::Help() const{
	system("cls");

	printf("Commands enabled:\n");
	printf("- look: for printing description room, possible exits and items.\n");
	printf("- look + direction: for printing description of possible exits content.\n");
	printf("- go + direction: for moving at rooms.");
	printf("- enter + portal: for passing the portal.");
	printf("- open/close + door/gate: for opening or closing doors/gates when you tryied to pass.\n");
	printf("- pick/drop + item: for picking and dropping items on the room.\n");
	printf("- inventory/inv/i: s for looking at the list of items player is carrying. You have 3 spaces of limit.\n");
	printf("- equip/unequip + item: for equiping any item at player.\n");
	printf("- put/get + item + into/from + item: put items inside other items.\n");
	printf("- stats: for seeing your stats, the objects can afect the stats.\n");
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
		player->localition->Desc();

		Command();

		printf("Pulse any key to continue...");
		getchar();

		system("cls");

	} while (loop != false);
}

Entity* World::Find(EntityType type)
{
	uint num_elements = entities.size();
	for (uint i = 0; i < num_elements; i++)
	{
		if (entities[i]->type == type)
			return entities[i];
	}
}

List<Entity*> World::FindAll(EntityType type)
{
	uint num_elements = entities.size();
	List<Entity*> ret;
	for (uint i = 0; i < num_elements; i++)
	{
		if (entities[i]->type == type)
			ret.pushback(entities[i]);
	}
	return ret;
}