#include "NetMgr.h"

NetMgr::NetMgr()
{

}

NetMgr::~NetMgr()
{

}

bool NetMgr::Initialize()
{
	return true;
}

void NetMgr::Finialize()
{

}

void NetMgr::Update()
{

}

bool NetMgr::Connect(const char* pIP, int iPort, int iTimeOut, int iBuffSize /* = MIN_BUFFER_SIZE */, int iFlag /* = SF_16BIT_WIN */)
{
	unsigned int hSock;

}

void NetMgr::Disconnect(const HSock& rSock)
{

}

bool NetMgr::Listen(int iPort, int iNum /* = 8 */, int iBuffSize /* = MIN_BUFFER_SIZE */, int iFlag /* = SF_16BIT_WIN */)
{

}

SendResult NetMgr::Send(const HSock& rSock, void* pData, int iSize)
{

}

bool NetMgr::Recv(Handle hSocket, char* pBuff, int BuffSize, int& ByteRecv)
{

	return true;
}

bool NetMgr::Ping(const char* pIP, std::function<void(bool, int)> fCallback)
{
	
	return true;
}

NetMgr::CreateSock(unsigned int& hScok, const char* pIP, int iPort, int iBuffSize, int iFlag, int ForceUDP)
{
	static Handle __Cur_Handle_Index = 0;
	__Cur_Handle_Index++;
	hScok = __Cur_Handle_Index;
}

NetMgr::ReleaseSock(unsigned int hSock)
{

}