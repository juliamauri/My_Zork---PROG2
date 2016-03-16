#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exits.h"
#include "rooms.h"
#include "players.h"

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

void World::CreateWorld()
{
	
	player->lastnumdoor = player->pos = 1;

	strcpy_s(room[0].name, "Bedroom"); 
	strcpy_s(room[0].desc, "Desc 1");
	strcpy_s(room[0].descexit, "DescExit 1");
	room[0].n_room = 1;
	room[0].n = 0;
	room[0].s= 0;
	exit[0].origin = room[0].e = 2;
	room[0].w = 0;
	

	strcpy_s(room[1].name, "Living room");
	strcpy_s(room[1].desc, "Desc 2");
	strcpy_s(room[1].descexit, "DescExit 2");
	room[1].n_room = 2;
	exit[1].origin = room[1].n = 3;
	room[1].s = 0;
	exit[2].origin = room[1].e = 4;
	exit[0].destiny = room[1].w = 1;
	
	strcpy_s(room[2].name, "Entrance hall"); 
	strcpy_s(room[2].desc, "Desc 2");
	strcpy_s(room[2].descexit, "DescExit 3");
	room[2].n_room = 3;
	room[2].n = 0;
	exit[1].destiny = room[2].s = 2;
	room[2].e = 0;
	room[2].w = 0;
	
	strcpy_s(room[3].name, "Kitchen");
	strcpy_s(room[3].desc, "Desc 4");
	strcpy_s(room[3].descexit, "DescExit 4");
	room[3].n_room = 4;
	room[3].n = 0;
	exit[3].origin  = room[3].s = 5;
	room[3].e = 0;
	exit[2].destiny = room[3].w = 2;

	strcpy_s(room[4].name, "Storeroom");
	strcpy_s(room[4].desc, "Desc 5");
	strcpy_s(room[4].descexit, "DescExit 5");
	room[4].n_room = 5;
	exit[3].destiny = room[4].n = 4;
	room[4].s = 0;
	room[4].e = 0;
	room[4].w = 0;

	strcpy_s(room[5].name, "Machines room");
	strcpy_s(room[5].desc, "Desc 6");
	strcpy_s(room[5].descexit, "DescExit 6");
	room[5].n_room = 6;
	room[5].n = 0;
	exit[4].origin = room[5].s = 7;
	room[5].e = 0;
	room[5].w = 0;

	strcpy_s(room[6].name, "Drying room");
	strcpy_s(room[6].desc, "Desc 7");
	strcpy_s(room[6].descexit, "DescExit 7");
	room[6].n_room = 7;
	exit[4].destiny = room[6].n = 6;
	room[6].s = 0;
	exit[5].origin = room[6].e = 8;
	room[6].w = 0;

	strcpy_s(room[7].name, "Research room");
	strcpy_s(room[7].desc, "Desc 8");
	strcpy_s(room[7].descexit, "DescExit 8");
	room[7].n_room = 8;
	room[7].n = 0;
	exit[6].origin = room[7].s = 9;
	exit[7].origin = room[7].e = 10;
	exit[5].destiny = room[7].w = 7;

	strcpy_s(room[8].name, "Technology room");
	strcpy_s(room[8].desc, "Desc 9");
	strcpy_s(room[8].descexit, "DescExit 9");
	room[8].n_room = 9;
	exit[6].destiny = room[8].n = 8;
	room[8].s = 0;
	room[8].e = 0;
	room[8].w = 0;

	strcpy_s(room[9].name, "Boss room");
	strcpy_s(room[9].desc, "Desc 10");
	strcpy_s(room[9].descexit, "DescExit 10");
	room[9].n_room = 10;
	exit[8].origin = room[9].n = 11;
	room[9].s = 0;
	room[9].e = 0;
	exit[7].destiny = room[9].w = 8;

	strcpy_s(room[10].name, "Store socks");
	strcpy_s(room[10].desc, "Desc 11");	
	strcpy_s(room[10].descexit, "DescExit 11");
	room[10].n_room = 11;
	room[10].n = 0;
	exit[8].destiny = room[10].s = 10;
	room[10].e = 0;
	room[10].w = 0;

	player->movclose = false;
}

void World::Command()
{
	char command1[20];
	char *command2;
	char *command3;
	char *restcommand;

	printf("Write the command: ");
	fgets(command1, 20, stdin);
	fflush(stdin);

	strtok_s(command1, " ", &command2);
	strtok_s(command2, " ", &command3);
	if (strcmp(command3, "") == 0)
		strtok_s(command2, "\n", &restcommand);
	else
		strtok_s(command3, "\n", &restcommand);

	strtok_s(command1, "\n", &restcommand);

	if (strcmp(restcommand, "") == 0){
		if (strcmp(command1, "look") == 0)
		{
			if (strcmp(command3, "") == 0 && (strcmp(command2, "north") == 0 || strcmp(command2, "south") == 0 || strcmp(command2, "east") == 0 || strcmp(command2, "west") == 0))
				player->Look(*command2);
			else if (strcmp(command3, "") == 0 && (strcmp(command2, "n") == 0 || strcmp(command2, "s") == 0 || strcmp(command2, "e") == 0 || strcmp(command2, "w") == 0))
				player->Look(*command2);
			else if (strcmp(command3, "") == 0 && strcmp(command2, "") == 0)
				player->Look(*command3);
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
}

void World::Help(){
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

void World::Loop(){
	
	do{
		room[(player->pos) - 1].Desc();

		Command();

		printf("Pulse any key to continue...");
		getchar();

		system("cls");

	} while (loop != false);
}