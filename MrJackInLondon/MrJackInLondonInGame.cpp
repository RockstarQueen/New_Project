﻿// MrJackInLondonInGame_T.cpp: 구현 파일
//
#include <math.h>
#include <time.h>
#include "pch.h"
#include "MrJackInLondon.h"
#include "MrJackInLondonInGame.h"
#include "afxdialogex.h"
#include "MrJackInLondonHTP.h"
#include "MrJackInLondonSetting.h"
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


CGoodley goodley;
CShelock homes;
CJeremy jeremy;
CLestrade lestrade;
CSmith john;
CStealthy stealthy;
CWatson watson;
CWilliam william;

// MrJackInLondonInGame_T 대화 상자

IMPLEMENT_DYNAMIC(CMrJackInLondonInGame, CDialogEx)

CMrJackInLondonInGame::CMrJackInLondonInGame(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_InGame, pParent)
{ 
	
	i_Button_pressed_after = 0;
	i_Button_pressed_before = 0;
	//제작:이화원 탈출하는 위치& 타일의 판정을 Rect배열로 구현함. 
	Escape_route[0].SetRect(15, 15, 120, 80);
	Escape_route[1].SetRect(605, 15, 680, 80);
	Escape_route[2].SetRect(15, 490, 120, 560);
	Escape_route[3].SetRect(605, 490, 680, 560);

	for (int i = 1; i < 7; i++) {
		rect[i].SetRect(30, 52 + 58 * i, 75, 107 + 58 * i);
	}
	for (int i = 10; i < 17; i++) {
		int k = i - 10;
		rect[i].SetRect(80, 80 + 58 * k, 125, 135 + 58 * k);
	}
	for (int i = 17; i < 25; i++) {
		int k = i - 17;
		rect[i].SetRect(130, 52 + 58 * k, 175, 107 + 58 * k);
	}
	for (int i = 25; i < 34; i++) {
		int k = i - 25;
		rect[i].SetRect(180, 22 + 58 * k, 225, 77 + 58 * k);
	}
	for (int i = 34; i < 42; i++) {
		int k = i - 34;
		rect[i].SetRect(230, 52 + 58 * k, 275, 107 + 58 * k);
	}
	for (int i = 42; i < 51; i++) {
		int k = i - 42;
		rect[i].SetRect(280, 22 + 58 * k, 325, 77 + 58 * k);
	}
	for (int i = 51; i < 59; i++) {
		int k = i - 51;
		rect[i].SetRect(330, 52 + 58 * k, 375, 107 + 58 * k);
	}
	for (int i = 59; i < 68; i++) {
		int k = i - 59;
		rect[i].SetRect(380, 22 + 58 * k, 425, 77 + 58 * k);
	}
	for (int i = 68; i < 76; i++) {
		int k = i - 68;
		rect[i].SetRect(430, 52 + 58 * k, 475, 107 + 58 * k);
	}
	for (int i = 76; i < 85; i++) {
		int k = i - 76;
		rect[i].SetRect(480, 22 + 58 * k, 525, 77 + 58 * k);
	}
	for (int i = 85; i < 93; i++) {
		int k = i - 85;
		rect[i].SetRect(530, 52 + 58 * k, 575, 107 + 58 * k);
	}
	for (int i = 94; i < 101; i++) {
		int k = i - 94;
		rect[i].SetRect(580, 80 + 58 * k, 625, 135 + 58 * k);
	}
	for (int i = 103; i < 109; i++) {
		int k = i - 103;
		rect[i].SetRect(630, 110 + 58 * k, 675, 165 + 58 * k);
	}
}

CMrJackInLondonInGame::~CMrJackInLondonInGame()
{
	m_png_Light_1.Destroy();
}

void CMrJackInLondonInGame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_SETTING, m_button_Setting);
	DDX_Control(pDX, IDC_IGB_HELP, m_button_Help);
	DDX_Control(pDX, IDC_IGB_TURNEND, m_button_TurnEnd);
}


