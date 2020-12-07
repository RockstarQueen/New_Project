#include "pch.h"
#include "CShelock.h"
#include "CGoodley.h"
#include "Character.h"
#include "CJeremy.h"
#include "CLestrade.h"
#include "CSmith.h"
#include "CStealthy.h"
#include "CWatson.h"
#include "CWilliam.h"

CShelock::CShelock() {

	this->p_charpos.x = 6;
	this->p_charpos.y = 5;
}

int CShelock::ShelockAble()
{
	// TODO: 여기에 구현 코드 추가.
	srand((unsigned int)time(NULL));
	int rand_pick = (rand() % 8)+1;
	while (rand_pick == Jack )
	{
		srand((unsigned int)time(NULL));
		int rand_pick = (rand() % 8) + 1;
		for (int i = 0; i < 4; i++)
		{
			if (result[i] == rand_pick)
				rand_pick = Jack;
		}
	}
	return rand_pick;
}
