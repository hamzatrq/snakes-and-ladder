#pragma once
#include <stdlib.h>
#include <ctime>

class dice
{
public:
	dice()
	{
		srand(time(NULL));
	}
	int rolldice()
	{
			return rand() % 6 + 1;
	}
};