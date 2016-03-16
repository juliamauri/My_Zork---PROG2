#ifndef __players__
#define __players__

#include "world.h"

class Players
{
public:
	short pos;
	char lastcloseddoor;
	short lastnumdoor;
	bool movclose;

	World* p;

public:
	void Look(char);
	void Movement(char);
	void ChangeWorld();
	void OpenDoor(char);
	void CloseDoor(char);
	short FindExit(short);
};

#endif //__players__