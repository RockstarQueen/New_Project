// MrJackInLondonInGame_T.cpp: 구현 파일
//

#include "pch.h"
#include "MrJackInLondon.h"
#include "MrJackInLondonInGame_T.h"
#include "afxdialogex.h"


// MrJackInLondonInGame_T 대화 상자

IMPLEMENT_DYNAMIC(MrJackInLondonInGame_T, CDialogEx)

MrJackInLondonInGame_T::MrJackInLondonInGame_T(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_InGame, pParent)
{

}

MrJackInLondonInGame_T::~MrJackInLondonInGame_T()
{
}

void MrJackInLondonInGame_T::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MrJackInLondonInGame_T, CDialogEx)
END_MESSAGE_MAP()


// MrJackInLondonInGame_T 메시지 처리기
