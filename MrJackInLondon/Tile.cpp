#include "pch.h"
#include "Tile.h"

CTile::CTile(int x, int y, int z, int type, int valid) : i_type(type), i_array_Position{ x, y, z }
{
	CTile::i_valid = valid;
}