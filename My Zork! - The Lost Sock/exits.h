#ifndef __exits__
#define __exits__

#include "world.h"

class Exits
{
public:
	int o,d;
	bool door = false;
	char desc[150];
	World* e;
};

#endif //__exits__