#include "pch.h"
#include "Tile.h"
/*
CTile::CTile(int num, int type, int valid) : i_type(type), i_num(num), i_valid(valid)
{
	i_Item_on = 0;
}
*/
CTile::CTile() {
	this->i_num_m = 0;
	this->i_type_m = 0;
	this->i_valid_m = 0;
}

void CTile::setTile(CPoint pos_2d, int type, int valid) {
	this->p_tilepos = pos_2d;
	this->i_type_m = type;
	this->i_valid_m = valid;
}