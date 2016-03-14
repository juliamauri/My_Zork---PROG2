#include "rooms.h"
#include "players.h"

class World
{
public:
	Rooms* room = nullptr;
	Players* player = nullptr;

public:
	World();
	~World();

	void CreateWorld();
	void Movement();

};