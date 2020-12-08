#include <iostream>
#include <ctime>
#pragma once

class Chara
{
public:
	int x;
	int y;
	bool inno;
};

class Map
{
public:
	bool b_lamp_on;
	bool b_checkpoint_on;
	bool b_manhole_on;
	int x, y;
	int i_Item_on;
	int i_default_item;
};

enum Characters :int
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

class GameData
{
public:
	int whoWin = -1;						// ���� �̰�°�? ������ ������¸� ���´�. -1�̸� �ƹ��� �̱��� ��������. 0�̸� Jack ����, 1�̸� ����� ������ �¸�
	int selectedCard[8] = { 0, 0 };			// ���� ī��� 1�� ǥ��
	int RoundTurn[2] = { 1, 1 };				// round, turn �˷��ִ� �迭( [0] : round, [1] : turn )

	int usedCard[8] = { 0,0 };				// ���ӿ��� ���� ī��: ���õ� ī��(1) �˷���. 
	bool JackState = true;					// ���� ����,  �켱 '���� �ִ�' �����ϰ� ����
	Characters jack;						// � ĳ���Ͱ� ������

	/// <summary>
	/// ĳ���͵��� ����
	/// Ccharacter Ÿ���̱⶧���� charaInfo[ĳ���� ������ ��ȣ].��� ������ ������ �� �ִ�
	/// ������ CCharacter���� x, y, inno�� ����ȴ�.
	/// </summary>
	Chara charaInfo[8];

	GameData();
	~GameData();

	void randomCard();					// Ȧ�����帶�� ĳ���� ī�� 4�� �̴� �Լ� 
	void remainCard();					//	¦�������� �� ������ ī�� 4�� �̴� �Լ�
	void set_Jack();					// ���� ���� �� Jack�� �������� �̾ƾ��Ѵ�


	/// <summary>
	/// ����� �� ������ ������Ʈ �ϴ� �Լ�
	/// </summary>
	/// <returns></returns>
	void InfoGameRound();
	int check_user();					// �� �������� ����� �������� �˷��ִ� �Լ�

	Map tile[113];
	Map manhole[8];
	Map lamp[6];
};
