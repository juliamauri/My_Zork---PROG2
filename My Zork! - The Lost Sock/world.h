#include "rooms.h"
#include "players.h"
#include "exits.h"

class World
{
public:
	Rooms* room = nullptr;
	Exits* exit = nullptr;
	Players* player = nullptr;

public:
	World();
	~World();

	void CreateWorld();
	void Movement();
	void DetectionRoom();

};