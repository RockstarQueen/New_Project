#pragma once
#define PORT 18363
#define PACKET_SIZE 1024
#define IP "---.---.---.---"

// CClient 명령 대상

class CClient : public CSocket
{
public:
	CClient();
	virtual ~CClient();
};


