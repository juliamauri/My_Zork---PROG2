#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	char command[20];
	char *command2;
	char *command3;
	char *restcommand;

	printf("Write the command: ");
	
	/* Get the name, with size limit. */
	fgets(command, 20, stdin);
	fflush(stdin);
	/* Remove trailing newline, if there. */
	if ((strlen(command)>0) && (command[strlen(command) - 1] == '\n'))
		command[strlen(command) - 1] = '\0';

	My_String command1(command);

	//My_String command2 = command1 -= " ";
	/*
	strtok_s(command1, " ", &command2);
	strtok_s(command2, " ", &command3);
	if (strcmp(command3, "") == 0)
		strtok_s(command2, "\n", &restcommand);
	else
		strtok_s(command3, "\n", &restcommand);

	strtok_s(command1, "\n", &restcommand);
	*/

	/*
	if (strcmp(restcommand, "") == 0){
		if (strcmp(command1, "look") == 0)
		{
			if (strcmp(command3, "") == 0 && (strcmp(command2, "north") == 0 || strcmp(command2, "south") == 0 || strcmp(command2, "east") == 0 || strcmp(command2, "west") == 0))
				player->Look(*command2);
			else if (strcmp(command3, "") == 0 && (strcmp(command2, "n") == 0 || strcmp(command2, "s") == 0 || strcmp(command2, "e") == 0 || strcmp(command2, "w") == 0))
				player->Look(*command2);
			else if (strcmp(command3, "") == 0 && strcmp(command2, "") == 0)
				player->Look(NULL);
			else{
				printf("Introduce a good command...\n\n");
				Command();
			}
		}
		else if (strcmp(command1, "go") == 0)
		{
			if (strcmp(command3, "") == 0 && (strcmp(command2, "north") == 0 || strcmp(command2, "south") == 0 || strcmp(command2, "east") == 0 || strcmp(command2, "west") == 0))
				player->Movement(*command2);
			else if (strcmp(command3, "") == 0 (strcmp(command2, "n") == 0 || strcmp(command2, "s") == 0 || strcmp(command2, "e") == 0 || strcmp(command2, "w") == 0))
				player->Movement(*command2);
			else{
				printf("Introduce a good command...\n\n");
				Command();
			}
		}
		else if (strcmp(command1, "open") == 0)
		{
			if (strcmp(command3, "") == 0){
				if (strcmp(command2, "door") == 0 || strcmp(command2, "gate") == 0)
					player->OpenDoor(NULL);
				else{
					printf("Introduce a good command...\n\n");
					Command();
				}
			}
			else if (strcmp(restcommand, "") == 0){
				if ((strcmp(command2, "north") == 0 || strcmp(command2, "south") == 0 || strcmp(command2, "east") == 0 || strcmp(command2, "west") == 0) && ((strcmp(command3, "door") == 0 || strcmp(command3, "gate") == 0)))
					player->OpenDoor(*command2);
				else if ((strcmp(command2, "n") == 0 || strcmp(command2, "s") == 0 || strcmp(command2, "e") == 0 || strcmp(command2, "w") == 0) && ((strcmp(command3, "door") == 0 || strcmp(command3, "gate") == 0)))
					player->OpenDoor(*command2);
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
		else if (strcmp(command1, "close") == 0)
		{
			if (strcmp(command3, "") == 0){
				if (strcmp(command2, "door") == 0 || strcmp(command2, "gate") == 0)
					player->CloseDoor(NULL);
				else{
					printf("Introduce a good command...\n\n");
					Command();
				}
			}
			else if (strcmp(restcommand, "") == 0){
				if ((strcmp(command2, "north") == 0 || strcmp(command2, "south") == 0 || strcmp(command2, "east") == 0 || strcmp(command2, "west") == 0) && ((strcmp(command3, "door") == 0 || strcmp(command3, "gate") == 0)))
					player->CloseDoor(*command2);
				else if ((strcmp(command2, "n") == 0 || strcmp(command2, "s") == 0 || strcmp(command2, "e") == 0 || strcmp(command2, "w") == 0) && ((strcmp(command3, "door") == 0 || strcmp(command3, "gate") == 0)))
					player->CloseDoor(*command2);
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
		else if (strcmp(command1, "quit") == 0)
		{
			loop = false;
		}
		else if (strcmp(command1, "help") == 0)
		{
			Help();
		}
		else if (strcmp(command1, "enter") == 0)
		{
			if (strcmp(command3, "") == 0 && strcmp(command2, "portal") == 0)
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
	*/
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