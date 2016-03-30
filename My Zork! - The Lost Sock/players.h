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
	void Look(char)const;
	void Movement(char);
	void ChangeWorld();
	void OpenDoor(char);
	void CloseDoor(char);
	short FindExit(short)const;
	void PrintOCDoor(short, bool)const;
};

#endif //__players__