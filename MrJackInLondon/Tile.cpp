#include "pch.h"
#include "Tile.h"

Tile::Tile(int x, int y, int z, int type, int valid) : i_type(type), i_array_Position{ x, y, z }
{
	Tile::i_valid = valid;
}