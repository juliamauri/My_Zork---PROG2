#ifndef __items__
#define __items__

#include "entity.h"
#include "stats.h"

class Items : public Entity, public Stats
{
public:
	bool objectsarea;
	bool consumable;
	unsigned int itemcarry = NULL;
	unsigned int max_itemcarry = NULL;

public:
	Items(const char* name, const char* desc, bool consumable, int attack = 0, int defense = 0, int hp = 0, bool objectsarea = false, unsigned int max_itemcarry = 2) : Entity(name, desc), consumable(consumable), Stats(attack, defense, hp), objectsarea(objectsarea), max_itemcarry(max_itemcarry)
	{
		if (objectsarea == true)
			item.Init();
	};
	~Items()
	{
	};
};

#endif //__items__