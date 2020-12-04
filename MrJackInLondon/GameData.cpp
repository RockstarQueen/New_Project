#include "pch.h"
#include "GameData.h"

GameData::GameData()
{
}

GameData::~GameData()
{
}


/// <summary>
/// Ȧ�� ���� ������ ��, 8���� ī�� �� �������� 4���� �̴� �Լ�
/// </summary>
void GameData::randomCard() {
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 8; i++) {					// Ȧ�� ���帶�� ��� 0���� �ʱ�ȭ
		this->selectedCard[i] = 0;
	}
	while (1) {
		int n = rand() % 8;
		this->selectedCard[n] = 1;				// ���� ī��� 1�� ǥ��
		int cnt = 0;
		for (int i = 0; i < 8; i++) {
			if (this->selectedCard[i] == 1)
				cnt++;
		}
		if (cnt == 4) {						// ���� ī�� 4�� �� �� ����
			break;
		}
	}
}


/// <summary>
/// Ȧ�� ���忡�� ¦�� ����� �ٲ� ��,
/// �� ���忡�� ������� ���� ī�带 �������ִ� �Լ�
/// </summary>
void GameData::remainCard() {
	for (int i = 0; i < 8; i++) {
		if (this->selectedCard[i] == 1) {
			this->selectedCard[i] = 0;
		}
		else {
			this->selectedCard[i] = 1;
		}
	}
	// Ȧ���϶� 1�� ī�带 0����, 0�� ī�带 1�� �ٲ�!
}

/// <summary>
/// ������ ������ Ȯ���ϴ� �Լ�
/// </summary>
/// <returns>0�̸� ���� ����, 1�̸� ������� ����</returns>
int GameData::check_user() {
	int oddround[4] = { 1, 0, 0, 1 };				// Ȧ�� : �����(1)����
	int evenround[4] = { 0, 1, 1, 0 };				// ¦�� : ��(0)����

	if (this->RoundTurn[0] % 2 == 0) {				// ¦�� ������ ���
		return evenround[this->RoundTurn[1]];
	}
	else {											// Ȧ�� ������ ���
		return oddround[this->RoundTurn[1]];
	}
}


/// <summary>
/// ���� ���� �ִ���, ��ҿ� �ִ��� Ȯ���ؼ� JackState�� �����ϴ� �Լ�
/// </summary>
/// <returns>����</returns>
void GameData::update_Jack() {
	if (light_character(0/*Jack ĳ������ ������ ����*/))
	{
		this->JackState = true;
	}
	else {
		this->JackState = false;
	}
}


/// <summary>
/// �� ĳ���Ͱ� ���� �ִ��� Ȯ���ϴ� �Լ�
/// ���ڷ� ĳ���� ����(������)�� �ִ´�.
/// </summary>
/// <returns>���� ���� ������ true, ��ο� ���� ������ false</returns>
bool GameData::light_character(int character) {
	// TODO: ���ε� ����, �ӽ� ������ ����, ���� ��� ���� Ȯ��
	if (/*���ε� �� || ���� ĳ���� �� || �ӽ� ������ ���� ��*/0) { return true; }
	else return false;
}


/// <summary>
/// 8���� ī�� �� �� ������ ĳ���͸� ���� �����ϴ� �Լ�
/// </summary>
void GameData::set_Jack() {
	srand((unsigned int)time(NULL));
	this->jack = (Characters)(rand() % 8);
}