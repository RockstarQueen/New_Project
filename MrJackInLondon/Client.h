#pragma once
#define PORT 18363
#define PACKET_SIZE 1024
#define IP "172.30.1.10"

#include <fstream>

using namespace std;
// CClient 명령 대상

class CClient : public CSocket
{
public:
	CClient();
	virtual ~CClient();
};