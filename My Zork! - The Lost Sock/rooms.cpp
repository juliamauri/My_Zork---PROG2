#include <stdio.h>
#include "rooms.h"

void Rooms::Desc() const
{
	printf("%s\n\n", name);
	printf("Description:\n%s\n\n", desc);
}

void Rooms::DescExit() const
{
	printf("Next room:\n%s\n\n", descexit);
}