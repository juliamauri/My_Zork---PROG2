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
	bool init_item;

public:
	Rooms(const char* name, const char* desc, const char* descexit, bool init_item = true) : Entity(name, desc), descexit(descexit), init_item(init_item)
	{
		if (init_item == true)
			item.Init();
	};
	~Rooms()
	{
	};

	void DescExit()const;
};

#endif //__rooms__