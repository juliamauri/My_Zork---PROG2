#ifndef __rooms__
#define __rooms__

class Rooms
{
public:
	char name[20];
	char desc[250];
	char descexit[150];

public:
	void Desc() const;
	void DescExit() const;
};

#endif //__rooms__