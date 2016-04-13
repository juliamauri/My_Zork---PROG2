#ifndef __rooms__
#define __rooms__

#include "My_String.h"

class Rooms
{
public:
	My_String name;
	My_String desc;
	My_String descexit;

public:
	void Desc() const;
	void DescExit() const;
};

#endif //__rooms__