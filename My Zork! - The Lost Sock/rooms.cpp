#include "rooms.h"

void Rooms::DescExit()const
{
	printf("Next room:\n%s\n\n", descexit.c_str());
}

update_status Rooms::Update()
{
	if (contains.empty() == false)
		ObjectsinRoom = true;
	else
		ObjectsinRoom = false;

	return UPDATE_CONTINUE;
}