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
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_HTPB_PREV, &MrJackInLondonHTP::OnBnClickedHtpbPrev)
	ON_BN_CLICKED(IDC_HTPB_NEXT, &MrJackInLondonHTP::OnBnClickedHtpbNext)
END_MESSAGE_MAP()


// MrJackInLondonHTP 메시지 처리기


BOOL MrJackInLondonHTP::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	i_page_num = 1;

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void MrJackInLondonHTP::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	if (i_page_num == 1) {
		GetDlgItem(IDC_HTPB_PREV)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_S_P1_T)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_S_P1_N1)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_S_P2_T)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_S_P2_N1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_S_P2_N2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_S_P2_N3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_S_P2_P1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_S_P2_P2)->ShowWindow(SW_HIDE);
	}
	if (i_page_num != 1) {
		GetDlgItem(IDC_HTPB_PREV)->ShowWindow(SW_SHOW);

	}
	if (i_page_num == 2) {
		GetDlgItem(IDC_S_P1_T)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_S_P1_N1)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_S_P2_T)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_S_P2_N1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_S_P2_N2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_S_P2_N3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_S_P2_P1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_S_P2_P2)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_S_P3_T)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_S_P3_N1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_S_P3_N2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_S_P3_N3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_S_P3_P1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_S_P3_P2)->ShowWindow(SW_HIDE);
	}
	if (i_page_num == 3) {
		GetDlgItem(IDC_S_P2_T)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_S_P2_N1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_S_P2_N2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_S_P2_N3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_S_P2_P1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_S_P2_P2)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_S_P3_T)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_S_P3_N1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_S_P3_N2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_S_P3_N3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_S_P3_P1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_S_P3_P2)->ShowWindow(SW_SHOW);
	}
}


void MrJackInLondonHTP::OnBnClickedHtpbPrev()
{
	i_page_num--;
	Invalidate();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void MrJackInLondonHTP::OnBnClickedHtpbNext()
{
	i_page_num++;
	Invalidate();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
