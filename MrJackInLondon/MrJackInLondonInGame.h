#pragma once
#include "Tile.h"
#include "CGoodley.h"
#include "CJeremy.h"
#include "CLestrade.h"
#include "CShelock.h"
#include "CStealthy.h"
#include "CSmith.h"
#include "CWatson.h"
#include "CWilliam.h"
#include "Character.h"

// MrJackInLondonInGame_T 대화 상자

class CMrJackInLondonInGame : public CDialogEx
{
	DECLARE_DYNAMIC(CMrJackInLondonInGame)

public:
	CMrJackInLondonInGame(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMrJackInLondonInGame();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_InGame };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	CPoint m_pos;
	CRect rect[109];
	CRect Escape_route[4];
	CTile tile[109];
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
	CImage m_png_Light_2;
	CImage m_png_Light_3;
	CImage m_png_Light_4;
	CImage m_png_Light_5;
	CImage m_png_etile;
	int stealthy_move;
	int goodley_move;

	int move_count;
	CGoodley goodley;
	CShelock homes;
	CJeremy jeremy;
	CLestrade lestrade;
	CSmith john;
	CStealthy stealthy;
	CWatson watson;
	CWilliam william;

	afx_msg void OnBnClickedButtonSetting();
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CImage m_png_Goodley;
	CImage m_png_Stealthy;
	CImage m_png_Homes;
	CImage m_png_Jeremy;
	CImage m_png_John;
	CImage m_png_Lestrade;
	CImage m_png_Watson;
	CImage m_png_William;


	CImage m_png_CheckPoint1;
	CImage m_png_Light_Map;
	CImage m_png_Manhole_Closed;
	//CTile m_Tile[110] = {CTile(0,0,0), CTile()};
	int i_Button_pressed_before;
	int i_Button_pressed_after;
	int i_round=1;
	int i_player_num;
	int set_Jack();
	CString s_is_jack;
	CString s_not_jack;
	afx_msg void OnBnClickedIgbTurnend();
	void round_start();
	void round_end();
	void turn_end();
};
