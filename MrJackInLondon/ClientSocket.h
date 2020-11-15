#pragma once

// CClientSocket 명령 대상

class CClientSocket : public CSocket
{
private:
	SOCKET sock;
public:
	CClientSocket();
	virtual ~CClientSocket();
	int SetClientSocket();
};


