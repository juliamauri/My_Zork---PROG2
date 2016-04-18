#ifndef __stats__
#define __stats__

class Stats
{
public:
	int attack;
	int defense;
	int hp;

public:
	Stats(int attack, int defense, int hp) : attack(attack), defense(defense), hp(hp){};
	~Stats(){};
};

#endif //__stats__