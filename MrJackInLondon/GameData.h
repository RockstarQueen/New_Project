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

	int selectedCard[8] = { 0, 0 };			// 뽑힌 카드는 1로 표현
	int RoundTurn[2] = { 1,0 };				// round, turn 알려주는 배열( [0] : round, [1] : turn )

	int usedCard[8] = { 0,0 };				// 게임에서 사용된 카드: 선택된 카드(1) 알려줌. 
	bool JackState = true;					// 잭의 상태,  우선 '빛에 있다' 가정하고 시작
	Characters jack;						// 어떤 캐릭터가 잭인지

	GameData();
	~GameData();

	void randomCard();					// 홀수라운드마다 캐릭터 카드 4장 뽑는 함수 
	void remainCard();					//	짝수라운드일 때 나머지 카드 4장 뽑는 함수
	// void set_Jack();					// 게임 시작 시 Jack을 랜덤으로 뽑아야한다
	
	/// <summary>
	/// 라운드와 턴 정보를 업데이트 하는 함수
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
	}									// turn 시작마다 round, turn 알려주는 함수(전체 게임 시작시에도 실행)
	int check_user();					// 잭 차례인지 수사관 차례인지 알려주는 함수
	void update_Jack();					// 잭이 빛에 있는지, 어둠에 있는지 확인해서 JackState를 세팅하는 함수
	bool light_character(int);

	/*
	추가로 구현해야 할 것
	캐릭터, 가로등, 맨홀, 손전등 위치(+ 왓슨 손전등 방향)
	캐릭터 innocent
	*/

	/// <summary>
	/// 캐릭터들의 위치, 0~7까지 각각 열거형과 동일
	/// [][0]은 x축, [][1]은 y축을 의미
	/// </summary>
	int characterPosition[8][2];

	/// <summary>
	/// 캐릭터들이 빛에 위치하는지의 여부
	/// 처음에 모든 캐릭터들은 true로 설정되어있음
	/// </summary>
	bool characterState[8] = { true, true, true, true, true, true, true, true };
	bool characterInnocent[8] = { true, true, true, true, true, true, true, true };
};
