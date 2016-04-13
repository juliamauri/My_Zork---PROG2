#include <stdio.h>
#include <stdlib.h>

#include "exits.h"
#include "rooms.h"
#include "players.h"
#include "My_String.h"

#include "world.h"

World::World()
{
	room = new Rooms[NUM_ROOMS];
	exit = new Exits[NUM_CONNECTIONS];
	player = new Players;
	player->p = this;
}

World::~World()
{
	delete[] room;
	delete[] exit;
	delete player;
}

void World::CreateWorld() const
{
	player->pos = &room[0];


	room[0].name.write("Bedroom");
	room[0].desc.write("Yeah... It's my bedroom...");
	room[0].descexit.write("It smells a jerk...");

	exit[0].origin = &room[0];
	

	room[1].name.write("Living room");
	room[1].desc.write("My room thatI smoke weed every day(taranta tararan...[song]). One joint stay on the table <3");
	room[1].descexit.write("It smells a weed *^*");

	exit[1].origin = &room[1];
	exit[2].origin = &room[1];
	exit[0].destiny = &room[1];
	exit[0].dir_dest = 'e';
	

	room[2].name.write("Entrance hall");
	room[2].desc.write("Normal room that I use every day to contact the other world.");
	room[2].descexit.write("Smells tasty... WTF?!? o_o");

	exit[1].destiny = &room[2];
	exit[1].dir_dest = 'n';
	

	room[3].name.write("Kitchen");
	room[3].desc.write("Too much sugar everywhere ._.");
	room[3].descexit.write("Hmm... I'm hungry :3");

	exit[3].origin  = &room[3];
	exit[2].destiny = &room[3];
	exit[2].dir_dest = 'e';


	room[4].name.write("Storeroom");
	room[4].desc.write("Amount of rope everywhere...");
	room[4].descexit.write("It smells trash");

	exit[3].destiny = &room[4];
	exit[3].dir_dest = 's';


	room[5].name.write("Machines room");
	room[5].desc.write("Too much metal");
	room[5].descexit.write("Nosy!! OMG! PLS! STOP!");


	exit[4].origin = &room[5];


	room[6].name.write("Drying room");
	room[6].desc.write("Wind everywhere");
	room[6].descexit.write("I fell cold");

	exit[4].destiny = &room[6];
	exit[4].dir_dest = 's';
	exit[5].origin = &room[6];


	room[7].name.write("Research room");
	room[7].desc.write("Papers everiwhere...");
	room[7].descexit.write("I can see lights...");

	exit[6].origin = &room[7];
	exit[7].origin = &room[7];
	exit[5].destiny = &room[7];
	exit[5].dir_dest = 'e';


	room[8].name.write("Technology room");
	room[8].desc.write("Unknown technology... Waow *^*");
	room[8].descexit.write("Too much security...");

	exit[6].destiny = &room[8];
	exit[6].dir_dest = 's';


	room[9].name.write("Boss room");
	room[9].desc.write("Wires across the room");
	room[9].descexit.write("I activated my senses arachnids...");

	exit[8].origin = &room[9];
	exit[7].destiny = &room[9];
	exit[7].dir_dest = 'e';


	room[10].name.write("Store socks");
	room[10].desc.write("Socks everywhere!");
	room[10].descexit.write("I supose that is the last room, pls!!");

	exit[8].destiny = &room[10];
	exit[8].dir_dest = 'n';


	player->movclose = false;
}

void World::Command() 
{
	My_String command;

	printf("Write the command: ");
	
	command.write();
	My_String command2 = command -= " ";
	My_String command3 = command2 -= " ";
	My_String rest = command3 -= " ";
	
	if (rest == ""){
		if (command == "look")
		{
			if (command3 == "" && (command2 == "north" || command2 == "south" || command2 == "east" || command2 == "west"))
				player->Look(*command2.c_str());
			else if (command3 == "" && (command2 == "n" || command2 == "s" || command2 == "e" || command2 == "w"))
				player->Look(*command2.c_str());
			else if (command3 == "" && command2 == "")
				player->Look(NULL);
			else{
				printf("Introduce a good command...\n\n");
				Command();
			}
		}
		else if (command == "go")
		{
			if (command3 == "" && (command2 == "north" || command2 == "south" || command2 == "east" || command2 == "west"))
				player->Movement(*command2.c_str());
			else if (command3 == "" && (command2 == "n" || command2 == "s" || command2 == "e" || command2 == "w"))
				player->Movement(*command2.c_str());
			else{
				printf("Introduce a good command...\n\n");
				Command();
			}
		}
		else if (command == "open")
		{
			if (command3 == ""){
				if (command2 == "door" || command2 == "gate")
					player->OpenDoor(NULL);
				else{
					printf("Introduce a good command...\n\n");
					Command();
				}
			}
			else if (rest == ""){
				if ((command2 == "north" || command2 == "south" || command2 == "east" || command2 == "west") && (command3 == "door" || command3 == "gate"))
					player->OpenDoor(*command2.c_str());
				else if ((command2 == "n" || command2 == "s" || command2 == "e" || command2 == "w") && (command3 == "door" || command3 == "gate"))
					player->OpenDoor(*command2.c_str());
				else{
					printf("Introduce a good command...\n\n");
					Command();
				}
			}
			else{
				printf("Introduce a good command...\n\n");
				Command();
			}
		}
		else if (command == "close")
		{
			if (command3 == ""){
				if (command2 == "door" || command2 == "gate")
					player->CloseDoor(NULL);
				else{
					printf("Introduce a good command...\n\n");
					Command();
				}
			}
			else if (rest == ""){
				if ((command2 == "north" || command2 == "south" || command2 == "east" || command2 == "west") && (command3 == "door" || command3 == "gate"))
					player->CloseDoor(*command2.c_str());
				else if ((command2 == "n" || command2 == "s" || command2 == "e" || command2 == "w") && (command3 == "door" || command3 == "gate"))
					player->CloseDoor(*command2.c_str());
				else{
					printf("Introduce a good command...\n\n");
					Command();
				}
			}
			else{
				printf("Introduce a good command...\n\n");
				Command();
			}
		}
		else if (command == "quit")
		{
			loop = false;
		}
		else if (command == "help")
		{
			Help();
		}
		else if (command == "enter")
		{
			if (command3 == "" && command2 == "portal")
				player->ChangeWorld();
			else{
				printf("Introduce a good command...\n\n");
				Command();
			}
		}
		else{
			printf("Introduce a good command...\n\n");
			Command();
		}
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

void World::Init()const{
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