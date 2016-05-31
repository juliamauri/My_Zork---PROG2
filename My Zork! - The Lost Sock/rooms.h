#ifndef __ROOMS_H__
#define __ROOMS_H__

#include "Entity.h"
#include "VectorDynamic.h"
#include "My_String.h"
#include "Items.h"

class Rooms : public Entity
{
public:
	My_String descexit;
	bool ObjectsinRoom = false;

public:
	Rooms(const char* name, const char* desc, const char* descexit, EntityType type) : Entity(name, desc, type), descexit(descexit){};
	~Rooms(){};

	update_status Update();

	void DescExit()const;
};

#endif //__ROOMS_H__