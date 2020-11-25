#include "pch.h"
#include "Tile.h"

CTile::CTile(int num, int type, int valid) : i_type(type), i_num(num), i_valid(valid)
{
	i_Item_on = 0;
	i_xpos = 0;
	i_ypos = 0;
}