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

void CTile::checkPos() {
	
}

void CTile::swapItem(CTile& old_tile) {
	if (this->i_default_item > 3 && old_tile.i_default_item > 3) {
		this->i_default_item = this->i_default_item * 10 + old_tile.i_default_item;
	}
	else if (this->i_default_item > 11) {
		old_tile.i_default_item = this->i_default_item / 10;
		this->i_default_item = this->i_default_item % 10;
	}
	else {
		int temp = old_tile.i_default_item;
		old_tile.i_default_item = this->i_default_item;
		this->i_default_item = temp;
	}
}