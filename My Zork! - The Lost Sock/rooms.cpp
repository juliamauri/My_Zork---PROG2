#include <stdio.h>
#include "rooms.h"

void Rooms::Desc() const
{
	printf("%s\n\n", name.c_str());
	printf("Description:\n%s\n\n", desc.c_str());
}

void Rooms::DescExit() const
{
	printf("Next room:\n%s\n\n", descexit.c_str());
}