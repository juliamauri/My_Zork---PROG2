#ifndef __players__
#define __players__

#include "world.h"

class Players
{
public:
	World* p;
	short pos;

	//Variables for doing the Close/Open door funciton, with totally uses of commands.
	char lastcloseddoor;
	short lastnumdoor;
	bool movclose;

public:
	void Look(char);
	void Movement(char);
	void ChangeWorld();
	void OpenDoor(char);
	void CloseDoor(char);
	short FindExit(short);
};

#endif //__players__