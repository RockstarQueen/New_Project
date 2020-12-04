#include <iostream>
#include <ctime>
#pragma once
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
class GameData
{
public:

	int selectedCard[8] = { 0, 0 };			// ���� ī��� 1�� ǥ��
	int RoundTurn[2] = { 1,0 };				// round, turn �˷��ִ� �迭( [0] : round, [1] : turn )

	int usedCard[8] = { 0,0 };				// ���ӿ��� ���� ī��: ���õ� ī��(1) �˷���. 
	bool JackState = true;					// ���� ����,  �켱 '���� �ִ�' �����ϰ� ����
	Characters jack;						// � ĳ���Ͱ� ������

	GameData();
	~GameData();

	void randomCard();					// Ȧ�����帶�� ĳ���� ī�� 4�� �̴� �Լ� 
	void remainCard();					//	¦�������� �� ������ ī�� 4�� �̴� �Լ�
	// void set_Jack();					// ���� ���� �� Jack�� �������� �̾ƾ��Ѵ�
	
	/// <summary>
	/// ����� �� ������ ������Ʈ �ϴ� �Լ�
	/// </summary>
	/// <returns></returns>
	void InfoGameRound() {

		if (this->RoundTurn[1] < 4) {
			this->RoundTurn[0]++;
		}
		else {
			this->RoundTurn[0]++;
			this->RoundTurn[1] = 1;
		}
	}									// turn ���۸��� round, turn �˷��ִ� �Լ�(��ü ���� ���۽ÿ��� ����)
	int check_user();					// �� �������� ����� �������� �˷��ִ� �Լ�
	void update_Jack();					// ���� ���� �ִ���, ��ҿ� �ִ��� Ȯ���ؼ� JackState�� �����ϴ� �Լ�
	bool light_character(int);

	/*
	�߰��� �����ؾ� �� ��
	ĳ����, ���ε�, ��Ȧ, ������ ��ġ(+ �ӽ� ������ ����)
	ĳ���� innocent
	*/

	/// <summary>
	/// ĳ���͵��� ��ġ, 0~7���� ���� �������� ����
	/// [][0]�� x��, [][1]�� y���� �ǹ�
	/// </summary>
	int characterPosition[8][2];

	/// <summary>
	/// ĳ���͵��� ���� ��ġ�ϴ����� ����
	/// ó���� ��� ĳ���͵��� true�� �����Ǿ�����
	/// </summary>
	bool characterState[8] = { true, true, true, true, true, true, true, true };
	bool characterInnocent[8] = { true, true, true, true, true, true, true, true };
};
