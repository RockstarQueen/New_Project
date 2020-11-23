#pragma once
class CCharacter
{
public:

	enum Characters
	{
		Shelock = 0,
		Watson,
		Smith,
		Lestrade,
		Stealthy,
		Goodley,
		William,
		Jeremy
	};
	
	bool GetInno();
	int GetPos();
	void Moveable();
	void Move();

protected:
	bool b_innocent;
	int i_position;
	int i_array_check[6] = { 0,0 };
};

