#pragma once


// MrJackInLondonInGame_T 대화 상자

class MrJackInLondonInGame_T : public CDialogEx
{
	DECLARE_DYNAMIC(MrJackInLondonInGame_T)

public:
	MrJackInLondonInGame_T(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~MrJackInLondonInGame_T();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_InGame };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
