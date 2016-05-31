#ifndef __GLOBALS_H__
#define __GLOBALS_H__

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

enum EntityType
{
	PLAYER,
	ITEM,
	ROOM,
	EXIT
};

typedef unsigned int uint;

#define NUM_EXITS 9
#define NUM_ITEMS 14

#endif // __GLOBALS_H__
