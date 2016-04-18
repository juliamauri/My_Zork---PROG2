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


public:
	World();
	~World();

	void CreateWorld();
	void Command();
	void Help()const;
	void Init();
	void Loop();
	void Quit();
};

#endif //__world__