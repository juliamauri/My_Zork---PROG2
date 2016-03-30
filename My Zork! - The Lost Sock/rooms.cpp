#include <stdio.h>
#include "rooms.h"

void Rooms::Desc() const{
	printf("%s\n\n", name);
	printf("Description:\n%s\n\n", desc);
}

void Rooms::DescExit() const{
	printf("Next room:\n%s\n\n", descexit);
}

short Rooms::DirNum(char dir)const{

	switch (dir)
	{
	case 'n':
		return n;
		break;
	case 's':
		return s;
		break;
	case 'e':
		return e;
		break;
	case 'w':
		return w;
		break;
	}
}