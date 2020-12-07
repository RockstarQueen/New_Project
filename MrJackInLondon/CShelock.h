#pragma once
#include "Character.h"
class CShelock :
	public CCharacter
{
public:
	CShelock();
	int ShelockAble();
	int Jack;
	int result[4] = { 0, 0, };
	int num = 0;
};

