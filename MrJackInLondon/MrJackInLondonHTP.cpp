// MrJackInLondonHTP.cpp: 구현 파일
//

#include "pch.h"
#include "MrJackInLondon.h"
#include "MrJackInLondonHTP.h"
#include "afxdialogex.h"


// MrJackInLondonHTP 대화 상자

IMPLEMENT_DYNAMIC(MrJackInLondonHTP, CDialogEx)

MrJackInLondonHTP::MrJackInLondonHTP(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_HTP, pParent)
{
}

MrJackInLondonHTP::~MrJackInLondonHTP()
{
}

void MrJackInLondonHTP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MrJackInLondonHTP, CDialogEx)
END_MESSAGE_MAP()


// MrJackInLondonHTP 메시지 처리기


BOOL MrJackInLondonHTP::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
