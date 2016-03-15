#ifndef __players__
#define __players__

#include "world.h"

class Players
{
public:
	int pos;
	World* p;

public:
	void Movement(char);
	void ChangeWorld();
	int FindExit(int);
};

#endif //__players__