#include "ListenSocket.h"
// MrJackInLondonDlg.h: 헤더 파일
//

#pragma once


// CMrJackInLondonDlg 대화 상자
class CMrJackInLondonDlg : public CDialogEx
{
// 생성입니다.
public:
	CMrJackInLondonDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	CListenSocket m_ListenSocket;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MRJACKINLONDON_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CImage m_png_image_of_Main;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CRect rectCtl;
	CWnd* pCt1;
	float f_image_width_Main;
	float f_image_height_Main;
	float f_rect_rate_Main;
	float f_image_rate_Main;
	int i_priority_range_Main;
	afx_msg void OnBnClickedBtStart();
	afx_msg void OnBnClickedBtHtp();
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	CBitmapButton m_png_button_Rule;
	CBitmapButton m_png_button_Play;
};
