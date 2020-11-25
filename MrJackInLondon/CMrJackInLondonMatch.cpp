// CMrJackInLondonMatch.cpp: 구현 파일
//

#include "pch.h"
#include "MrJackInLondon.h"
#include "CMrJackInLondonMatch.h"
#include "afxdialogex.h"
#include <thread>

// CMrJackInLondonMatch 대화 상자

IMPLEMENT_DYNAMIC(CMrJackInLondonMatch, CDialogEx)

CMrJackInLondonMatch::CMrJackInLondonMatch(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MATCHING, pParent)
{

}

CMrJackInLondonMatch::~CMrJackInLondonMatch()
{
}

void CMrJackInLondonMatch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMrJackInLondonMatch, CDialogEx)
END_MESSAGE_MAP()


// CMrJackInLondonMatch 메시지 처리기
void CMrJackInLondonMatch::proc_recv()
{
    // TODO: 여기에 구현 코드 추가.
   
}

BOOL CMrJackInLondonMatch::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}



