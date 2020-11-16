#pragma once
class Tile
{
public:
	int i_valid;
	const int i_array_Position[3];
	const int i_type;
	Tile(int x, int y, int z, int type, int valid);
	/*
	type 1 장애물
	type 2 일반 블록
	type 3 가스등
	type 4 맨홀
	type 5 검문소
	*/
};
