#ifndef __players__
#define __players__

#include "entity.h"
#include "rooms.h"
#include "VectorDynamic.h"
#include "items.h"

class Players : public Entity
{
public:
	Rooms* pos = nullptr;
	//Vector<Items*>* itemlist;


	//Variables for doing the Close/Open door funciton, with totally uses of commands.
	char lasttrieddoor;
	bool movclose = false;

public:
	Players(const char* name, const char* desc, Rooms* pos) : Entity(name, desc), pos(pos){};
	~Players(){};

	void Look(char);
	void Movement(char);
	void ChangeWorld();
	void OpenDoor(char);
	void CloseDoor(char);
	short FindExit(char dir)const;
	void PrintOCDoor(short, bool)const;
};

#endif //__players__