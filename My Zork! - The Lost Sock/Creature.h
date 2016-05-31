#ifndef __CREATURE_H__
#define __CREATURE_H__

#include "Entity.h"
#include "Stats.h"

class Rooms;

class Creature : public Entity, public Stats
{
public:
	Rooms* localition;

public:
	Creature(const char* name, const char* desc, Rooms* pos, EntityType type, int attack, int defense, int hp) : Entity(name, desc, type), Stats(attack, defense, hp), localition(pos){};
};

#endif //__CREATURE_H__