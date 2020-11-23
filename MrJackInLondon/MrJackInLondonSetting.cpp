// MrJackInLondonSetting.cpp: 구현 파일
//

#include "pch.h"
#include "MrJackInLondon.h"
#include "MrJackInLondonSetting.h"
#include "afxdialogex.h"


// MrJackInLondonSetting 대화 상자

IMPLEMENT_DYNAMIC(CMrJackInLondonSetting, CDialogEx)

CMrJackInLondonSetting::CMrJackInLondonSetting(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_Setting, pParent)
{

}

CMrJackInLondonSetting::~CMrJackInLondonSetting()
{
}

void CMrJackInLondonSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMrJackInLondonSetting, CDialogEx)
END_MESSAGE_MAP()


// MrJackInLondonSetting 메시지 처리기
