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
	void Move(CPoint dest_pos);
	int GetPos();
	int move_count;
	bool b_jack;
protected:
	CPoint p_charpos;
	bool b_innocent=FALSE;
	int i_position;
	int i_xposition;
	int i_yposition;
	int i_array_check[6] = { 0,0 };
public:
	void setInno();
};

