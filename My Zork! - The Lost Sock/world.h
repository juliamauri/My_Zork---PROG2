#ifndef __WORLD_H__
#define __WORLD_H__

#include "Globals.h"
#include "VectorDynamic.h"
#include "Entity.h"
#include "Linked_List.h"

class Players;

class World
{
public:
	bool loop = true;
	Vector<Entity*> entities;
	Players* player = nullptr;

public:
	World();
	~World();

	update_status Update();

	void CreateWorld();
	void Command();
	void Help()const;
	void Init();
	void Loop();
	Entity* Find(EntityType type);
	List<Entity*> FindAll(EntityType type);
};

extern World* Wd;

#endif //__WORLD_H__