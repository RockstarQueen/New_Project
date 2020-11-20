// MrJackInLondonSetting.cpp: 구현 파일
//

#include "pch.h"
#include "MrJackInLondon.h"
#include "MrJackInLondonSetting.h"
#include "afxdialogex.h"


// MrJackInLondonSetting 대화 상자

IMPLEMENT_DYNAMIC(MrJackInLondonSetting, CDialogEx)

MrJackInLondonSetting::MrJackInLondonSetting(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_Setting, pParent)
{

}

MrJackInLondonSetting::~MrJackInLondonSetting()
{
}

void MrJackInLondonSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MrJackInLondonSetting, CDialogEx)
END_MESSAGE_MAP()


// MrJackInLondonSetting 메시지 처리기
