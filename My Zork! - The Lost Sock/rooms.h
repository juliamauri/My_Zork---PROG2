#ifndef __rooms__
#define __rooms__

#include "entity.h"
#include "VectorDynamic.h"
#include "My_String.h"
#include "items.h"

class Rooms : public Entity
{
public:
	My_String descexit;
	unsigned int numberitems = NULL;

public:
	Rooms(const char* name, const char* desc, const char* descexit) : Entity(name, desc), descexit(descexit){};
	~Rooms(){};

	void DescExit()const;
};

#endif //__rooms__