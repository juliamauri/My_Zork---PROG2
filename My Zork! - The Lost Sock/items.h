#ifndef __ITEMS_H__
#define __ITEMS_H__

#include "Entity.h"
#include "Stats.h"

class Items : public Entity, public Stats
{
public:
	bool objectsarea;
	bool consumable;
	uint itemcarry = NULL;
	uint max_itemcarry = NULL;

public:
	Items(const char* name, const char* desc, EntityType type, bool consumable, int attack = 0, int defense = 0, int hp = 0, bool objectsarea = false, unsigned int max_itemcarry = 2) : Entity(name, desc, type), consumable(consumable), Stats(attack, defense, hp), objectsarea(objectsarea), max_itemcarry(max_itemcarry){};
	~Items(){};
};

#endif //__ITEMS_H__