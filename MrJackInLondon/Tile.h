#pragma once
class CTile
{
public:
	/*
	const int i_valid;
	const int i_num;
	const int i_type;
	*/
	CTile();
	CTile(int pos, int type, int valid);
	CPoint p_tilepos;
	int i_valid_m, i_num_m, i_type_m;
	/*
	type 0 ��ֹ�
	type 1 �Ϲ� Ÿ��(��)
	type 2 ������
	type 3 ��Ȧ
	type 4 �˹���
	*/
	int i_Item_on;
	/*
	0 nothing
	1 Lamp
	2 Manhole
	3 Shelock
	4 Watson
	5 Smith
	6 Lestrade
	7 Stealthy
	8 William
	9 Goodley
	10 Jeremy
	ex1) manhole & Smith = 52
	ex2) manhole & Jeremy = 102
	*/
	void setTile(CPoint pos_2d, int type, int valid);
	void setItem(int value) {
		this->i_Item_on = value;
	}
};
