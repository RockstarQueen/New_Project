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
#include "GameData.h"
#include "Client.h"

// MrJackInLondonInGame_T 대화 상자

class CMrJackInLondonInGame : public CDialogEx
{
	DECLARE_DYNAMIC(CMrJackInLondonInGame)

public:
	CClient clsock;
	CMrJackInLondonInGame(CWnd* pParent/* = nullptr*/, CClient* tempsock);   // 표준 생성자입니다.
	virtual ~CMrJackInLondonInGame();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_InGame };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	CPoint m_pos;
	CRect rect[113];
	CRect Escape_route[4];
	CTile tile[113];
	CTile manhole[8];
	CTile lamp[6];
public:
	static UINT ThreadFunc(LPVOID lpVoid);
	SOCKET rsock;
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedIgbHelp();
	class Tile;
	
	CBitmapButton m_button_Setting;
	CBitmapButton m_button_Help;
	CBitmapButton m_button_TurnEnd;
	CBitmapButton m_button_MoveEnd;
	afx_msg void OnPaint();
	
	CBitmap m_bitmap_map;
	CImage m_png_Light_0;
	CImage m_png_Light_1;
	CImage m_png_Light_2;
	CImage m_png_Light_3;
	CImage m_png_Light_4;
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
	CImage m_png_Goodley_s;
	CImage m_png_Stealthy_s;
	CImage m_png_Homes_s;
	CImage m_png_Jeremy_s;
	CImage m_png_John_s;
	CImage m_png_Lestrade_s;
	CImage m_png_Watson_s;
	CImage m_png_William_s;

	CImage m_png_Goodley_i;
	CImage m_png_Stealthy_i;
	CImage m_png_Homes_i;
	CImage m_png_Jeremy_i;
	CImage m_png_John_i;
	CImage m_png_Lestrade_i;
	CImage m_png_Watson_i;
	CImage m_png_William_i;

	CImage m_png_CheckPoint;
	CImage m_png_Light_Map;
	CImage m_png_Manhole_Closed;
	CImage m_png_Light_CheckPoint;
	//CTile m_Tile[110] = {CTile(0,0,0), CTile()};
	int i_Button_pressed_before;
	int i_Button_pressed_after;
	int i_round=1;
	int i_player_num;
	/// <summary>
	/// 잭을 정하는 함수(서버에서 이미 구현함)
	/// </summary>
	/// <returns></returns>
	int set_Jack();

	// 잭인 캐릭터 이름
	CString s_is_jack;
	CString s_not_jack;

	afx_msg void OnBnClickedIgbTurnend();
	void round_start();
	void round_end();
	void turn_end();
	int checkchar1dPos(int index);
	afx_msg void OnBnClickedButtonMoveend();
	afx_msg void OnDestroy();
	void characterMove();
	
	
};