BEGIN_MESSAGE_MAP(CMrJackInLondonInGame, CDialogEx)
	ON_WM_GETMINMAXINFO()
	ON_BN_CLICKED(IDC_IGB_HELP, &CMrJackInLondonInGame::OnBnClickedIgbHelp)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_SETTING, &CMrJackInLondonInGame::OnBnClickedButtonSetting)
//	ON_WM_MOUSEMOVE()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// MrJackInLondonInGame_T 메시지 처리기


void CMrJackInLondonInGame::OnGetMinMaxInfo(MINMAXINFO* lpMMI2)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	lpMMI2->ptMinTrackSize.x = 1800;
	lpMMI2->ptMinTrackSize.y = 1132;

	lpMMI2->ptMaxTrackSize.x = 1800;
	lpMMI2->ptMaxTrackSize.y = 1132;
	CDialogEx::OnGetMinMaxInfo(lpMMI2);
}


BOOL CMrJackInLondonInGame::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_bitmap_map.LoadBitmap(IDB_BITMAP_MAP);
	m_button_Setting.LoadBitmaps(IDB_BITMAP_BT_SETTING_DEF, IDB_BITMAP_BT_SETTING_ON, NULL, NULL);
	m_button_Setting.SizeToContent();
	m_png_Light_1.Load(L"res\\StreetLamp.png");
	m_png_Light_2.Load(L"res\\StreetLamp1.png");
	m_png_Light_3.Load(L"res\\StreetLamp2.png");
	m_png_Light_4.Load(L"res\\StreetLamp3.png");
	m_png_Light_5.Load(L"res\\StreetLamp4.png");

	m_png_Goodley.Load(L"res\\Goodley-suspicious.png");
	m_png_Homes.Load(L"res\\Homes-suspicious.png");
	m_png_Jeremy.Load(L"res\\Jeremy-suspicious.png");
	m_png_John.Load(L"res\\John-suspicious.png");
	m_png_Lestrade.Load(L"res\\Lestrade-suspicious.png");
	m_png_Stealthy.Load(L"res\\Stealthy-suspicious.png");
	m_png_William.Load(L"res\\William-suspicious.png");
	m_png_Watson.Load(L"res\\Watson-suspicious.png");

	m_png_CheckPoint1.Load(L"res\\CheckPoint.png");
	m_png_etile.Load(L"res\\empty_tile.png");
	m_png_Light_Map.Load(L"res\\able_to_go.png");
	m_png_Manhole_Closed.Load(L"res\\Manhole_Closed.png");
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
	
}


