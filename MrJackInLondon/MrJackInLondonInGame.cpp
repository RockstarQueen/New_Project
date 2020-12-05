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
#include "GameData.h"


// MrJackInLondonInGame_T 대화 상자

IMPLEMENT_DYNAMIC(CMrJackInLondonInGame, CDialogEx)

UINT CMrJackInLondonInGame::ThreadFunc(LPVOID lpVoid)
{
	TRACE("\nrecv thread starts\n");
	// If you use a worker thread, you'll need to
	// call AfxSocketInit()...
	if (AfxSocketInit() == FALSE)
	{
		TRACE("AfxSocketInit() failed!\n");
		return 1;
	}
	SOCKET* pSocket = (SOCKET*)lpVoid;
	CClient* clSocket = new CClient();
	clSocket->Attach(*pSocket);
	TRACE("\nAttach finished\n");

	while (true)
	{
		TRACE("\n===== receive always =====\n");
		char recvData[PACKET_SIZE] = "";
		if (clSocket->Receive(recvData, sizeof(recvData), 0)) {
			recvData[strlen(recvData)] = '\0';

			// 게임 종료조건
			if (!strcmp(recvData, "Game End")) {
				TRACE("\n===== Game End =====\n");
				break;
			}
			else
				TRACE("\nreceived message: %s\n", recvData);
				//clSocket->Send(recvData, PACKET_SIZE, 0);
		}
	}
	return 0;
}

