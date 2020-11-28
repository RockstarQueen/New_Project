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
	CCharacter();
	bool GetInno();
	int GetXPos();
	int GetYPos();
	void Moveable();
	void Move(int xpos, int ypos);
	int GetPos();

protected:
	CPoint p_charpos;
	bool b_innocent;
	int i_position;
	int i_xposition;
	int i_yposition;
	int i_array_check[6] = { 0,0 };
};

