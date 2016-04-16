#ifndef __world__
#define __world__

#include "entity.h"
#include "VectorDynamic.h"
#include "rooms.h"
#include "exits.h"
#include "players.h"
#include "items.h"

class World
{
public:
	bool loop = true;
	Vector<Entity*> entity;
	Players* player = nullptr;

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

public:
	World();
	~World();

	void CreateWorld();
	void Command();
	void Help()const;
	void Init();
	void Loop();
};

#endif //__world__