// ClientSocket.cpp: 구현 파일
//

#include "pch.h"
#include "MrJackInLondon.h"
#include "ClientSocket.h"
#include "MrJackInLondonInGame.h"

#define PORT_NUM 18363
#define SERVER_IP "127.0.0.1"

// CClientSocket
CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}

// 소켓 만들고 서버에 연결을 요청
int CClientSocket::SetClientSocket() {
    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);//소켓 생성
    if (sock == -1)
    {
        return -1;
    }

    SOCKADDR_IN serv_addr = { 0 };//소켓 주소
    serv_addr.sin_family = PF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serv_addr.sin_port = htons(PORT_NUM);
    int re = 0;
    re = connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));//연결 요청
    if (re == -1)
    {
        return -1;
    }
}