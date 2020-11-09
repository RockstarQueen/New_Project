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
	ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()


// MrJackInLondonInGame_T 메시지 처리기


void MrJackInLondonInGame_T::OnGetMinMaxInfo(MINMAXINFO* lpMMI2)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	lpMMI2->ptMinTrackSize.x = 1800;
	lpMMI2->ptMinTrackSize.y = 1132;

	lpMMI2->ptMaxTrackSize.x = 1800;
	lpMMI2->ptMaxTrackSize.y = 1132;
	CDialogEx::OnGetMinMaxInfo(lpMMI2);
}
