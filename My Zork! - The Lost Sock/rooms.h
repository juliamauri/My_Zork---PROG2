#ifndef __rooms__
#define __rooms__

class Rooms
{
public:
	short n, s, e, w; //Contanins number of next room, 0 is nothing
	short n_room; //Contains number soom and world
	char name[20];
	char desc[250];
	char descexit[150];

public:
	void Desc() const;
	void DescExit() const;
	short DirNum(char)const;
};

#endif //__rooms__