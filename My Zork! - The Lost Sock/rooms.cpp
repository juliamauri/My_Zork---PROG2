#include <stdio.h>
#include "rooms.h"

void Rooms::Desc(){
	printf("%s\n\n", name);
	printf("Description:\n%s\n\n", desc);
}

void Rooms::DescExit(){
	printf("Next room:\n%s\n\n", descexit);
}