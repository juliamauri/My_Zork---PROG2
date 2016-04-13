#ifndef __players__
#define __players__

#include "world.h"
#include "rooms.h"

class Players
{
public:
	World* p;
	Rooms* pos;

	//Variables for doing the Close/Open door funciton, with totally uses of commands.
	char lastcloseddoor;
	short lastnumdoor;
	bool movclose;

public:
	void Look(char);
	void Movement(char);
	void ChangeWorld();
	//void OpenDoor(char);
	//void CloseDoor(char);
	short FindExit(char dir);
	//void PrintOCDoor(short, bool)const;
};

#endif //__players__