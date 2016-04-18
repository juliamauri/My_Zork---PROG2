#ifndef __players__
#define __players__

#include "entity.h"
#include "rooms.h"
#include "VectorDynamic.h"
#include "items.h"
#include "stats.h"

class World;

class Players : public Entity, public Stats
{
public:
	World* p;
	Rooms* pos = nullptr;
	Items* itemequip = nullptr;
	unsigned int ext_size = NULL;
	unsigned int itemcarry = NULL;
	unsigned int max_itemcarry = 3;
	bool init_item;

	//Variables for doing the Close/Open door funciton, with totally uses of commands.
	char lasttrieddoor;
	bool movclose = false;

public:
	Players(const char* name, const char* desc, int ext_size, int attack = 0, int defense = 0, int hp = 0, bool init_item = false) : Entity(name, desc), ext_size(ext_size), Stats(attack, defense, hp), init_item(init_item)
	{
		if (init_item == true)
			item.Init();
	};
	~Players()
	{
	};

	void Look(char);
	void Movement(char);
	void ChangeWorld();
	void OpenDoor(char);
	void CloseDoor(char);
	void PDItem(char,const char*);
	void Inventory();
	void EUItem(char,const char*);
	void PGItem(char,const char*, const char*);
	void UpdateStats();
	void PrintStats();
	short FindExit(char)const;
	void PrintOCDoor(short, bool)const;
};

#endif //__players__