void CMrJackInLondonInGame::OnBnClickedIgbHelp()
{
	CMrJackInLondonRule dialogHTP;
	dialogHTP.DoModal();
	//TCHAR path[_MAX_PATH];

	/*
	GetModuleFileName(NULL, path, sizeof path);
	CString strpath = path;
	int i = strpath.ReverseFind('\\');
	strpath = strpath.Left(i);
	CString realpath = strpath + "/HTP.pdf";
	ShellExecute(NULL, _T("open"), _T("MicrosoftEDGE.EXE"), realpath, NULL, SW_SHOW);
	*/
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMrJackInLondonInGame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	CDC m_dc;
	BITMAP bmpInfo;
	m_dc.CreateCompatibleDC(&dc);
	CBitmap* pOldBmp = NULL;
	m_bitmap_map.GetBitmap(&bmpInfo);
	pOldBmp = m_dc.SelectObject(&m_bitmap_map);
	dc.BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &m_dc, 0, 0, SRCCOPY);
	m_button_Setting.LoadBitmaps(IDB_BITMAP_BT_SETTING_DEF, IDB_BITMAP_BT_SETTING_ON, NULL, NULL);
	m_button_Setting.SizeToContent();
	m_button_TurnEnd.LoadBitmaps(IDB_BITMAP_BT_TURNEND_DEF, IDB_BITMAP_BT_TURNEND_ON, NULL, NULL);
	m_button_TurnEnd.SizeToContent();
	m_button_Help.LoadBitmaps(IDB_BITMAP_BT_INGAMERULE_DEF, IDB_BITMAP_BT_INGAMERULE_ON, NULL, NULL);
	m_button_Help.SizeToContent();
	//m_png_Light_1.Draw(dc, 71, 81);//현재 테스트 상태, 나중에 Lamp1으로 교체
	//m_png_Goodley.Draw(dc, 82, 90);
	//m_png_CheckPoint1.Draw(dc, 10, 25);
	m_png_Manhole_Closed.Draw(dc, 70 + 50 * 4, 81 + 2 * 58);
	//m_png_Goodley.Draw(dc, 32 + 50 * 12, 37 + 58 * 4 - 35);
	
	//등대 초기 구현.
	m_png_Light_1.Draw(dc, 71 + 50 * 4, 81 + 4 * 58);
	m_png_Light_1.Draw(dc, 71 + 50 * 6, 81 + 2 * 58);
	m_png_Light_2.Draw(dc, 70 + 50 * 0, 81 + 5 * 58);
	m_png_Light_3.Draw(dc, 73 + 50 * 10, 81 + 1 * 58);
	m_png_Light_4.Draw(dc, 71 + 50 * 1, 81 + 1 * 58-29);
	m_png_Light_5.Draw(dc, 71 + 50 * 9, 81 + 6 * 58 - 29);
	
	if ((i_Button_pressed_before == 3) && i_Button_pressed_after == 4) {
		m_png_Goodley.Draw(dc, 32 + 50 * 0, 37 + 58 * 4 + 20);
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	
	if ((i_Button_pressed_before == 3) && i_Button_pressed_after == 4) {
		m_png_Goodley.Draw(dc, 32 + 50 * 0, 37 + 58 * 4 + 20);
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	if ((i_Button_pressed_before == 3) && i_Button_pressed_after == 2) {
		m_png_Goodley.Draw(dc, 32 + 50 * 0, 37 + 58 * 2 + 20);
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	if ((i_Button_pressed_before == 2 || i_Button_pressed_before == 4) && i_Button_pressed_after == 3) {
		goodley.Move(0, 3);
		m_png_Goodley.Draw(dc, 32 + 50 * goodley.GetXPos(), 37 + 58 * goodley.GetYPos() + 20);
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	if ((i_Button_pressed_before == 1 || i_Button_pressed_before == 3) && i_Button_pressed_after == 4) {
		m_png_Goodley.Draw(dc, 32 + 50 * 0, 37 + 58 * 3 + 20);
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	if ((i_Button_pressed_before == 75 || i_Button_pressed_before == 73) && i_Button_pressed_after == 74) {
		
		stealthy.Move(8, 6);
		m_png_etile.Draw(dc, 32 + 50 * 8, 37 + 58 * 8 - 35);
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	else if (i_Button_pressed_before == 2) {
		
		m_png_Goodley.Draw(dc, 32 + 50 * goodley.GetXPos(), 37 + 58 * goodley.GetYPos() +20);
		m_png_Light_Map.Draw(dc, 70 + 50 * 0, 81 + 1 * 58 );
		m_png_Light_Map.Draw(dc, 70 + 50 * 4, 81 + -1 * 58);
		m_png_Light_Map.Draw(dc, 70 + 50 * 6, 81 + 7 * 58);
		m_png_Light_Map.Draw(dc, 70 + 50 * 6, 81 + 4 * 58);
		m_png_Light_Map.Draw(dc, 70 + 50 * 10, 81 + 0 * 58);
		m_png_Light_Map.Draw(dc, 70 + 50 * 11, 81 + 4 * 58 - 30);
		m_png_Light_Map.Draw(dc, 70 + 50 * -1, 81 + 3 * 58 - 30);
		m_png_Light_Map.Draw(dc, 70 + 50 * 1, 81 + 6 * 58 - 30);
	}
	else if (i_Button_pressed_before == 3) {
		m_png_Goodley.Draw(dc, 32 + 50 * 0, 37 + 58 * 3 + 20);
		m_png_Light_Map.Draw(dc, 65 + 50 * -1, 81 + 2 * 58 - 30);
		m_png_Light_Map.Draw(dc, 65 + 50 * -1, 81 + 4 * 58 - 30);
	}
	else if (i_Button_pressed_before == 4) {
		m_png_Goodley.Draw(dc, 32 + 50 * 0, 37 + 58 * 4 + 20);
		m_png_Light_Map.Draw(dc, 65 + 50 * -1, 81 + 3 * 58 - 30);
		m_png_Light_Map.Draw(dc, 65 + 50 * -1, 81 + 5 * 58 - 30);
	}
	else if (i_Button_pressed_before == 75) {
		m_png_Stealthy.Draw(dc, 32 + 50 * 8, 37 + 58 * 8 - 35);
		m_png_Light_Map.Draw(dc, 70 + 50 * 7, 81 + 6 * 58 - 30);
		m_png_Light_Map.Draw(dc, 70 + 50 * 6, 81 + 7 * 58);
	}
	else if (i_Button_pressed_before == 74) {
		m_png_Stealthy.Draw(dc, 32 + 50 * 8, 37 + 58 * 7 - 35);
		m_png_Light_Map.Draw(dc, 70 + 50 * 7, 81 + 5 * 58 - 30);
		m_png_Light_Map.Draw(dc, 70 + 50 * 7, 81 + 7 * 58 - 30);
	}
	else {
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	if (goodley.GetXPos() % 2 == 0) {
		m_png_Goodley.Draw(dc, 32 + 50 * goodley.GetXPos(), 95 + 58 * goodley.GetYPos() - 35);
	}
	else if (goodley.GetXPos() % 2 != 0) {
		m_png_Goodley.Draw(dc, 32 + 50 * goodley.GetXPos(), 95 + 58 * goodley.GetYPos() - 65);
	}
	if (homes.GetXPos() % 2 == 0) {
		m_png_Homes.Draw(dc, 32 + 50 * homes.GetXPos(), 95 + 58 * homes.GetYPos() - 35);
	}
	else if (goodley.GetXPos() % 2 != 0) {
		m_png_Homes.Draw(dc, 32 + 50 * homes.GetXPos(), 95 + 58 * homes.GetYPos() - 65);
	}
	if (jeremy.GetXPos() % 2 == 0) {
		m_png_Jeremy.Draw(dc, 32 + 50 * jeremy.GetXPos(), 95 + 58 * jeremy.GetYPos() - 35);
	}
	else if (jeremy.GetXPos() % 2 != 0) {
		m_png_Jeremy.Draw(dc, 32 + 50 * jeremy.GetXPos(), 95 + 58 * jeremy.GetYPos() - 65);
	}
	if (john.GetXPos() % 2 == 0) {
		m_png_John.Draw(dc, 32 + 50 * john.GetXPos(), 95 + 58 * john.GetYPos() - 35);
	}
	else if (john.GetXPos() % 2 != 0) {
		m_png_John.Draw(dc, 32 + 50 * john.GetXPos(), 95 + 58 * john.GetYPos() - 65);
	}
	if (lestrade.GetXPos() % 2 == 0) {
		m_png_Lestrade.Draw(dc, 32 + 50 * lestrade.GetXPos(), 95 + 58 * lestrade.GetYPos() - 35);
	}
	else if (lestrade.GetXPos() % 2 != 0) {
		m_png_Lestrade.Draw(dc, 32 + 50 * lestrade.GetXPos(), 95 + 58 * lestrade.GetYPos() - 65);
	}
	if (stealthy.GetXPos() % 2 == 0) {
		m_png_Stealthy.Draw(dc, 32 + 50 * stealthy.GetXPos(), 95 + 58 * stealthy.GetYPos() - 35);
	}
	else if (stealthy.GetXPos() % 2 != 0) {
		m_png_Stealthy.Draw(dc, 32 + 50 * stealthy.GetXPos(), 95 + 58 * stealthy.GetYPos() - 65);
	}
	if (watson.GetXPos() % 2 == 0) {
		m_png_Watson.Draw(dc, 32 + 50 * watson.GetXPos(), 95 + 58 * watson.GetYPos() - 35);
	}
	else if (watson.GetXPos() % 2 != 0) {
		m_png_Watson.Draw(dc, 32 + 50 * watson.GetXPos(), 95 + 58 * watson.GetYPos() - 65);
	}
	if (william.GetXPos() % 2 == 0) {
		m_png_William.Draw(dc, 32 + 50 * william.GetXPos(), 95 + 58 * william.GetYPos() - 35);
	}
	else if (william.GetXPos() % 2 != 0) {
		m_png_William.Draw(dc, 32 + 50 * william.GetXPos(), 95 + 58 * william.GetYPos() - 65);
	}
	
	
	
	
	
	
	//탈출경로와 타일 판정위치 표시하는 것임. 하단에 있는것을 주석처리하면 나타나지 않음. 
	/*
	for(int i=0;i<109;i++)
		dc.Rectangle(rect[i]);
	for (int i = 0; i < 4; i++) {
		dc.Rectangle(Escape_route[i]);
	}
	*/
	
	//m_png_Light_1.Draw(dc, 0, 0);
}


void CMrJackInLondonInGame::OnBnClickedButtonSetting()
{
	CMrJackInLondonSetting dialogset;
	dialogset.DoModal();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


//void MrJackInLondonInGame::OnMouseMove(UINT nFlags, CPoint point)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	CClientDC dc(this);
//	CString temp;
//	temp.Format("X= %4d, Y= %4d", m_pos.x, m_pos.y);
//	m_pos = point;
//	CDialogEx::OnMouseMove(nFlags, point);
//}


void CMrJackInLondonInGame::OnLButtonDown(UINT nFlags, CPoint point)
{
	CString msg;
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//타일 안에 있으면 반응하게 하는 함수. 주석 처리시 발생안함. lhw. <<현재 i값을 못불러옴. 마우스의 x좌표로 불러오는 문제가 보임. 수정 바람(20201120)
	/*
	for (int i = 0; i < 109; i++) {
		if (rect[i].PtInRect(point)) {
			MessageBox(_T("사각형 안에 있어용"));
		}
	}
	*/
	

	msg.Format(_T("값: %d, %d"), stealthy.GetXPos(), stealthy.GetYPos());
	MessageBox(msg);
	for (int i = 1; i < 109; i++) {
		if (rect[i].PtInRect(point) && i_Button_pressed_before == 0) {
			i_Button_pressed_before = i;
			Invalidate();
		}
		else if (rect[i].PtInRect(point) && i_Button_pressed_before != 0) {
			i_Button_pressed_after = i;
			Invalidate();
		}
	}
	for (int j = 0; j < 4; j++) {
		if (Escape_route[j].PtInRect(point)) {
			msg = j+"번째 안에 있다.";
			AfxMessageBox(msg);
		}
	}
	/*
	if (point.x >= rect[i].left && point.y >= rect[i].top && point.x <= rect[i].right && point.y <= rect[i].bottom) {
		MessageBox(_T("제발.."));
	}
	else {
		MessageBox(_T("다행이다"));
	}
	*/
	
	CDialogEx::OnLButtonDown(nFlags, point);
}


int CMrJackInLondonInGame::set_Jack()
{
	srand((unsigned int)time(NULL));
	int rand_pick=(rand()%8)+1;

	// TODO: 여기에 구현 코드 추가.
	return 0;
}
