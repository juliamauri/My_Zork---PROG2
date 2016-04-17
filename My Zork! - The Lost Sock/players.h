#ifndef __players__
#define __players__

#include "entity.h"
#include "rooms.h"
#include "VectorDynamic.h"
#include "items.h"

class World;

class Players : public Entity
{
public:
	World* p;
	Rooms* pos = nullptr;
	Items* itemequip = nullptr;
	unsigned int ext_size = NULL;
	unsigned int itemcarry = NULL;
	unsigned int max_itemcarry = 3;

	//Variables for doing the Close/Open door funciton, with totally uses of commands.
	char lasttrieddoor;
	bool movclose = false;

public:
	Players(const char* name, const char* desc,unsigned int ext_size) : Entity(name, desc),ext_size(ext_size){};
	~Players(){};

	void Look(char);
	void Movement(char);
	void ChangeWorld();
	void OpenDoor(char);
	void CloseDoor(char);
	void PDItem(char,const char*);
	void Inventory();
	void EUItem(char,const char*);
	void PGItem(const char*, const char*);
	short FindExit(char)const;
	void PrintOCDoor(short, bool)const;
};

#endif //__players__