CMrJackInLondonInGame::CMrJackInLondonInGame(CWnd* pParent, CClient* tempsock)
	: CDialogEx(IDD_DIALOG_InGame, pParent)
{
	
	TRACE("\n~~~~~~~~~~~tmpSocket: %#x~~~~~~~~~~~\n", tempsock);


	TRACE("\nstart detach()\n");
	this->rsock = tempsock->Detach();
	TRACE("\nfinished detach()\n");

	CWinThread* pthread = AfxBeginThread(ThreadFunc, &this->rsock);

	/*s_is_jack.Format(_T("당신은 도둑입니다. 잭: "));
	s_not_jack.Format(_T("당신은 경찰입니다."));
	set_Jack();*/
	//i_player_num == 0 ? MessageBox(s_is_jack) : MessageBox(s_not_jack);
	i_Button_pressed_after = 0;
	i_Button_pressed_before = 0;
	//제작:이화원 탈출하는 위치& 타일의 판정을 Rect배열로 구현함. 
	Escape_route[0].SetRect(15, 15, 120, 80);
	Escape_route[1].SetRect(605, 15, 680, 80);
	Escape_route[2].SetRect(15, 490, 120, 560);
	Escape_route[3].SetRect(605, 490, 680, 560);
	//tile 값 초기화, 2차원 연동.
	tile[0].setTile(CPoint(0, 0), 0, 0);
	tile[1].setTile(CPoint(0, 1), 0, 0);
	tile[2].setTile(CPoint(0, 2), 1, 0);
	tile[3].setTile(CPoint(0, 3), 1, 0);
	tile[4].setTile(CPoint(0, 4), 1, 0);
	tile[5].setTile(CPoint(0, 5), 1, 0);
	tile[6].setTile(CPoint(0, 6), 1, 0);
	tile[7].setTile(CPoint(0, 0), 0, 0);
	tile[8].setTile(CPoint(0, 0), 0, 0);
	tile[9].setTile(CPoint(1, 1), 1, 0);
	tile[10].setTile(CPoint(1, 2), 1, 0);
	tile[11].setTile(CPoint(1, 3), 0, 0);
	tile[12].setTile(CPoint(1, 4), 0, 0);
	tile[13].setTile(CPoint(1, 5), 1, 0);
	tile[14].setTile(CPoint(1, 6), 2, 0);
	tile[15].setTile(CPoint(1, 7), 1, 0);
	tile[16].setTile(CPoint(0, 8), 0, 0);
	tile[17].setTile(CPoint(2, 0), 0, 0);
	tile[18].setTile(CPoint(2, 1), 2, 0);
	tile[19].setTile(CPoint(2, 2), 1, 0);
	tile[20].setTile(CPoint(2, 3), 0, 0);
	tile[21].setTile(CPoint(2, 4), 1, 0);
	tile[22].setTile(CPoint(2, 5), 1, 0);
	tile[23].setTile(CPoint(2, 6), 1, 0);
	tile[24].setTile(CPoint(2, 7), 0, 0);
	tile[25].setTile(CPoint(3, 0), 0, 0);
	tile[26].setTile(CPoint(3, 1), 0, 0);
	tile[27].setTile(CPoint(3, 2), 1, 0);
	tile[28].setTile(CPoint(3, 3), 0, 0);
	tile[29].setTile(CPoint(3, 4), 1, 0);
	tile[30].setTile(CPoint(3, 5), 0, 0);
	tile[31].setTile(CPoint(3, 6), 1, 0);
	tile[32].setTile(CPoint(3, 7), 0, 0);
	tile[33].setTile(CPoint(3, 8), 0, 0);
	tile[34].setTile(CPoint(4, 0), 1, 0);
	tile[35].setTile(CPoint(4, 1), 1, 0);
	tile[36].setTile(CPoint(4, 2), 1, 0);
	tile[37].setTile(CPoint(4, 3), 1, 0);
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
	tile[93].setTile(CPoint(11, 0), 0, 0);
	tile[94].setTile(CPoint(11, 1), 1, 0);
	tile[95].setTile(CPoint(11, 2), 2, 0);
	tile[96].setTile(CPoint(11, 3), 1, 0);
	tile[97].setTile(CPoint(11, 4), 0, 0);
	tile[98].setTile(CPoint(11, 5), 0, 0);
	tile[99].setTile(CPoint(11, 6), 1, 0);
	tile[100].setTile(CPoint(11, 7), 1, 0);
	tile[101].setTile(CPoint(0, 0), 0, 0);
	tile[102].setTile((0, 0), 0, 0);
	tile[103].setTile(CPoint(12, 1), 1, 0);
	tile[104].setTile(CPoint(12, 2), 1, 0);
	tile[105].setTile(CPoint(12, 3), 1, 0);
	tile[106].setTile(CPoint(12, 4), 1, 0);
	tile[107].setTile(CPoint(12, 5), 1, 0);
	tile[108].setTile(CPoint(12, 6), 0, 0);

	for (int i = 0; i < 110; i++) {
		if (tile[i].i_type_m == 2) {
			tile[i].setItem(1);
		}
	}
	tile[14].b_switch_on = TRUE;
	tile[18].b_switch_on = TRUE;
	tile[47].b_switch_on = TRUE;
	tile[62].b_switch_on = TRUE;
	tile[91].b_switch_on = TRUE;
	tile[95].b_switch_on = TRUE;

	//homes
	tile[56].setItem(3);
	//watson
	tile[2].setItem(4);
	//smith
	tile[53].setItem(5);
	//Lestrade
	tile[38].setItem(6);
	//Stealthy
	tile[75].setItem(7);
	//William
	tile[34].setItem(8);
	//goodley
	tile[105].setItem(9);
	//Jeremy
	tile[71].setItem(10);


	//SetRect -> 판정 구현
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
		rect[i].SetRect(280, 22 + 58 * k, 325, 77 + 58 * k);
	}
	for (int i = 51; i < 59; i++) {
		int k = i - 50;
		rect[i].SetRect(330, -6 + 58 * k, 375, 49 + 58 * k);
	}
	for (int i = 59; i < 68; i++) {
		int k = i - 59;
		rect[i].SetRect(380, 22 + 58 * k, 425, 77 + 58 * k);
	}
	for (int i = 68; i < 76; i++) {
		int k = i - 67;
		rect[i].SetRect(430, -6 + 58 * k, 475, 49 + 58 * k);
	}
	for (int i = 76; i < 85; i++) {
		int k = i - 76;
		rect[i].SetRect(480, 22 + 58 * k, 525, 77 + 58 * k);
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
ON_BN_CLICKED(IDC_IGB_TURNEND, &CMrJackInLondonInGame::OnBnClickedIgbTurnend)
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

	m_png_Goodley_s.Load(L"res\\Goodley-suspicious.png");
	m_png_Homes_s.Load(L"res\\Homes-suspicious.png");
	m_png_Jeremy_s.Load(L"res\\Jeremy-suspicious.png");
	m_png_John_s.Load(L"res\\John-suspicious.png");
	m_png_Lestrade_s.Load(L"res\\Lestrade-suspicious.png");
	m_png_Stealthy_s.Load(L"res\\Stealthy-suspicious.png");
	m_png_William_s.Load(L"res\\William-suspicious.png");
	m_png_Watson_s.Load(L"res\\Watson-suspicious.png");

	m_png_Goodley_i.Load(L"res\\Goodley-innocent.png");
	m_png_Homes_i.Load(L"res\\Homes-innocent.png");
	m_png_Jeremy_i.Load(L"res\\Jeremy-innocent.png");
	m_png_John_i.Load(L"res\\John-innocent.png");
	m_png_Lestrade_i.Load(L"res\\Lestrade-innocent.png");
	m_png_Stealthy_i.Load(L"res\\Stealthy-innocent.png");
	m_png_William_i.Load(L"res\\William-innocent.png");
	m_png_Watson_i.Load(L"res\\Watson-innocent.png");

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
	
	if (watson.move_count == 0) {

	}
	//tile[i_b_p_b] -> tile[i_b_p_a] 
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
	if ((i_Button_pressed_before == 72 || i_Button_pressed_before == 70) && i_Button_pressed_after == 71) {
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
	if ((i_Button_pressed_before == 73 || i_Button_pressed_before == 71) && i_Button_pressed_after == 72) {
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
	if ((i_Button_pressed_before == 74 || i_Button_pressed_before == 72) && i_Button_pressed_after == 73) {
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
	if ((i_Button_pressed_before == 72 || i_Button_pressed_before == 74 || i_Button_pressed_before == 82) && i_Button_pressed_after == 73) {
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
	if ((i_Button_pressed_before == 10 || i_Button_pressed_before == 3) && i_Button_pressed_after == 2) {
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
	if ((i_Button_pressed_before == 4) && i_Button_pressed_after == 3) {
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
	// 맨홀 2 제외
	if ((i_Button_pressed_before == 3 || i_Button_pressed_before == 5 || i_Button_pressed_before == 13) && i_Button_pressed_after == 4) {
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
	if ((i_Button_pressed_before == 4 || i_Button_pressed_before == 6 || i_Button_pressed_before == 13) && i_Button_pressed_after == 5) {
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
	if ((i_Button_pressed_before == 13 || i_Button_pressed_before == 5) && i_Button_pressed_after == 6) {
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
	if ((i_Button_pressed_before == 10) && i_Button_pressed_after == 9) {
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
	if ((i_Button_pressed_before == 9 || i_Button_pressed_before == 19||i_Button_pressed_before==2) && i_Button_pressed_after == 10) {
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
	// 맨홀 2 제외
	if ((i_Button_pressed_before == 4 || i_Button_pressed_before == 5 || i_Button_pressed_before == 21 || i_Button_pressed_before == 22) && i_Button_pressed_after == 13) {
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
	if ((i_Button_pressed_before == 6) && i_Button_pressed_after == 15) {
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
	// 맨홀 23 제외
	if ((i_Button_pressed_before == 10 || i_Button_pressed_before == 27) && i_Button_pressed_after == 19) {
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
	if ((i_Button_pressed_before == 13 || i_Button_pressed_before == 22||i_Button_pressed_before==29) && i_Button_pressed_after == 21) {
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
	if ((i_Button_pressed_before == 21 || i_Button_pressed_before == 13 || i_Button_pressed_before == 31) && i_Button_pressed_after == 22) {
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
	// 맨홀 23 제외
	if ((i_Button_pressed_before == 22 || i_Button_pressed_before == 31 || i_Button_pressed_before == 15) && i_Button_pressed_after == 23) {
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
	if ((i_Button_pressed_before == 19 || i_Button_pressed_before == 35 || i_Button_pressed_before == 36) && i_Button_pressed_after == 27) {
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
	if ((i_Button_pressed_before == 21 || i_Button_pressed_before == 37 || i_Button_pressed_before == 38) && i_Button_pressed_after == 29) {
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
	if ((i_Button_pressed_before == 22 || i_Button_pressed_before == 39 || i_Button_pressed_before == 40) && i_Button_pressed_after == 31) {
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
	// 맨홀 23제외
	if ((i_Button_pressed_before == 35) && i_Button_pressed_after == 34) {
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
	// 맨홀 42 제외
	if ((i_Button_pressed_before == 34 || i_Button_pressed_before == 27 || i_Button_pressed_before == 36) && i_Button_pressed_after == 35) {
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
	if ((i_Button_pressed_before == 37 || i_Button_pressed_before == 27 || i_Button_pressed_before == 35||i_Button_pressed_before==45) && i_Button_pressed_after == 36) {
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
	//맨홀 45 제외
	if ((i_Button_pressed_before == 27 || i_Button_pressed_before == 38 || i_Button_pressed_before == 36 || i_Button_pressed_before == 45) && i_Button_pressed_after == 37) {
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
	//맨홀 45 제외
	if ((i_Button_pressed_before == 27 || i_Button_pressed_before == 37 || i_Button_pressed_before == 39||i_Button_pressed_before == 47) && i_Button_pressed_after == 38) {
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
	if ((i_Button_pressed_before == 31 || i_Button_pressed_before == 40 || i_Button_pressed_before == 38||i_Button_pressed_before==47) && i_Button_pressed_after == 39) {
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
	if ((i_Button_pressed_before == 31 || i_Button_pressed_before == 39 || i_Button_pressed_before == 49) && i_Button_pressed_after == 40) {
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
	if ((i_Button_pressed_before == 34 || i_Button_pressed_before == 51) && i_Button_pressed_after == 42) {
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
	if ((i_Button_pressed_before == 36 || i_Button_pressed_before == 37 || i_Button_pressed_before == 53 || i_Button_pressed_before == 54) && i_Button_pressed_after == 45) {
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
	if ((i_Button_pressed_before == 40 || i_Button_pressed_before == 57 || i_Button_pressed_before == 58) && i_Button_pressed_after == 49) {
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
	if ((i_Button_pressed_before == 60 || i_Button_pressed_before == 52 || i_Button_pressed_before==42) && i_Button_pressed_after == 51) {
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
	// 맨홀 42 제외
	if ((i_Button_pressed_before == 53 || i_Button_pressed_before == 60 || i_Button_pressed_before == 51) && i_Button_pressed_after == 52) {
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
	if ((i_Button_pressed_before == 52 || i_Button_pressed_before == 54 || i_Button_pressed_before == 45) && i_Button_pressed_after == 53) {
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
	//맨홀45 제외
	if ((i_Button_pressed_before == 55 || i_Button_pressed_before == 53 || i_Button_pressed_before == 45) && i_Button_pressed_after == 54) {
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
	//맨홀 45 제외
	if ((i_Button_pressed_before == 56 || i_Button_pressed_before == 54||i_Button_pressed_before==64|| i_Button_pressed_before == 47) && i_Button_pressed_after == 55) {
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
	//맨홀 64 제외
	if ((i_Button_pressed_before == 57 || i_Button_pressed_before == 55||i_Button_pressed_before == 64|| i_Button_pressed_before == 47) && i_Button_pressed_after == 56) {
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
	// 맨홀 64 제외
	if ((i_Button_pressed_before == 49 || i_Button_pressed_before == 58 || i_Button_pressed_before == 56) && i_Button_pressed_after == 57) {
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
	if ((i_Button_pressed_before == 49 || i_Button_pressed_before == 57||i_Button_pressed_before==67) && i_Button_pressed_after == 58) {
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
	//맨홀 67제외
	if ((i_Button_pressed_before == 51 || i_Button_pressed_before == 52 || i_Button_pressed_before == 69) && i_Button_pressed_after == 60) {
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
	if ((i_Button_pressed_before == 55 || i_Button_pressed_before == 56 || i_Button_pressed_before == 72 || i_Button_pressed_before == 73) && i_Button_pressed_after == 64) {
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
	if ((i_Button_pressed_before == 58 || i_Button_pressed_before == 75) && i_Button_pressed_after == 67) {
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
	if ((i_Button_pressed_before == 60 || i_Button_pressed_before == 70 || i_Button_pressed_before == 78) && i_Button_pressed_after == 69) {
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
	if ((i_Button_pressed_before == 69 || i_Button_pressed_before == 78 || i_Button_pressed_before == 71) && i_Button_pressed_after == 70) {
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
	if ((i_Button_pressed_before == 72 || i_Button_pressed_before == 80 || i_Button_pressed_before == 70) && i_Button_pressed_after == 71) {
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
	if ((i_Button_pressed_before == 73 || i_Button_pressed_before == 80 || i_Button_pressed_before == 64|| i_Button_pressed_before == 71 || i_Button_pressed_before == 4) && i_Button_pressed_after == 72) {
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
	// 맨홀 67제외
	if ((i_Button_pressed_before == 74 || i_Button_pressed_before == 82 || i_Button_pressed_before == 64|| i_Button_pressed_before == 72||i_Button_pressed_before==4) && i_Button_pressed_after == 73) {
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
	// 맨홀 64 제외
	if ((i_Button_pressed_before == 73 || i_Button_pressed_before == 82 || i_Button_pressed_before == 75) && i_Button_pressed_after == 74) {
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
	if ((i_Button_pressed_before == 74) && i_Button_pressed_after == 75) {
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
	//맨홀 67 제외
	if ((i_Button_pressed_before == 69 || i_Button_pressed_before == 70 || i_Button_pressed_before == 86 || i_Button_pressed_before == 87) && i_Button_pressed_after == 78) {
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
	if ((i_Button_pressed_before == 71 || i_Button_pressed_before == 72 || i_Button_pressed_before == 88) && i_Button_pressed_after == 80) {
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
	if ((i_Button_pressed_before == 73 || i_Button_pressed_before == 74 || i_Button_pressed_before == 90) && i_Button_pressed_after == 82) {
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
	if ((i_Button_pressed_before == 87 || i_Button_pressed_before == 78) && i_Button_pressed_after == 86) {
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
	//맨홀 94 제외
	if ((i_Button_pressed_before == 78 || i_Button_pressed_before == 96 || i_Button_pressed_before == 86 || i_Button_pressed_before == 88) && i_Button_pressed_after == 87) {
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
	if ((i_Button_pressed_before == 96 || i_Button_pressed_before == 80 || i_Button_pressed_before == 87) && i_Button_pressed_after == 88) {
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
	if ((i_Button_pressed_before == 82 || i_Button_pressed_before == 99) && i_Button_pressed_after == 90) {
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
	if ((i_Button_pressed_before == 103 || i_Button_pressed_before == 86) && i_Button_pressed_after == 94) {
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
	if ((i_Button_pressed_before == 104 || i_Button_pressed_before == 88 || i_Button_pressed_before == 87 || i_Button_pressed_before == 105) && i_Button_pressed_after == 96) {
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
	if ((i_Button_pressed_before == 90 || i_Button_pressed_before == 107 || i_Button_pressed_before == 100) && i_Button_pressed_after == 99) {
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
	if ((i_Button_pressed_before == 104||i_Button_pressed_after==94) && i_Button_pressed_after == 103) {
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
	// 맨홀 94 제외
	if ((i_Button_pressed_before == 105 || i_Button_pressed_before == 96 || i_Button_pressed_before == 103) && i_Button_pressed_after == 104) {
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
	if ((i_Button_pressed_before == 96 || i_Button_pressed_before == 104) && i_Button_pressed_after == 105) {
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
	//맨홀 106 제외
	if ((i_Button_pressed_before == 107 || i_Button_pressed_before == 105) && i_Button_pressed_after == 106) {
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
	if ((i_Button_pressed_before == 99|| i_Button_pressed_before == 106) && i_Button_pressed_after == 107) {
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
	//맨홀 106 제외
	else if (i_Button_pressed_before == 2) {
		m_png_Light_Map.Draw(dc, 70 + 50 * 0, 81 + 1 * 58 );
		m_png_Light_Map.Draw(dc, 17 + 50 * 0, 51 + 3 * 58);

		m_png_Light_Map.Draw(dc, 70 + 50 * 4, 81 + -1 * 58);
		m_png_Light_Map.Draw(dc, 70 + 50 * 6, 81 + 7 * 58);
		m_png_Light_Map.Draw(dc, 70 + 50 * 6, 81 + 4 * 58);
		m_png_Light_Map.Draw(dc, 70 + 50 * 10, 81 + 0 * 58);
		m_png_Light_Map.Draw(dc, 70 + 50 * 11, 81 + 4 * 58 - 30);
		m_png_Light_Map.Draw(dc, 70 + 50 * 1, 81 + 6 * 58 - 30);
	}
	else if (i_Button_pressed_before == 3) {
		m_png_Light_Map.Draw(dc, 15 + 50 * 0, 51 + 2 * 58);
		m_png_Light_Map.Draw(dc, 15 + 50 * 0, 51 + 4 * 58);
	}
	else if (i_Button_pressed_before == 4) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 0, 51 + 3 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 0, 51 + 5 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 1, 21 + 5 * 58);
	}
	else if (i_Button_pressed_before == 5) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 0, 81 + 4 * 58 - 30);
		m_png_Light_Map.Draw(dc, 17 + 50 * 0, 81 + 6 * 58 - 30);
		m_png_Light_Map.Draw(dc, 17 + 50 * 1, 21 + 5 * 58);
	}
	else if (i_Button_pressed_before == 6) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 0, 81 + 5 * 58 - 30);
		m_png_Light_Map.Draw(dc, 17 + 50 * 1, 81 + 6 * 58);
	}
	else if (i_Button_pressed_before == 9) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 1, 51 + 2 * 58 - 30);
		
	}
	else if (i_Button_pressed_before == 10) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 1, 51 + 1 * 58-30);
		m_png_Light_Map.Draw(dc, 17 + 50 * 0, 51 + 2 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 2, 51 + 2 * 58);
	}
	else if (i_Button_pressed_before == 13) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 0, 81 + 4 * 58 - 30);
		m_png_Light_Map.Draw(dc, 17 + 50 * 0, 81 + 5 * 58 - 30);
		m_png_Light_Map.Draw(dc, 17 + 50 * 2, 81 + 4 * 58 - 30);
		m_png_Light_Map.Draw(dc, 17 + 50 * 2, 81 + 5 * 58 - 30);
	}
	else if (i_Button_pressed_before == 15) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 0, 81 + 6 * 58 - 30);
		m_png_Light_Map.Draw(dc, 17 + 50 * 2, 81 + 6 * 58 - 30);		
	}
	else if (i_Button_pressed_before == 19) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 1, 81 + 1 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 3, 81 + 1 * 58);
	}
	else if (i_Button_pressed_before == 21) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 1, 81 + 4 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 2, 51 + 5 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 3, 81 + 3 * 58);
	}
	else if (i_Button_pressed_before == 22) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 1, 81 + 4 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 2, 51 + 4 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 2, 51 + 6 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 3, 81 + 5 * 58);
	}
	else if (i_Button_pressed_before == 23) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 1, 81 + 6 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 2, 51 + 5 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 3, 81 + 5 * 58);
	}
	else if (i_Button_pressed_before == 27) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 2, -65 + 4 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 4, -65 + 3 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 4, -65 + 4 * 58);
	}
	else if (i_Button_pressed_before == 29) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 2, -65 + 6 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 4, -65 + 5 * 58);
	}
	else if (i_Button_pressed_before == 31) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 2, -65 + 7 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 2, -65 + 8 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 4, -65 + 7 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 4, -65 + 8 * 58);
	}
	else if (i_Button_pressed_before == 34) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 5, 21 + 0 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 4, 51 + 1 * 58);
	}
	else if (i_Button_pressed_before == 35) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 3, 21 + 2 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 4, 51 + 0 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 4, 51 + 2 * 58);
	}
	else if (i_Button_pressed_before == 36) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 3, 21 + 2 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 4, 51 + 1 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 4, 51 + 3 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 5, 21 + 3 * 58);
	}
	else if (i_Button_pressed_before == 37) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 3, 21 + 4 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 5, 21 + 3 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 4, 51 + 2 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 4, 51 + 4 * 58);
	}
	else if (i_Button_pressed_before == 38) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 3, 21 + 4 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 4, 51 + 3 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 4, 51 + 5 * 58);
	}
	else if (i_Button_pressed_before == 39) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 3, 21 + 6 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 4, 51 + 4 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 4, 51 + 6 * 58);
	}
	else if (i_Button_pressed_before == 40) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 3, 21 + 6 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 5, 21 + 7 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 4, 51 + 5 * 58);
	}
	else if (i_Button_pressed_before == 42) {
	
	m_png_Light_Map.Draw(dc, 17 + 50 * 4, 51 + 0 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 0 * 58);
	}
	else if (i_Button_pressed_before == 45) {

	m_png_Light_Map.Draw(dc, 17 + 50 * 4, 51 + 2 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 4, 51 + 3 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 2 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 3 * 58);
	}
	else if (i_Button_pressed_before == 49) {

	m_png_Light_Map.Draw(dc, 17 + 50 * 4, 51 + 6 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 6 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 7 * 58);
	}
	else if (i_Button_pressed_before == 51) {

	m_png_Light_Map.Draw(dc, 17 + 50 * 5, 21 + 0 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 1 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 7, 21 + 1 * 58);
	}
	else if (i_Button_pressed_before == 52) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 0 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 2 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 7, 21 + 1 * 58);
	}
	else if (i_Button_pressed_before == 53) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 1 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 3 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 5, 21 + 3 * 58);
	}
	else if (i_Button_pressed_before == 54) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 2 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 4 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 5, 21 + 3 * 58);
	}
	else if (i_Button_pressed_before == 55) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 3 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 5 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 7, 21 + 5 * 58);
	}
	else if (i_Button_pressed_before == 56) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 4 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 6 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 7, 21 + 5 * 58);
	}
	else if (i_Button_pressed_before == 57) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 5 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 7 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 5, 21 + 7 * 58);
	}
	else if (i_Button_pressed_before == 58) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 6 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 5, 21 + 7 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 7, 21 + 8 * 58);
	}
	else if (i_Button_pressed_before == 60) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 0 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 1 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 1 * 58);
	}
	else if (i_Button_pressed_before == 64) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 4 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 5 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 4 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 5 * 58);
	}
	else if (i_Button_pressed_before == 67) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 6, 51 + 7 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 7 * 58);
	}
	else if (i_Button_pressed_before == 69) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 7, 21 + 1 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 2 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 9, 21 + 2 * 58);
	}
	else if (i_Button_pressed_before == 70) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 1 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 3 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 9, 21 + 2 * 58);
	}
	else if (i_Button_pressed_before == 71) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 2 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 4 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 9, 21 + 4 * 58);
	}
	else if (i_Button_pressed_before == 72) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 7, 21 + 5 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 3 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 5 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 9, 21 + 4 * 58);
	}
	else if (i_Button_pressed_before == 73) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 7, 21 + 5 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 4 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 6 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 9, 21 + 6 * 58);
	}
	else if (i_Button_pressed_before == 74) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 5 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 7 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 9, 21 + 6 * 58);
	}
	else if (i_Button_pressed_before == 75) {

		m_png_Light_Map.Draw(dc, 17 + 50 * 7, 21 + 8 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 6 * 58);
	}
	else if (i_Button_pressed_before == 78) {
		m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 1 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 2 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 10, 51 + 1 * 58);
		m_png_Light_Map.Draw(dc, 17 + 50 * 10, 51 + 2 * 58);
	}
	else if (i_Button_pressed_before == 80) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 3 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 4 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 10, 51 + 3 * 58);
	}
	else if (i_Button_pressed_before == 82) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 5 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 8, 51 + 6 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 10, 51 + 5 * 58);
	}
	else if (i_Button_pressed_before == 86) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 9, 21 + 2 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 10, 51 + 2 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 11, 21 + 1 * 58);
	}
	else if (i_Button_pressed_before == 87) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 9, 21 + 2 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 10, 51 + 1 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 10, 51 + 3 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 11, 21 + 3 * 58);
	}
	else if (i_Button_pressed_before == 88) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 9, 21 + 4 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 10, 51 + 2 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 11, 21 + 3 * 58);
	}
	else if (i_Button_pressed_before == 90) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 9, 21 + 6 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 11, 21 + 6 * 58);
	}
	else if (i_Button_pressed_before == 94) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 10, 51 + 1 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 12, 51 + 1 * 58);
	}
	else if (i_Button_pressed_before == 96) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 10, 51 + 2 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 10, 51 + 3 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 12, 51 + 2 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 12, 51 + 3 * 58);
	}
	else if (i_Button_pressed_before == 99) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 10, 51 + 5 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 11, 21 + 7 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 12, 51 + 5 * 58);
	}
	else if (i_Button_pressed_before == 100) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 11, 21 + 6 * 58);
	}
	else if (i_Button_pressed_before == 103) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 11, 21 + 1 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 12, 51 + 2 * 58);
	}
	else if (i_Button_pressed_before == 104) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 11, 21 + 3 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 12, 51 + 1 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 12, 51 + 3 * 58);
	}
	else if (i_Button_pressed_before == 105) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 11, 21 + 3 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 12, 51 + 2 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 12, 51 + 4 * 58);
	}
	else if (i_Button_pressed_before == 106) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 12, 51 + 3 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 12, 51 + 5 * 58);
	}
	else if (i_Button_pressed_before == 107) {
	m_png_Light_Map.Draw(dc, 17 + 50 * 11, 21 + 6 * 58);
	m_png_Light_Map.Draw(dc, 17 + 50 * 12, 51 + 4 * 58);
	}
	
	else {
		i_Button_pressed_before = 0;
		i_Button_pressed_after = 0;
	}
	//캐릭터의 좌표에 따라서 구현시키는 함수 구현.
	if (!goodley.GetInno()) {
		goodley.GetXPos() % 2 == 0 ? m_png_Goodley_s.Draw(dc, 32 + 50 * goodley.GetXPos(), 95 + 58 * goodley.GetYPos() - 35) : m_png_Goodley_s.Draw(dc, 32 + 50 * goodley.GetXPos(), 95 + 58 * goodley.GetYPos() - 65);
	}else
		goodley.GetXPos() % 2 == 0 ? m_png_Goodley_i.Draw(dc, 32 + 50 * goodley.GetXPos(), 95 + 58 * goodley.GetYPos() - 35) : m_png_Goodley_i.Draw(dc, 32 + 50 * goodley.GetXPos(), 95 + 58 * goodley.GetYPos() - 65);
	if (!homes.GetInno()) {
		homes.GetXPos() % 2 == 0 ? m_png_Homes_s.Draw(dc, 32 + 50 * homes.GetXPos(), 95 + 58 * homes.GetYPos() - 35) : m_png_Homes_s.Draw(dc, 32 + 50 * homes.GetXPos(), 95 + 58 * homes.GetYPos() - 65);
	}else
		homes.GetXPos() % 2 == 0 ? m_png_Homes_i.Draw(dc, 32 + 50 * homes.GetXPos(), 95 + 58 * homes.GetYPos() - 35) : m_png_Homes_i.Draw(dc, 32 + 50 * homes.GetXPos(), 95 + 58 * homes.GetYPos() - 65);
	if (!jeremy.GetInno()) {
		jeremy.GetXPos() % 2 == 0 ? m_png_Jeremy_s.Draw(dc, 32 + 50 * jeremy.GetXPos(), 95 + 58 * jeremy.GetYPos() - 35) : m_png_Jeremy_s.Draw(dc, 32 + 50 * jeremy.GetXPos(), 95 + 58 * jeremy.GetYPos() - 65);
	}
	else
		jeremy.GetXPos() % 2 == 0 ? m_png_Jeremy_i.Draw(dc, 32 + 50 * jeremy.GetXPos(), 95 + 58 * jeremy.GetYPos() - 35) : m_png_Jeremy_i.Draw(dc, 32 + 50 * jeremy.GetXPos(), 95 + 58 * jeremy.GetYPos() - 65);
	john.GetXPos() % 2 == 0 ? m_png_John_s.Draw(dc, 32 + 50 * john.GetXPos(), 95 + 58 * john.GetYPos() - 35) : m_png_John_s.Draw(dc, 32 + 50 * john.GetXPos(), 95 + 58 * john.GetYPos() - 65);
	if (!lestrade.GetInno()) {
		lestrade.GetXPos() % 2 == 0 ? m_png_Lestrade_s.Draw(dc, 32 + 50 * lestrade.GetXPos(), 95 + 58 * lestrade.GetYPos() - 35) : m_png_Lestrade_s.Draw(dc, 32 + 50 * lestrade.GetXPos(), 95 + 58 * lestrade.GetYPos() - 65);
	}
	else
		lestrade.GetXPos() % 2 == 0 ? m_png_Lestrade_i.Draw(dc, 32 + 50 * lestrade.GetXPos(), 95 + 58 * lestrade.GetYPos() - 35) : m_png_Lestrade_i.Draw(dc, 32 + 50 * lestrade.GetXPos(), 95 + 58 * lestrade.GetYPos() - 65);
	if (!stealthy.GetInno()) {
		stealthy.GetXPos() % 2 == 0 ? m_png_Stealthy_s.Draw(dc, 32 + 50 * stealthy.GetXPos(), 95 + 58 * stealthy.GetYPos() - 35) : m_png_Stealthy_s.Draw(dc, 32 + 50 * stealthy.GetXPos(), 95 + 58 * stealthy.GetYPos() - 65);
	}else
		stealthy.GetXPos() % 2 == 0 ? m_png_Stealthy_i.Draw(dc, 32 + 50 * stealthy.GetXPos(), 95 + 58 * stealthy.GetYPos() - 35) : m_png_Stealthy_i.Draw(dc, 32 + 50 * stealthy.GetXPos(), 95 + 58 * stealthy.GetYPos() - 65);
	if (!watson.GetInno()) {
		watson.GetXPos() % 2 == 0 ? m_png_Watson_s.Draw(dc, 32 + 50 * watson.GetXPos(), 95 + 58 * watson.GetYPos() - 35) : m_png_Watson_s.Draw(dc, 32 + 50 * watson.GetXPos(), 95 + 58 * watson.GetYPos() - 65);
	}else
		watson.GetXPos() % 2 == 0 ? m_png_Watson_i.Draw(dc, 32 + 50 * watson.GetXPos(), 95 + 58 * watson.GetYPos() - 35) : m_png_Watson_i.Draw(dc, 32 + 50 * watson.GetXPos(), 95 + 58 * watson.GetYPos() - 65);
	if (!william.GetInno()) {
		william.GetXPos() % 2 == 0 ? m_png_William_s.Draw(dc, 32 + 50 * william.GetXPos(), 95 + 58 * william.GetYPos() - 35) : m_png_William_s.Draw(dc, 32 + 50 * william.GetXPos(), 95 + 58 * william.GetYPos() - 65);
	}
	else {
		william.GetXPos() % 2 == 0 ? m_png_William_i.Draw(dc, 32 + 50 * william.GetXPos(), 95 + 58 * william.GetYPos() - 35) : m_png_William_i.Draw(dc, 32 + 50 * william.GetXPos(), 95 + 58 * william.GetYPos() - 65);
	}
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
			if (tile[i].i_default_item == 3&&homes.move_count>0) {
				i_Button_pressed_before = i;
			}
			if (tile[i].i_default_item == 4 && watson.move_count >= 0) {
				if (watson.move_count == 0) {
					MessageBox(_T("구역을 선택하세요"));
					i_Button_pressed_before = i;
				}
				else
					i_Button_pressed_before = i;	
			}
			if (tile[i].i_default_item == 5 && john.move_count > 0) {
				i_Button_pressed_before = i;
			}
			if (tile[i].i_default_item == 6 && lestrade.move_count > 0) {
				i_Button_pressed_before = i;
			}
			if (tile[i].i_default_item == 7 && stealthy.move_count > 0) {
				i_Button_pressed_before = i;
			}
			if (tile[i].i_default_item == 8 && william.move_count > 0) {
				i_Button_pressed_before = i;
			}
			if (tile[i].i_default_item == 9 && goodley.move_count > 0) {
				i_Button_pressed_before = i;
			}
			if (tile[i].i_default_item == 10 && jeremy.move_count > 0) {
				i_Button_pressed_before = i;
			}

			Invalidate();
		}
		else if (rect[i].PtInRect(point) && i_Button_pressed_before != 0 && watson.move_count == 0 && tile[i_Button_pressed_before].i_default_item==4) {
			i_Button_pressed_after=i;
			
			if(i_Button_pressed_after-i_Button_pressed_before==-9)
				watson.i_light_pos = -9;
			if (i_Button_pressed_after - i_Button_pressed_before == -8)
				watson.i_light_pos = -8;
			if (i_Button_pressed_after - i_Button_pressed_before == -1)
				watson.i_light_pos = -1;
			if (i_Button_pressed_after - i_Button_pressed_before == 1)
				watson.i_light_pos = 1;
			if (i_Button_pressed_after - i_Button_pressed_before == 8)
				watson.i_light_pos = 8;
			if (i_Button_pressed_after - i_Button_pressed_before == 9)
				watson.i_light_pos = 9;

			i_Button_pressed_before = 0;
			i_Button_pressed_after = 0;
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


/// <summary>
/// 잭을 정하는 함수(서버에서 이미 구현함)
/// </summary>
/// <returns></returns>

inline int CMrJackInLondonInGame::set_Jack()
{
	//return this->gameData.jack;
	/*srand((unsigned int)time(NULL));
	int rand_pick = (rand() % 8) + 1;
	homes.Jack = rand_pick;
	if (rand_pick == 1) {
	homes.b_jack = TRUE;
	CString jack_name=(_T("Shelock Homes"));
	s_is_jack+=jack_name;
	}
	if (rand_pick == 2) {
	watson.b_jack = TRUE;
	CString jack_name = (_T("Watson"));
	s_is_jack += jack_name;
	}
	if (rand_pick == 3) {
	john.b_jack=TRUE;
	CString jack_name = (_T("John Smith"));
	s_is_jack += jack_name;
	}
	if (rand_pick == 4) {
	lestrade.b_jack = TRUE;
	CString jack_name = (_T("Lestrade"));
	s_is_jack += jack_name;
	}
	if (rand_pick == 5) {
	stealthy.b_jack = TRUE;
	CString jack_name = (_T("Stealthy"));
	s_is_jack += jack_name;
	}
	if (rand_pick == 6) {
	william.b_jack = TRUE;
	CString jack_name = (_T("william"));
	s_is_jack += jack_name;
	}
	if (rand_pick == 7) {
	goodley.b_jack = TRUE;
	CString jack_name = (_T("Goodley"));
	s_is_jack += jack_name;
	}
	if (rand_pick == 8) {
	jeremy.b_jack = TRUE;
	CString jack_name = (_T("Jeremy Bert"));
	s_is_jack += jack_name;
	}
	// TODO: 여기에 구현 코드 추가.
	return 0;*/
}

/// <summary>
/// 턴 종료 버튼 클릭 시 수행되는 함수
/// </summary>
void CMrJackInLondonInGame::OnBnClickedIgbTurnend()
{
	//Char좌표: (캐릭터명.p_charpos.x, 캐릭터명.p_charpos.y)
	//
	turn_end();
	round_end();
	CString watson_str;
	watson_str.Format(_T("%d"), watson.i_light_pos);
	round_start();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMrJackInLondonInGame::round_start()
{
	//movecount 리셋.
	
	jeremy.move_count = 3;
	watson.move_count = 3;
	goodley.move_count = 3;
	lestrade.move_count = 3;
	homes.move_count = 3;
	william.move_count = 3;
	john.move_count = 3;
	stealthy.move_count = 4;
	Invalidate();
	// TODO: 여기에 구현 코드 추가.
}


void CMrJackInLondonInGame::round_end()
{
	i_round++;
	// TODO: 여기에 구현 코드 추가.
}


void CMrJackInLondonInGame::turn_end()
{
	//가로등 주의 -> 밝아져랏.
	for (int i = 9; i < 100; i++) {
		if (tile[i].i_default_item == 1&&tile[i].b_switch_on==TRUE) {
			tile[i - 1].onLight = TRUE;
			tile[i + 1].onLight = TRUE;
			tile[i - 9].onLight = TRUE;
			tile[i - 8].onLight = TRUE;
			tile[i + 8].onLight = TRUE;
			tile[i + 9].onLight = TRUE;
		}
		//왓슨도 밝아져라.
		if (tile[i].i_default_item == 4) {
			while (tile[i].i_type_m != 0) {
				if (watson.i_light_pos == 0)
					break;
				i += watson.i_light_pos;
				tile[i].onLight = TRUE;
			}
		}
	}
	for(int i=0;i<110;i++){
		//homes
		if (homes.b_jack == TRUE) {
			int jack1dpos=checkchar1dPos(3);
			if (tile[jack1dpos].onLight == TRUE) {
				for (int i = 0; i < 110; i++) {
					if (tile[i].i_default_item > 2) {
						if (tile[i].onLight == FALSE) {
							if (tile[i].i_default_item == 4)
								watson.setInno();
							else if (tile[i].i_default_item == 5)
								john.setInno();
							else if (tile[i].i_default_item == 6)
								lestrade.setInno();
							else if (tile[i].i_default_item == 7)
								stealthy.setInno();
							else if (tile[i].i_default_item == 8)
								william.setInno();
							else if (tile[i].i_default_item == 9)
								goodley.setInno();
							else if (tile[i].i_default_item == 10)
								jeremy.setInno();
						}
					}
				}
			}
			else {
				for (int i = 0; i < 110; i++) {
					if (tile[i].i_default_item > 2) {
						if (tile[i].onLight == TRUE) {
							if (tile[i].i_default_item == 4)
								watson.setInno();
							else if (tile[i].i_default_item == 5)
								john.setInno();
							else if (tile[i].i_default_item == 6)
								lestrade.setInno();
							else if (tile[i].i_default_item == 7)
								stealthy.setInno();
							else if (tile[i].i_default_item == 8)
								william.setInno();
							else if (tile[i].i_default_item == 9)
								goodley.setInno();
							else if (tile[i].i_default_item == 10)
								jeremy.setInno();
						}
					}
				}
			}
		}
		if (watson.b_jack == TRUE) {
			int jack1dpos = checkchar1dPos(4);
			if (tile[jack1dpos].onLight == TRUE) {
				for (int i = 0; i < 110; i++) {
					if (tile[i].i_default_item > 2) {
						if (tile[i].onLight == FALSE) {
							if (tile[i].i_default_item == 3)
								homes.setInno();
							else if (tile[i].i_default_item == 5)
								john.setInno();
							else if (tile[i].i_default_item == 6)
								lestrade.setInno();
							else if (tile[i].i_default_item == 7)
								stealthy.setInno();
							else if (tile[i].i_default_item == 8)
								william.setInno();
							else if (tile[i].i_default_item == 9)
								goodley.setInno();
							else if (tile[i].i_default_item == 10)
								jeremy.setInno();
						}
					}
				}
			}
			else {
				for (int i = 0; i < 110; i++) {
					if (tile[i].i_default_item > 2) {
						if (tile[i].onLight == TRUE) {
							if (tile[i].i_default_item == 4)
								homes.setInno();
							else if (tile[i].i_default_item == 5)
								john.setInno();
							else if (tile[i].i_default_item == 6)
								lestrade.setInno();
							else if (tile[i].i_default_item == 7)
								stealthy.setInno();
							else if (tile[i].i_default_item == 8)
								william.setInno();
							else if (tile[i].i_default_item == 9)
								goodley.setInno();
							else if (tile[i].i_default_item == 10)
								jeremy.setInno();
						}
					}
				}
			}
		}
		if (john.b_jack == TRUE) {
			int jack1dpos = checkchar1dPos(5);
			if (tile[jack1dpos].onLight == TRUE) {
				for (int i = 0; i < 110; i++) {
					if (tile[i].i_default_item > 2) {
						if (tile[i].onLight == FALSE) {
							if (tile[i].i_default_item == 4)
								watson.setInno();
							else if (tile[i].i_default_item == 3)
								homes.setInno();
							else if (tile[i].i_default_item == 6)
								lestrade.setInno();
							else if (tile[i].i_default_item == 7)
								stealthy.setInno();
							else if (tile[i].i_default_item == 8)
								william.setInno();
							else if (tile[i].i_default_item == 9)
								goodley.setInno();
							else if (tile[i].i_default_item == 10)
								jeremy.setInno();
						}
					}
				}
			}
			else {
				for (int i = 0; i < 110; i++) {
					if (tile[i].i_default_item > 2) {
						if (tile[i].onLight == TRUE) {
							if (tile[i].i_default_item == 4)
								watson.setInno();
							else if (tile[i].i_default_item == 3)
								homes.setInno();
							else if (tile[i].i_default_item == 6)
								lestrade.setInno();
							else if (tile[i].i_default_item == 7)
								stealthy.setInno();
							else if (tile[i].i_default_item == 8)
								william.setInno();
							else if (tile[i].i_default_item == 9)
								goodley.setInno();
							else if (tile[i].i_default_item == 10)
								jeremy.setInno();
						}
					}
				}
			}
		}
		if (lestrade.b_jack == TRUE) {
			int jack1dpos = checkchar1dPos(6);
			if (tile[jack1dpos].onLight == TRUE) {
				for (int i = 0; i < 110; i++) {
					if (tile[i].i_default_item > 2) {
						if (tile[i].onLight == FALSE) {
							if (tile[i].i_default_item == 4)
								watson.setInno();
							else if (tile[i].i_default_item == 3)
								homes.setInno();
							else if (tile[i].i_default_item == 5)
								john.setInno();
							else if (tile[i].i_default_item == 7)
								stealthy.setInno();
							else if (tile[i].i_default_item == 8)
								william.setInno();
							else if (tile[i].i_default_item == 9)
								goodley.setInno();
							else if (tile[i].i_default_item == 10)
								jeremy.setInno();
						}
					}
				}
			}
			else {
				for (int i = 0; i < 110; i++) {
					if (tile[i].i_default_item > 2) {
						if (tile[i].onLight == TRUE) {
							if (tile[i].i_default_item == 4)
								watson.setInno();
							else if (tile[i].i_default_item == 3)
								homes.setInno();
							else if (tile[i].i_default_item == 5)
								john.setInno();
							else if (tile[i].i_default_item == 7)
								stealthy.setInno();
							else if (tile[i].i_default_item == 8)
								william.setInno();
							else if (tile[i].i_default_item == 9)
								goodley.setInno();
							else if (tile[i].i_default_item == 10)
								jeremy.setInno();
						}
					}
				}
			}
		}
		if (stealthy.b_jack == TRUE) {
		int jack1dpos = checkchar1dPos(7);
		if (tile[jack1dpos].onLight == TRUE) {
			for (int i = 0; i < 110; i++) {
				if (tile[i].i_default_item > 2) {
					if (tile[i].onLight == FALSE) {
						if (tile[i].i_default_item == 4)
							watson.setInno();
						else if (tile[i].i_default_item == 5)
							john.setInno();
						else if (tile[i].i_default_item == 6)
							lestrade.setInno();
						else if (tile[i].i_default_item == 3)
							homes.setInno();
						else if (tile[i].i_default_item == 8)
							william.setInno();
						else if (tile[i].i_default_item == 9)
							goodley.setInno();
						else if (tile[i].i_default_item == 10)
							jeremy.setInno();
					}
				}
			}
		}
		else {
			for (int i = 0; i < 110; i++) {
				if (tile[i].i_default_item > 2) {
					if (tile[i].onLight == TRUE) {
						if (tile[i].i_default_item == 4)
							watson.setInno();
						else if (tile[i].i_default_item == 5)
							john.setInno();
						else if (tile[i].i_default_item == 6)
							lestrade.setInno();
						else if (tile[i].i_default_item == 3)
							homes.setInno();
						else if (tile[i].i_default_item == 8)
							william.setInno();
						else if (tile[i].i_default_item == 9)
							goodley.setInno();
						else if (tile[i].i_default_item == 10)
							jeremy.setInno();
					}
				}
			}
		}
	}
		if (william.b_jack == TRUE) {
			int jack1dpos = checkchar1dPos(8);
			if (tile[jack1dpos].onLight == TRUE) {
				for (int i = 0; i < 110; i++) {
					if (tile[i].i_default_item > 2) {
						if (tile[i].i_default_item == 4 && tile[i].onLight == FALSE)
							watson.setInno();
						else if (tile[i].i_default_item == 5 && tile[i].onLight == FALSE)
							john.setInno();
						else if (tile[i].i_default_item == 6 && tile[i].onLight == FALSE)
							lestrade.setInno();
						else if (tile[i].i_default_item == 7 && tile[i].onLight == FALSE)
							stealthy.setInno();
						else if (tile[i].i_default_item == 3 && tile[i].onLight == FALSE)
							homes.setInno();
						else if (tile[i].i_default_item == 9 && tile[i].onLight == FALSE)
							goodley.setInno();
						else if (tile[i].i_default_item == 10 && tile[i].onLight == FALSE)
							jeremy.setInno();
					
					}
				}
			}
			else {
				for (int i = 0; i < 110; i++) {
					if (tile[i].i_default_item > 2) {
						if (tile[i].i_default_item == 4 && tile[i].onLight == TRUE)
							watson.setInno();
						else if (tile[i].i_default_item == 5 && tile[i].onLight == TRUE)
							john.setInno();
						else if (tile[i].i_default_item == 6 && tile[i].onLight == TRUE)
							lestrade.setInno();
						else if (tile[i].i_default_item == 7 && tile[i].onLight == TRUE)
							stealthy.setInno();
						else if (tile[i].i_default_item == 3&& tile[i].onLight == TRUE)
							homes.setInno();
						else if (tile[i].i_default_item == 9 && tile[i].onLight == TRUE)
							goodley.setInno();
						else if (tile[i].i_default_item == 10 && tile[i].onLight == TRUE)
							jeremy.setInno();
					}
				}
			}
		}
		if (goodley.b_jack == TRUE) {
			int jack1dpos = checkchar1dPos(9);
			if (tile[jack1dpos].onLight == TRUE) {
				for (int i = 0; i < 110; i++) {
					if (tile[i].i_default_item > 2) {
						if (tile[i].i_default_item == 4 && tile[i].onLight == FALSE)
							watson.setInno();
						else if (tile[i].i_default_item == 5 && tile[i].onLight == FALSE)
							john.setInno();
						else if (tile[i].i_default_item == 6 && tile[i].onLight == FALSE)
							lestrade.setInno();
						else if (tile[i].i_default_item == 7 && tile[i].onLight == FALSE)
							stealthy.setInno();
						else if (tile[i].i_default_item == 8 && tile[i].onLight == FALSE)
							william.setInno();
						else if (tile[i].i_default_item == 3 && tile[i].onLight == FALSE)
							homes.setInno();
						else if (tile[i].i_default_item == 10 && tile[i].onLight == FALSE)
							jeremy.setInno();
					}
				}
			}
			else {
				for (int i = 0; i < 110; i++) {
					if (tile[i].i_default_item > 2) {
						if (tile[i].onLight == TRUE) {
							if (tile[i].i_default_item == 4)
								watson.setInno();
							else if (tile[i].i_default_item == 5)
								john.setInno();
							else if (tile[i].i_default_item == 6)
								lestrade.setInno();
							else if (tile[i].i_default_item == 7)
								stealthy.setInno();
							else if (tile[i].i_default_item == 8)
								william.setInno();
							else if (tile[i].i_default_item == 3)
								homes.setInno();
							else if (tile[i].i_default_item == 10)
								jeremy.setInno();
						}
					}
				}
			}
		}
		if (jeremy.b_jack == TRUE) {
			int jack1dpos = checkchar1dPos(10);
			if (tile[jack1dpos].onLight == TRUE) {
				for (int i = 0; i < 110; i++) {
					if (tile[i].i_default_item > 2) {
						if (tile[i].onLight == FALSE) {
							if (tile[i].i_default_item == 4)
								watson.setInno();
							else if (tile[i].i_default_item == 5)
								john.setInno();
							else if (tile[i].i_default_item == 6)
								lestrade.setInno();
							else if (tile[i].i_default_item == 7)
								stealthy.setInno();
							else if (tile[i].i_default_item == 8)
								william.setInno();
							else if (tile[i].i_default_item == 9)
								goodley.setInno();
							else if (tile[i].i_default_item == 3)
								homes.setInno();
						}
					}
				}
			}
			else {
				for (int i = 0; i < 110; i++) {
					if (tile[i].i_default_item > 2) {
						if (tile[i].onLight == TRUE) {
							if (tile[i].i_default_item == 4)
								watson.setInno();
							else if (tile[i].i_default_item == 5)
								john.setInno();
							else if (tile[i].i_default_item == 6)
								lestrade.setInno();
							else if (tile[i].i_default_item == 7)
								stealthy.setInno();
							else if (tile[i].i_default_item == 8)
								william.setInno();
							else if (tile[i].i_default_item == 9)
								goodley.setInno();
							else if (tile[i].i_default_item == 3)
								homes.setInno();
						}
					}
				}
			}
		}
	}

	if (goodley.GetInno()) {
		MessageBox(_T("구들리 시민"));
	}
	if (stealthy.GetInno()) {
		MessageBox(_T("stealthy 시민"));
	}
	if (homes.GetInno()) {
		MessageBox(_T("homes 시민"));
	}
	if (jeremy.GetInno()) {
		MessageBox(_T("jeremy 시민"));
	}
	if (john.GetInno()) {
		MessageBox(_T("john 시민"));
	}
	if (william.GetInno()) {
		MessageBox(_T("william 시민"));
	}
	if (lestrade.GetInno()) {
		MessageBox(_T("lestrade 시민"));
	}
	if (watson.GetInno()) {
		MessageBox(_T("watson 시민"));
	}
	

	// TODO: 여기에 구현 코드 추가.
}




int CMrJackInLondonInGame::checkchar1dPos(int index)
{
	for (int i = 0; i < 110; i++) {
		if (tile[i].i_default_item == index)
			return i;
	}
	// TODO: 여기에 구현 코드 추가.
	return 0;
}
