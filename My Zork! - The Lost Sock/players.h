#ifndef __PLAYERS_H__
#define __PLAYERS_H__

#include "Creature.h"

class Items;
class Rooms;

class Players : public Creature
{
public:
	Items* itemequip = nullptr;
	uint itemcarry = NULL;
	uint max_itemcarry = 3;

	List<Entity*> exit_list;
	Node<Entity*>* exit_node = nullptr;
	Node<Entity*>* item_node = nullptr;

	//Variables for doing the Close/Open door funciton, with totally uses of commands.
	char lasttrieddoor;
	bool movclose = false;

public:
	Players(const char* name, const char* desc, Rooms* pos, EntityType type, int attack = 0, int defense = 0, int hp = 0) : Creature(name,desc,pos,type,attack,defense,hp){};
	~Players(){};

	void Look(char);
	void Movement(char);
	void ChangeWorld();
	void OpenDoor(char);
	void CloseDoor(char);
	void PDItem(char,const char*);
	void Inventory();
	void EUItem(char,const char*);
	void PGItem(char,const char*, const char*);
	void UpdateStats();
	void PrintStats();
	bool FindExit(char);
	void PrintOCDoor(short, bool)const;
	void SetExits();
};

#endif //__PLAYERS_H__