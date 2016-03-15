#include <stdio.h>
#include <string.h>

#include "exits.h"
#include "rooms.h"
#include "players.h"

#include "world.h"

#define NUM_ROOMS 11

World::World()
{
	room = new Rooms[NUM_ROOMS];
	exit = new Exits[NUM_ROOMS];
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

	player[0].pos = 1;

	strcpy_s(room[0].name, "Bedroom"); 
	strcpy_s(room[0].desc, "Desc 1");
	room[0].world = 1;
	room[0].n_room = 1;
	room[0].n = 0;
	room[0].s= 0;
	room[0].e = 2;
	room[0].w = 0;

	strcpy_s(room[1].name, "Living room");
	strcpy_s(room[1].desc, "Desc 2");
	room[1].world = 1;
	room[1].n_room = 2;
	room[1].n = 3;
	room[1].s = 0;
	room[1].e = 4;
	room[1].w = 1;
	
	strcpy_s(room[2].name, "Entrance hall"); 
	strcpy_s(room[1].desc, "Desc 2");
	room[1].world = 1;
	room[2].n_room = 3;
	room[2].n = 0;
	room[2].s = 2;
	room[2].e = 0;
	room[2].w = 0;
	
	strcpy_s(room[3].name, "Kitchen");
	strcpy_s(room[3].desc, "Desc 4");
	room[3].world = 1;
	room[3].n_room = 4;
	room[3].n = 0;
	room[3].s = 5;
	room[3].e = 0;
	room[3].w = 2;

	strcpy_s(room[4].name, "Storeroom");
	strcpy_s(room[4].desc, "Desc 5");
	room[4].world = 1;
	room[4].n_room = 5;
	room[4].n = 4;
	room[4].s = 0;
	room[4].e = 0;
	room[4].w = 0;

	strcpy_s(room[5].name, "Machines room");
	strcpy_s(room[5].desc, "Desc 6");
	room[5].world = 2;
	room[5].n_room = 6;
	room[5].n = 0;
	room[5].s = 7;
	room[5].e = 0;
	room[5].w = 0;

	strcpy_s(room[6].name, "Drying room");
	strcpy_s(room[6].desc, "Desc 7");
	room[6].world = 2;
	room[6].n_room = 7;
	room[6].n = 6;
	room[6].s = 0;
	room[6].e = 8;
	room[6].w = 0;

	strcpy_s(room[7].name, "Research room");
	strcpy_s(room[7].desc, "Desc 8");
	room[7].world = 2;
	room[7].n_room = 8;
	room[7].n = 4;
	room[7].s = 9;
	room[7].e = 10;
	room[7].w = 7;

	strcpy_s(room[8].name, "Technology room");
	strcpy_s(room[8].desc, "Desc 9");
	room[8].world = 2;
	room[8].n_room = 9;
	room[8].n = 8;
	room[8].s = 0;
	room[8].e = 0;
	room[8].w = 0;

	strcpy_s(room[9].name, "Boss room");
	strcpy_s(room[9].desc, "Desc 10");
	room[9].world = 2;
	room[9].n_room = 10;
	room[9].n = 11;
	room[9].s = 0;
	room[9].e = 0;
	room[9].w = 8;

	strcpy_s(room[10].name, "Store socks");
	strcpy_s(room[10].desc, "Desc 11");
	room[10].world = 2;
	room[10].n_room = 11;
	room[10].n = 0;
	room[10].s = 10;
	room[10].e = 0;
	room[10].w = 0;


	for (int i = 0; i < 11; i++)
	{
		exit[i].pos = room[0].n_room;
	}

}

void World::Command()
{
	char cmd[20];
	char *command;
	char *rest;

	printf("Write the command: ");
	fgets(cmd, 20, stdin);
	fflush(stdin);

	strtok_s(cmd, " ", &command);
	strtok_s(command,"\n", &rest);

	if (strcmp(cmd, "look") == 0)
	{
		// do something
	}
	else if (strcmp(cmd, "go") == 0)
	{
		if (strcmp(command, "north") == 0 || strcmp(command, "south") == 0 || strcmp(command, "east") == 0 || strcmp(command, "west") == 0)
			player->Movement(*command);
		else if (*command == 'n' || *command == 's' || *command == 'e' || *command == 'o')
			player->Movement(*command);
		else
			printf("Introduce a good command...\n");
			Command();
	}
	else if (strcmp(cmd, "open") == 0)
	{
		// do something else
	}
	else if (strcmp(cmd, "close") == 0)
	{
		// do something else
	}
	else if (strcmp(cmd, "quit") == 0)
	{
		// do something else
	}
	else if (strcmp(cmd, "help") == 0)
	{
		// do something else
	}
	else
	{
		printf("Introduce a good command...\n");
		Command();
	}

}


void World::DetectionRoom()
{
	printf("Actual room: %s.\n", room[player[0].pos - 1].name);
}