#pragma once
#include "ClientSocket.h"
// CListenSocket 명령 대상

class CListenSocket : public CAsyncSocket
{
public:
	CListenSocket();
	virtual ~CListenSocket();
	void OnAccept(int nErrorCode);
	void CloseClientSocket(CClientSocket s_client);
};


