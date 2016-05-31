#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "Globals.h"
#include "My_String.h"
#include "Linked_List.h"

class Entity
{

public:


	EntityType type;

	My_String name;
	My_String desc;

	List<Entity*> contains;

public:
	Entity(const char* name, const char* desc, EntityType type) : name(name), desc(desc), type(type){};
	virtual ~Entity() {};

	virtual update_status Update() { return update_status::UPDATE_CONTINUE; }

	void Desc()const;
};

#endif //__ENTITY_H__