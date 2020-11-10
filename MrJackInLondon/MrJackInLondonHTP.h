#pragma once


// MrJackInLondonHTP 대화 상자

class MrJackInLondonHTP : public CDialogEx
{
	DECLARE_DYNAMIC(MrJackInLondonHTP)

public:
	MrJackInLondonHTP(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~MrJackInLondonHTP();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HTP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
