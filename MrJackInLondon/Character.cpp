#include "pch.h"
#include "Character.h"
CCharacter::CCharacter() {
	/*
	Characters a;
	switch (a) {
	case 1:
		break;
	case 2:
		break;
	}
	*/
	b_innocent = 0;
	i_xposition = 0;
	i_yposition = 0;
}
int CCharacter::GetXPos() {
	
	return this->i_xposition;
}
int CCharacter::GetYPos() {
	return this->i_yposition;
}

int CCharacter::GetPos() {
	return this->i_position;
}
void CCharacter::Moveable() {
	int now_pos;
	now_pos = this->GetPos();
	if (now_pos  > 9&&now_pos<103) {

	}
}
void CCharacter::Move() {
	
}
bool CCharacter::GetInno() {
	return this->b_innocent;
}