#ifndef __players__
#define __players__

#include "world.h"

class Players
{
public:
	int pos;
	char lastcloseddoor;
	int lastnumdoor;
	bool movclose[4];

	World* p;

public:
	void Look(char);
	void Movement(char);
	void ChangeWorld();
	void OpenDoor(char);
	void CloseDoor(char);
	int FindExit(int);
};

#endif //__players__