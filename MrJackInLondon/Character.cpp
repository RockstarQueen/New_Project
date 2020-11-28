#include "pch.h"
#include "Character.h"
CCharacter::CCharacter() {
	b_innocent = 0;
}
int CCharacter::GetXPos() {
	
	return this->p_charpos.x;
}
int CCharacter::GetYPos() {
	return this->p_charpos.y;
}

int CCharacter::GetPos() {
	return this->i_position;
}
void CCharacter::Moveable() {
	int now_xpos;
	int now_ypos;
	CPoint a;
	a.x = this->GetXPos();
	a.y = this->GetYPos();
	
	
	if (a.x != 0 && a.x != 11 && a.y != 0 && a.y != 11) {

	}
	
}
void CCharacter::Move(int xpos, int ypos) {
	this->p_charpos.x = xpos;
	this->p_charpos.y = ypos;
}
bool CCharacter::GetInno() {
	return this->b_innocent;
}