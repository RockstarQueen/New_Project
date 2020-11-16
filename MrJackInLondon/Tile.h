#pragma once
class Tile
{
public:
	int i_valid;
	const int i_array_Position[3];
	const int i_type;
	Tile(int x, int y, int z, int type, int valid);
};
