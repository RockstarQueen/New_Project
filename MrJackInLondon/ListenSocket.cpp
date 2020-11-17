// CListenSocket.cpp: 구현 파일
//

#include "pch.h"
#include "MrJackInLondon.h"
#include "ListenSocket.h"
#include "ClientSocket.h"
#include "MrJackInLondonInGame.h"

// CListenSocket

CListenSocket::CListenSocket()
{
}

CListenSocket::~CListenSocket()
{
}

// CListenSocket 멤버 함수
void CListenSocket::OnAccept(int nErrorCode) {
	CClientSocket s_client;
	if (Accept(s_client)) {
	}
	else {
		AfxMessageBox(_T("ERROR: Failed to accept nes client!"));
	}

	CAsyncSocket::OnAccept(nErrorCode);
}

/// 특정 클라이언트와의 접속이 종료되었을 때 통신을 끝내고 CCLientSocket 클래스 객체를 소멸
void CListenSocket::CloseClientSocket(CClientSocket s_client) {

}