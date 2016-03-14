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

	room[0].n_room = 1;
	room[0].n = 0;
	room[0].s= 0;
	room[0].e = 2;
	room[0].w = 0;

	strcpy_s(room[1].name, "Living room");
	
	room[1].n_room = 2;
	room[1].n = 3;
	room[1].s = 0;
	room[1].e = 4;
	room[1].w = 1;
	
	strcpy_s(room[2].name, "Entrance hall"); 
	
	room[2].n_room = 3;
	room[2].n = 0;
	room[2].s = 2;
	room[2].e = 0;
	room[2].w = 0;
	
	strcpy_s(room[3].name, "Kitchen");

	room[3].n_room = 4;
	room[3].n = 0;
	room[3].s = 5;
	room[3].e = 0;
	room[3].w = 2;

	strcpy_s(room[4].name, "Storeroom");

	room[4].n_room = 5;
	room[4].n = 4;
	room[4].s = 0;
	room[4].e = 0;
	room[4].w = 0;

	strcpy_s(room[5].name, "Machines room");
	strcpy_s(room[6].name, "Drying room");
	strcpy_s(room[7].name, "Research room");
	strcpy_s(room[8].name, "Technology room");
	strcpy_s(room[9].name, "Boss room");
	strcpy_s(room[10].name, "Store socks");

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