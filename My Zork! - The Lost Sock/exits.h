#ifndef __exits__
#define __exits__

#include "rooms.h"

class Exits
{
public:
	bool door = false;
	Rooms* origin = nullptr;
	Rooms* destiny = nullptr;
	char dir_dest;

};

#endif //__exits__