#pragma once
#define PORT 18363
#define PACKET_SIZE 1024

// CMrJackInLondonMatch 대화 상자

class CMrJackInLondonMatch : public CDialogEx
{
	DECLARE_DYNAMIC(CMrJackInLondonMatch)

public:
	CMrJackInLondonMatch(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMrJackInLondonMatch();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MATCHING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	static void proc_recv();
	CWinThread* m_pThread;
	bool m_isWorkingThread;
	virtual BOOL OnInitDialog();
	SOCKET hSocket;
	char cMsg[PACKET_SIZE] = "";
	char cBuffer[PACKET_SIZE] = "";
};
