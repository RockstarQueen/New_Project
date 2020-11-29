// MrJackInLondonInGame_T.cpp: 구현 파일
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

	tile[0].setTile(CPoint(0,0), 0, 0);
	tile[1].setTile(CPoint(0,1), 0, 0);
	tile[2].setTile(CPoint(0,2), 1, 0);
	tile[3].setTile(CPoint(0,3) , 1, 0);
	tile[4].setTile(CPoint(0,4), 1, 0);
	tile[5].setTile(CPoint(0,5), 1, 0);
	tile[6].setTile(CPoint(0,6), 1, 0);
	tile[7].setTile(CPoint(0,0), 0, 0);
	tile[8].setTile(CPoint(0,0), 0, 0);
	tile[9].setTile(CPoint(1,0), 1, 0);
	tile[10].setTile(CPoint(1,1), 1, 0);
	tile[11].setTile(CPoint(1,2), 0, 0);
	tile[12].setTile(CPoint(1,3), 0, 0);
	tile[13].setTile(CPoint(1,4), 1, 0);
	tile[14].setTile(CPoint(1,5), 2, 0);
	tile[15].setTile(CPoint(1,6), 1, 0);
	tile[16].setTile(CPoint(0,7), 0, 0);
	tile[17].setTile(CPoint(2,0), 0, 0);
	tile[18].setTile(CPoint(2,1), 2, 0);
	tile[19].setTile(CPoint(2,2), 1, 0);
	tile[20].setTile(CPoint(2,3), 0, 0);
	tile[21].setTile(CPoint(2,4), 1, 0);
	tile[22].setTile(CPoint(2,5), 1, 0);
	tile[23].setTile(CPoint(2,6), 1, 0);
	tile[24].setTile(CPoint(2,7), 0, 0);
	tile[25].setTile(CPoint(3,0), 0, 0);
	tile[26].setTile(CPoint(3,1), 0, 0);
	tile[27].setTile(CPoint(3,2), 1, 0);
	tile[28].setTile(CPoint(3,3), 0, 0);
	tile[29].setTile(CPoint(3,4), 1, 0);
	tile[30].setTile(CPoint(3,5), 0, 0);
	tile[31].setTile(CPoint(3,6), 1, 0);
	tile[32].setTile(CPoint(3,7), 0, 0);
	tile[33].setTile(CPoint(3,8), 0, 0);
	tile[34].setTile(CPoint(4,0), 1, 0);
	tile[35].setTile(CPoint(4,1), 1, 0);
	tile[36].setTile(CPoint(4,2), 1, 0);
	tile[37].setTile(CPoint(4,3), 1, 0);
	tile[38].setTile(CPoint(4, 4), 1, 0);
	tile[39].setTile(CPoint(4, 5), 1, 0);
	tile[40].setTile(CPoint(4, 6), 1, 0);
	tile[41].setTile(CPoint(4, 7), 0, 0);
	tile[42].setTile(CPoint(5, 0), 1, 0);
	tile[43].setTile(CPoint(5, 1), 2, 0);
	tile[44].setTile(CPoint(5, 2), 0, 0);
	tile[45].setTile(CPoint(5, 3), 1, 0);
	tile[46].setTile(CPoint(5, 4), 0, 0);
	tile[47].setTile(CPoint(5, 5), 2, 0);
	tile[48].setTile(CPoint(5, 6), 0, 0);
	tile[49].setTile(CPoint(5, 7), 1, 0);
	tile[50].setTile(CPoint(5, 8), 0, 0);
	tile[51].setTile(CPoint(6, 0), 1, 0);
	tile[52].setTile(CPoint(6, 1), 1, 0);
	tile[53].setTile(CPoint(6, 2), 1, 0);
	tile[54].setTile(CPoint(6, 3), 1, 0);
	tile[55].setTile(CPoint(6, 4), 1, 0);
	tile[56].setTile(CPoint(6, 5), 1, 0);
	tile[57].setTile(CPoint(6, 6), 1, 0);
	tile[58].setTile(CPoint(6, 7), 1, 0);
	tile[59].setTile(CPoint(7, 0), 0, 0);
	tile[60].setTile(CPoint(7, 1), 1, 0);
	tile[61].setTile(CPoint(7, 2), 0, 0);
	tile[62].setTile(CPoint(7, 3), 2, 0);
	tile[63].setTile(CPoint(7, 4), 0, 0);
	tile[64].setTile(CPoint(7, 5), 1, 0);
	tile[65].setTile(CPoint(7, 6), 0, 0);
	tile[66].setTile(CPoint(7, 7), 2, 0);
	tile[67].setTile(CPoint(7, 8), 1, 0);
	tile[68].setTile(CPoint(8, 0), 0, 0);
	tile[69].setTile(CPoint(8, 1), 1, 0);
	tile[70].setTile(CPoint(8, 2), 1, 0);
	tile[71].setTile(CPoint(8, 3), 1, 0);
	tile[72].setTile(CPoint(8, 4), 1, 0);
	tile[73].setTile(CPoint(8, 5), 1, 0);
	tile[74].setTile(CPoint(8, 6), 1, 0);
	tile[75].setTile(CPoint(8, 7), 1, 0);
	tile[76].setTile(CPoint(9, 0), 0, 0);
	tile[77].setTile(CPoint(9, 1), 0, 0);
	tile[78].setTile(CPoint(9, 2), 1, 0);
	tile[79].setTile(CPoint(9, 3), 0, 0);
	tile[80].setTile(CPoint(9, 4), 1, 0);
	tile[81].setTile(CPoint(9, 5), 0, 0);
	tile[82].setTile(CPoint(9, 6), 1, 0);
	tile[83].setTile(CPoint(9, 7), 0, 0);
	tile[84].setTile(CPoint(9, 8), 0, 0);
	tile[85].setTile(CPoint(10, 0), 0, 0);
	tile[86].setTile(CPoint(10, 1), 1, 0);
	tile[87].setTile(CPoint(10, 2), 1, 0);
	tile[88].setTile(CPoint(10, 3), 1, 0);
	tile[89].setTile(CPoint(10, 4), 0, 0);
	tile[90].setTile(CPoint(10, 5), 1, 0);
	tile[91].setTile(CPoint(10, 6), 2, 0);
	tile[92].setTile(CPoint(10, 7), 0, 0);
	tile[93].setTile((0,0), 0, 0);
	tile[94].setTile(CPoint(11,0), 1, 0);
	tile[95].setTile(CPoint(11, 1), 2, 0);
	tile[96].setTile(CPoint(11, 2), 1, 0);
	tile[97].setTile(CPoint(11, 3), 0, 0);
	tile[98].setTile(CPoint(11, 4), 0, 0);
	tile[99].setTile(CPoint(11, 5), 1, 0);
	tile[100].setTile(CPoint(11, 6), 1, 0);
	tile[101].setTile(CPoint(0,0), 0, 0);
	tile[102].setTile((0,0), 0, 0);
	tile[103].setTile(CPoint(12,0), 1, 0);
	tile[104].setTile(CPoint(12, 1), 1, 0);
	tile[105].setTile(CPoint(12, 2), 1, 0);
	tile[106].setTile(CPoint(12, 3), 1, 0);
	tile[107].setTile(CPoint(12, 4), 1, 0);
	tile[108].setTile(CPoint(12, 5), 0, 0);
	for (int i = 0; i < 110; i++) {
		if (tile[i].i_type_m == 2) {
			tile[i].setItem(1);
		}
	}
	//homes
	tile[57].setItem(3);
	//watson
 	tile[2].setItem(4);
	//smith
	tile[54].setItem(5);
	//Lestrade
	tile[39].setItem(6);
	//Stealthy
	tile[75].setItem(7);
	//William
	tile[35].setItem(8); 
	//goodley
	tile[106].setItem(9);
	//Jeremy
	tile[71].setItem(10);





	for (int i = 1; i < 8; i++) {
		rect[i].SetRect(30, 52 + 58 * i, 75, 107 + 58 * i);
	}
	for (int i = 9; i < 17; i++) {
		int k = i - 9;
		rect[i].SetRect(80, 80 + 58 * k, 125, 135 + 58 * k);
	}
	for (int i = 17; i < 25; i++) {
		int k = i - 16;
		rect[i].SetRect(130, -6 + 58 * k, 175, 49 + 58 * k);
	}
	for (int i = 25; i < 34; i++) {
		int k = i - 25;
		rect[i].SetRect(180, 22 + 58 * k, 225, 77 + 58 * k);
	}
	for (int i = 34; i < 42; i++) {
		int k = i - 33;
		rect[i].SetRect(230, -6 + 58 * k, 275, 49 + 58 * k);
	}
	for (int i = 42; i < 51; i++) {
		int k = i - 42;
		rect[i].SetRect(280, 22 + 58 * k , 325, 77 + 58 * k);
	}
	for (int i = 51; i < 59; i++) {
		int k = i - 50;
		rect[i].SetRect(330, -6 + 58 * k, 375, 49 + 58 * k);
	}
	for (int i = 59; i < 68; i++) {
		int k = i - 59;
		rect[i].SetRect(380, 22 + 58 * k , 425, 77 + 58 * k);
	}
	for (int i = 68; i < 76; i++) {
		int k = i - 67;
		rect[i].SetRect(430, -6 + 58 * k, 475, 49 + 58 * k);
	}
	for (int i = 76; i < 85; i++) {
		int k = i - 76;
		rect[i].SetRect(480, 22 + 58 * k , 525, 77 + 58 *k );
	}
	for (int i = 85; i < 93; i++) {
		int k = i - 84;
		rect[i].SetRect(530, -6 + 58 * k, 575, 49 + 58 * k);
	}
	for (int i = 93; i < 102; i++) {
		int k = i - 93;
		rect[i].SetRect(580, 80 + 58 * (k - 1), 625, 135 + 58 * (k - 1));
	}
	for (int i = 103; i < 109; i++) {
		int k = i - 102;
		rect[i].SetRect(630, 110 + 58 * (k - 1), 675, 165 + 58 * (k - 1));
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
	

	if ((i_Button_pressed_before == 75 && i_Button_pressed_after == 67)) {
		if (tile[i_Button_pressed_before].i_default_item == 3)
			homes.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 4)
			watson.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 5)
			john.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 6)
			lestrade.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 7)
			stealthy.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 8)
			william.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 9)
			goodley.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 10)
			jeremy.Move(tile[i_Button_pressed_after].p_tilepos);

		tile[i_Button_pressed_after].swapItem(tile[i_Button_pressed_before]);

		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	if ((i_Button_pressed_before == 3) && i_Button_pressed_after == 4) {
		if (tile[i_Button_pressed_before].i_default_item == 3)
			homes.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 4)
			watson.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 5)
			john.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 6)
			lestrade.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 7)
			stealthy.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 8)
			william.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 9)
			goodley.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 10)
			jeremy.Move(tile[i_Button_pressed_after].p_tilepos);
		tile[i_Button_pressed_after].swapItem(tile[i_Button_pressed_before]);

		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}

	if ((i_Button_pressed_before == 99 || i_Button_pressed_before == 2) && i_Button_pressed_after == 1) {
		if (tile[i_Button_pressed_before].i_default_item == 3)
			homes.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 4)
			watson.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 5)
			john.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 6)
			lestrade.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 7)
			stealthy.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 8)
			william.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 9)
			goodley.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 10)
			jeremy.Move(tile[i_Button_pressed_after].p_tilepos);
		tile[i_Button_pressed_after].swapItem(tile[i_Button_pressed_before]);


		watson.Move(0, 1);
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
 	if ((i_Button_pressed_before == 3||i_Button_pressed_before==1) && i_Button_pressed_after == 2) {
		if (tile[i_Button_pressed_before].i_default_item == 3)
			homes.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 4)
			watson.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 5)
			john.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 6)
			lestrade.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 7)
			stealthy.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 8)
			william.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 9)
			goodley.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 10)
			jeremy.Move(tile[i_Button_pressed_after].p_tilepos);
		tile[i_Button_pressed_after].swapItem(tile[i_Button_pressed_before]);
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	if ((i_Button_pressed_before == 2 || i_Button_pressed_before == 4) && i_Button_pressed_after == 3) {
		if (tile[i_Button_pressed_before].i_default_item == 3)
			homes.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 4)
			watson.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 5)
			john.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 6)
			lestrade.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 7)
			stealthy.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 8)
			william.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 9)
			goodley.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 10)
			jeremy.Move(tile[i_Button_pressed_after].p_tilepos);
		tile[i_Button_pressed_after].swapItem(tile[i_Button_pressed_before]);
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	if ((i_Button_pressed_before == 3 || i_Button_pressed_before == 5) && i_Button_pressed_after == 4) {
		if (tile[i_Button_pressed_before].i_default_item == 3)
			homes.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 4)
			watson.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 5)
			john.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 6)
			lestrade.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 7)
			stealthy.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 8)
			william.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 9)
			goodley.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 10)
			jeremy.Move(tile[i_Button_pressed_after].p_tilepos);
		tile[i_Button_pressed_after].swapItem(tile[i_Button_pressed_before]);
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	if ((i_Button_pressed_before == 75 || i_Button_pressed_before == 73) && i_Button_pressed_after == 74) {
		if (tile[i_Button_pressed_before].i_default_item == 3)
			homes.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 4)
			watson.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 5)
			john.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 6)
			lestrade.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 7)
			stealthy.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 8)
			william.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 9)
			goodley.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 10)
			jeremy.Move(tile[i_Button_pressed_after].p_tilepos);
		tile[i_Button_pressed_after].swapItem(tile[i_Button_pressed_before]);
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	if ((i_Button_pressed_before == 67 || i_Button_pressed_before == 74) && i_Button_pressed_after == 75) {
		if (tile[i_Button_pressed_before].i_default_item == 3)
			homes.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 4)
			watson.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 5)
			john.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 6)
			lestrade.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 7)
			stealthy.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 8)
			william.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 9)
			goodley.Move(tile[i_Button_pressed_after].p_tilepos);
		if (tile[i_Button_pressed_before].i_default_item == 10)
			jeremy.Move(tile[i_Button_pressed_after].p_tilepos);
		tile[i_Button_pressed_after].swapItem(tile[i_Button_pressed_before]);
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	else if (i_Button_pressed_before == 2) {
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
		m_png_Light_Map.Draw(dc, 15 + 50 * 0, 81 + 2 * 58 - 30);
		m_png_Light_Map.Draw(dc, 15 + 50 * 0, 81 + 4 * 58 - 30);
	}
	else if (i_Button_pressed_before == 4) {
		m_png_Light_Map.Draw(dc, 15 + 50 * 0, 81 + 3 * 58 - 30);
		m_png_Light_Map.Draw(dc, 15 + 50 * 0, 81 + 5 * 58 - 30);
	}
	else if (i_Button_pressed_before == 75) {
		m_png_Light_Map.Draw(dc, 70 + 50 * 7, 81 + 6 * 58 - 30);
		m_png_Light_Map.Draw(dc, 70 + 50 * 6, 81 + 7 * 58);
	}
	else if (i_Button_pressed_before == 74) {
		m_png_Light_Map.Draw(dc, 70 + 50 * 7, 81 + 5 * 58 - 30);
		m_png_Light_Map.Draw(dc, 70 + 50 * 7, 81 + 7 * 58 - 30);
	}
	else if (i_Button_pressed_before == 67) {
		m_png_Light_Map.Draw(dc, 70 + 50 * 7, 81 + 7 * 58 - 30);
		m_png_Light_Map.Draw(dc, 70 + 50 * 5, 81 + 7 * 58 - 30);
	}
	else {
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	//캐릭터의 좌표에 따라서 구현시키는 함수 구현.
	goodley.GetXPos() % 2 == 0 ? m_png_Goodley.Draw(dc, 32 + 50 * goodley.GetXPos(), 95 + 58 * goodley.GetYPos() - 35) : m_png_Goodley.Draw(dc, 32 + 50 * goodley.GetXPos(), 95 + 58 * goodley.GetYPos() - 65);

	homes.GetXPos() % 2 == 0 ? m_png_Homes.Draw(dc, 32 + 50 * homes.GetXPos(), 95 + 58 * homes.GetYPos() - 35) : m_png_Homes.Draw(dc, 32 + 50 * homes.GetXPos(), 95 + 58 * homes.GetYPos() - 65);
	
	jeremy.GetXPos() % 2 == 0 ?	m_png_Jeremy.Draw(dc, 32 + 50 * jeremy.GetXPos(), 95 + 58 * jeremy.GetYPos() - 35): m_png_Jeremy.Draw(dc, 32 + 50 * jeremy.GetXPos(), 95 + 58 * jeremy.GetYPos() - 65);

	john.GetXPos() % 2 == 0 ? m_png_John.Draw(dc, 32 + 50 * john.GetXPos(), 95 + 58 * john.GetYPos() - 35) : m_png_John.Draw(dc, 32 + 50 * john.GetXPos(), 95 + 58 * john.GetYPos() - 65);

	lestrade.GetXPos() % 2 == 0 ? m_png_Lestrade.Draw(dc, 32 + 50 * lestrade.GetXPos(), 95 + 58 * lestrade.GetYPos() - 35) : m_png_Lestrade.Draw(dc, 32 + 50 * lestrade.GetXPos(), 95 + 58 * lestrade.GetYPos() - 65);
	
	stealthy.GetXPos() % 2 == 0 ? m_png_Stealthy.Draw(dc, 32 + 50 * stealthy.GetXPos(), 95 + 58 * stealthy.GetYPos() - 35) : m_png_Stealthy.Draw(dc, 32 + 50 * stealthy.GetXPos(), 95 + 58 * stealthy.GetYPos() - 65);

	watson.GetXPos() % 2 == 0 ? m_png_Watson.Draw(dc, 32 + 50 * watson.GetXPos(), 95 + 58 * watson.GetYPos() - 35) : m_png_Watson.Draw(dc, 32 + 50 * watson.GetXPos(), 95 + 58 * watson.GetYPos() - 65);

	william.GetXPos() % 2 == 0 ? m_png_William.Draw(dc, 32 + 50 * william.GetXPos(), 95 + 58 * william.GetYPos() - 35) : m_png_William.Draw(dc, 32 + 50 * william.GetXPos(), 95 + 58 * william.GetYPos() - 65);

	//탈출경로와 타일 판정위치 표시하는 것임. 하단에 있는것을 주석처리하면 나타나지 않음. 
	/*
	for(int i=1;i<109;i++)
		if(tile[i].i_type_m==1)
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
	
	/*
	msg.Format(_T("값: %d, %d"), watson.GetXPos(), watson.GetYPos());
	MessageBox(msg);
	*/
	for (int i = 1; i < 109; i++) {
		if (rect[i].PtInRect(point) && i_Button_pressed_before == 0&&tile[i].i_default_item>2) {
			i_Button_pressed_before = i;
			Invalidate();
		}
		else if (rect[i].PtInRect(point) && i_Button_pressed_before != 0) {
			i_Button_pressed_after = i;
			
			Invalidate();
			break;
		}
	}
	/*
	for (int j = 0; j < 4; j++) {
		if (Escape_route[j].PtInRect(point)) {
			msg = j+"번째 안에 있다.";
			AfxMessageBox(msg);
		}
	}
	*/
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
