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
	int whoWin = -1;						// 누가 이겼는가? 게임의 종료상태를 갖는다. -1이면 아무도 이기지 않은상태. 0이면 Jack 유저, 1이면 수사관 유저의 승리
	int selectedCard[8] = { 0, 0 };			// 뽑힌 카드는 1로 표현
	int RoundTurn[2] = { 1, 1 };				// round, turn 알려주는 배열( [0] : round, [1] : turn )

	int usedCard[8] = { 0,0 };				// 게임에서 사용된 카드: 선택된 카드(1) 알려줌. 
	bool JackState = true;					// 잭의 상태,  우선 '빛에 있다' 가정하고 시작
	Characters jack;						// 어떤 캐릭터가 잭인지

	/// <summary>
	/// 캐릭터들의 정보
	/// Ccharacter 타입이기때문에 charaInfo[캐릭터 열거형 번호].멤버 변수로 젒근할 수 있다
	/// 서버의 CCharacter에는 x, y, inno만 저장된다.
	/// </summary>
	Chara charaInfo[8];

	GameData();
	~GameData();

	void randomCard();					// 홀수라운드마다 캐릭터 카드 4장 뽑는 함수 
	void remainCard();					//	짝수라운드일 때 나머지 카드 4장 뽑는 함수
	void set_Jack();					// 게임 시작 시 Jack을 랜덤으로 뽑아야한다


	/// <summary>
	/// 라운드와 턴 정보를 업데이트 하는 함수
	/// </summary>
	/// <returns></returns>
	void InfoGameRound();
	int check_user();					// 잭 차례인지 수사관 차례인지 알려주는 함수

	Map tile[113];
	Map manhole[8];
	Map lamp[6];
};
