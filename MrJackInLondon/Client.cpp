// Client.cpp: 구현 파일
#include "pch.h"
#include "MrJackInLondon.h"
#include "Client.h"

using namespace std;
// CClient

CClient::CClient()
{
	// 초기화를 해야 10093 에러가 발생하지 않는다
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
}

CClient::~CClient()
{
}


// CClient 멤버 함수
