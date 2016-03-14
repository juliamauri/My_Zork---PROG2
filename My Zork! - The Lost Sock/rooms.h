#ifndef __rooms__
#define __rooms__

class Rooms
{
public:
	int n, s, e, w; //Contanins number of next room, 0 is nothing
	int n_room, world; // Contains number soom and world
	char name[20];
	char desc[250];
};

#endif //__rooms__