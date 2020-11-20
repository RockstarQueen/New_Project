#pragma once


// MrJackInLondonInGame_T 대화 상자

class MrJackInLondonInGame : public CDialogEx
{
	DECLARE_DYNAMIC(MrJackInLondonInGame)

public:
	MrJackInLondonInGame(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~MrJackInLondonInGame();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_InGame };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	CPoint m_pos;
	CRect rect[103];
	CRect Escape_route[4];
public:
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedIgbHelp();
	class Tile;
	
	CBitmapButton m_button_Setting;
	CBitmapButton m_button_Help;
	CBitmapButton m_button_TurnEnd;
	afx_msg void OnPaint();
	
	CBitmap m_bitmap_map;
	CImage m_png_Light_1;
	afx_msg void OnBnClickedButtonSetting();
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
