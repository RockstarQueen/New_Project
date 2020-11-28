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
	tile[1].setTile(0, 0, 0);
	tile[2].setTile(2, 0, 0);
	tile[3].setTile(3, 1, 0);
	tile[4].setTile(4, 1, 0);
	tile[5].setTile(5, 1, 0);
	tile[6].setTile(6, 1, 0);
	tile[7].setTile(7, 1, 0);
	tile[8].setTile(8, 0, 0);
	tile[9].setTile(9, 0, 0);
	tile[10].setTile(10, 1, 0);
	tile[11].setTile(11, 1, 0);
	tile[12].setTile(12, 0, 0);
	tile[13].setTile(13, 0, 0);
	tile[14].setTile(14, 1, 0);
	tile[15].setTile(15, 0, 0);
	tile[16].setTile(16, 1, 0);
	tile[17].setTile(17, 0, 0);
	tile[18].setTile(18, 0, 0);
	tile[19].setTile(19, 2, 0);
	tile[20].setTile(20, 1, 0);
	tile[21].setTile(21, 0, 0);
	tile[22].setTile(22, 1, 0);
	tile[23].setTile(23, 1, 0);
	tile[24].setTile(24, 1, 0);
	tile[25].setTile(25, 0, 0);
	tile[26].setTile(26, 0, 0);
	tile[27].setTile(27, 0, 0);
	tile[28].setTile(28, 1, 0);
	tile[29].setTile(29, 0, 0);
	tile[30].setTile(30, 1, 0);
	tile[31].setTile(31, 0, 0);
	tile[32].setTile(32, 1, 0);
	tile[33].setTile(33, 0, 0);
	tile[34].setTile(34, 0, 0);
	tile[35].setTile(35, 1, 0);
	tile[36].setTile(36, 1, 0);
	tile[37].setTile(37, 1, 0);
	tile[38].setTile(38, 1, 0);
	tile[39].setTile(39, 1, 0);
	tile[40].setTile(40, 1, 0);
	tile[41].setTile(41, 1, 0);
	tile[42].setTile(42, 0, 0);
	tile[43].setTile(43, 1, 0);
	tile[44].setTile(44, 2, 0);
	tile[45].setTile(45, 0, 0);
	tile[46].setTile(46, 1, 0);
	tile[47].setTile(47, 0, 0);
	tile[48].setTile(48, 2, 0);
	tile[49].setTile(49, 0, 0);
	tile[50].setTile(50, 1, 0);
	tile[51].setTile(51, 0, 0);
	tile[52].setTile(52, 1, 0);
	tile[53].setTile(53, 1, 0);
	tile[54].setTile(54, 1, 0);
	tile[55].setTile(55, 1, 0);
	tile[56].setTile(56, 1, 0);
	tile[57].setTile(57, 1, 0);
	tile[58].setTile(58, 1, 0);
	tile[59].setTile(59, 1, 0);
	tile[60].setTile(60, 0, 0);
	tile[61].setTile(61, 1, 0);
	tile[62].setTile(62, 0, 0);
	tile[63].setTile(63, 2, 0);
	tile[64].setTile(64, 0, 0);
	tile[65].setTile(65, 1, 0);
	tile[66].setTile(66, 0, 0);
	tile[67].setTile(67, 2, 0);
	tile[68].setTile(68, 1, 0);
	tile[69].setTile(69, 0, 0);
	tile[70].setTile(70, 1, 0);
	tile[71].setTile(71, 1, 0);
	tile[72].setTile(72, 1, 0);
	tile[73].setTile(73, 1, 0);
	tile[74].setTile(74, 1, 0);
	tile[75].setTile(75, 1, 0);
	tile[76].setTile(76, 1, 0);
	tile[77].setTile(77, 0, 0);
	tile[78].setTile(78, 0, 0);
	tile[79].setTile(79, 1, 0);
	tile[80].setTile(80, 0, 0);
	tile[81].setTile(81, 1, 0);
	tile[82].setTile(82, 0, 0);
	tile[83].setTile(83, 1, 0);
	tile[84].setTile(84, 0, 0);
	tile[85].setTile(85, 0, 0);
	tile[86].setTile(86, 0, 0);
	tile[87].setTile(87, 1, 0);
	tile[88].setTile(88, 1, 0);
	tile[89].setTile(89, 1, 0);
	tile[90].setTile(90, 0, 0);
	tile[91].setTile(91, 1, 0);
	tile[92].setTile(92, 2, 0);
	tile[93].setTile(93, 0, 0);
	tile[94].setTile(94, 0, 0);
	tile[95].setTile(95, 1, 0);
	tile[96].setTile(96, 2, 0);
	tile[97].setTile(97, 1, 0);
	tile[98].setTile(98, 0, 0);
	tile[99].setTile(99, 0, 0);
	tile[100].setTile(100, 1, 0);
	tile[101].setTile(101, 1, 0);
	tile[102].setTile(102, 0, 0);
	tile[103].setTile(103, 0, 0);
	tile[104].setTile(104, 1, 0);
	tile[105].setTile(105, 1, 0);
	tile[106].setTile(106, 1, 0);
	tile[107].setTile(107, 1, 0);
	tile[108].setTile(108, 1, 0);








	for (int i = 1; i < 8; i++) {
		rect[i].SetRect(30, 52 + 58 * (i-1), 75, 107 + 58 * (i-1));
	}
	for (int i = 10; i < 17; i++) {
		int k = i - 10;
		rect[i].SetRect(80, 80 + 58 * k, 125, 135 + 58 * k);
	}
	for (int i = 17; i < 26; i++) {
		int k = i - 17;
		rect[i].SetRect(130, -6 + 58 * k, 175, 49 + 58 * k);
	}
	for (int i = 26; i < 35; i++) {
		int k = i - 25;
		rect[i].SetRect(180, 22 + 58 * (k-1), 225, 77 + 58 * (k-1));
	}
	for (int i = 35; i < 43; i++) {
		int k = i - 34;
		rect[i].SetRect(230, -6 + 58 * k, 275, 49 + 58 * k);
	}
	for (int i = 43; i < 52; i++) {
		int k = i - 42;
		rect[i].SetRect(280, 22 + 58 * (k - 1), 325, 77 + 58 * (k - 1));
	}
	for (int i = 52; i < 60; i++) {
		int k = i - 51;
		rect[i].SetRect(330, -6 + 58 * k, 375, 49 + 58 * k);
	}
	for (int i = 60; i < 69; i++) {
		int k = i - 59;
		rect[i].SetRect(380, 22 + 58 * (k - 1), 425, 77 + 58 * (k - 1));
	}
	for (int i = 69; i < 77; i++) {
		int k = i - 68;
		rect[i].SetRect(430, -6 + 58 * k, 475, 49 + 58 * k);
	}
	for (int i = 77; i < 86; i++) {
		int k = i - 76;
		rect[i].SetRect(480, 22 + 58 * (k - 1), 525, 77 + 58 * (k - 1));
	}
	for (int i = 86; i < 94; i++) {
		int k = i - 85;
		rect[i].SetRect(530, -6 + 58 * k, 575, 49 + 58 * k);
	}
	for (int i = 94; i < 102; i++) {
		int k = i - 94;
		rect[i].SetRect(580, 80 + 58 * (k - 1), 625, 135 + 58 * (k - 1));
	}
	for (int i = 103; i < 109; i++) {
		int k = i - 103;
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
		stealthy.Move(7, 8);
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	if ((i_Button_pressed_before == 3) && i_Button_pressed_after == 4) {
		watson.Move(0,4);
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	if ((i_Button_pressed_before == 3) && i_Button_pressed_after == 2) {
		watson.Move(0, 2);
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	if ((i_Button_pressed_before == 2 || i_Button_pressed_before == 4) && i_Button_pressed_after == 3) {
		watson.Move(0, 3);
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
		m_png_Light_Map.Draw(dc, 65 + 50 * -1, 81 + 2 * 58 - 30);
		m_png_Light_Map.Draw(dc, 65 + 50 * -1, 81 + 4 * 58 - 30);
	}
	else if (i_Button_pressed_before == 4) {
		m_png_Light_Map.Draw(dc, 65 + 50 * -1, 81 + 3 * 58 - 30);
		m_png_Light_Map.Draw(dc, 65 + 50 * -1, 81 + 5 * 58 - 30);
	}
	else if (i_Button_pressed_before == 75) {
		m_png_Light_Map.Draw(dc, 70 + 50 * 7, 81 + 6 * 58 - 30);
		m_png_Light_Map.Draw(dc, 70 + 50 * 6, 81 + 7 * 58);
	}
	else if (i_Button_pressed_before == 74) {
		m_png_Light_Map.Draw(dc, 70 + 50 * 7, 81 + 5 * 58 - 30);
		m_png_Light_Map.Draw(dc, 70 + 50 * 7, 81 + 7 * 58 - 30);
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
	
	for(int i=1;i<109;i++)
		if(tile[i].i_type_m==1)
			dc.Rectangle(rect[i]);
	for (int i = 0; i < 4; i++) {
		dc.Rectangle(Escape_route[i]);
	}
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
