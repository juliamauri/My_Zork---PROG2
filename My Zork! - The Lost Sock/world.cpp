#include <stdio.h>
#include <string.h>

#include "world.h"

World::World()
{
	room = new Rooms[11];
	player = new Players[1];
}

World::~World()
{
	delete[] room;
	delete[] player;
}

void World::CreateWorld()
{

	player[0].pos = 1;

	strcpy_s(room[0].name, "Bedroom"); 

	room[0].n_room = 1;
	room[0].n = 0;
	room[0].s= 0;
	room[0].e = 2;
	room[0].o = 0;

	strcpy_s(room[1].name, "Living room");
	
	room[1].n_room = 2;
	room[1].n = 3;
	room[1].s = 0;
	room[1].e = 4;
	room[1].o = 1;
	
	strcpy_s(room[2].name, "Entrance hall"); 
	
	room[2].n_room = 3;
	room[2].n = 0;
	room[2].s = 2;
	room[2].e = 0;
	room[2].o = 0;
	
	strcpy_s(room[3].name, "Kitchen");

	room[3].n_room = 4;
	room[3].n = 0;
	room[3].s = 5;
	room[3].e = 0;
	room[3].o = 2;

	strcpy_s(room[4].name, "Storeroom");

	room[4].n_room = 5;
	room[4].n = 4;
	room[4].s = 0;
	room[4].e = 0;
	room[4].o = 0;

	strcpy_s(room[5].name, "Machines room");
	strcpy_s(room[6].name, "Drying room");
	strcpy_s(room[7].name, "Research room");
	strcpy_s(room[8].name, "Technology room");
	strcpy_s(room[9].name, "Boss room");
	strcpy_s(room[10].name, "Store socks");

}

void World::Movement()
{
	char dir = '\0';

	do{
		printf("Say direction n s e o: ");
		scanf_s("%c", &dir);
		fflush(stdin);
	} while (dir != 'n' && dir != 's' && dir != 'e' && dir != 'o');

	switch (dir)
	{
	case 'n':
		if (room[player[0].pos - 1].n != 0)
		{
			player[0].pos = room[player[0].pos - 1].n;
		}
		else
		{
			printf("Door doesn't exist.\n");
			Movement();
		}
		break;

	case 's':
		if (room[player[0].pos - 1].s != 0)
		{
			player[0].pos = room[player[0].pos - 1].s;
		}
		else
		{
			printf("Door doesn't exist.\n");
			Movement();
		}
		break;

	case 'e':
		if (room[player[0].pos - 1].e != 0)
		{
			player[0].pos = room[player[0].pos - 1].e;
		}
		else
		{
			printf("Door doesn't exist.\n");
			Movement();
		}
		break;

	case 'o':
		if (room[player[0].pos - 1].o != 0)
		{
			player[0].pos = room[player[0].pos - 1].o;
		}
		else
		{
			printf("Door doesn't exist.\n");
			Movement();
		}
		break;

	default:
		break;
	}

	
}