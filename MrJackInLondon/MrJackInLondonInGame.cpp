// MrJackInLondonInGame.cpp: 구현 파일
//

#include "pch.h"
#include "MrJackInLondon.h"
#include "MrJackInLondonInGame.h"
#include "afxdialogex.h"


// MrJackInLondonInGame 대화 상자

IMPLEMENT_DYNAMIC(MrJackInLondonInGame, CDialogEx)

MrJackInLondonInGame::MrJackInLondonInGame(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GAME, pParent)
{

}

MrJackInLondonInGame::~MrJackInLondonInGame()
{
}

void MrJackInLondonInGame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MrJackInLondonInGame, CDialogEx)
END_MESSAGE_MAP()


// MrJackInLondonInGame 메시지 처리기
