#ifndef __world__
#define __world__

#define NUM_ROOMS 11
#define NUM_CONNECTIONS 9  //NUM_ROMS - 1 - (NUM_WORLDS(in my case, 2) - 1)

#include "rooms.h"
#include "exits.h"
class Players;

class World
{
public:
	bool loop = true;

	Rooms* room = nullptr;
	Exits* exit = nullptr;
	Players* player = nullptr;

public:
	World();
	~World();

	void CreateWorld()const;
	void Command();
	void Help()const;
	void Init();
	void Loop();
};

#endif //__world__