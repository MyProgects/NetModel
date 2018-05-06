#include "NetMgr.h"

NetMgr::NetMgr()
{

}

NetMgr::~NetMgr()
{

}

NetMgr::Initialize()
{

}

NetMgr::Finialize()
{

}

NetMgr::Connect(const char* pIP, int iPort, int iTimeOut, int iBuffSize /* = MIN_BUFFER_SIZE */, int iFlag /* = SF_16BIT_WIN */)
{
	unsigned int hSock;

}

NetMgr::CreateSock(unsigned int& hScok, const char* pIP, int iPort, int iBuffSize, int iFlag, int ForceUDP)
{
	static Handle __Cur_Handle_Index = 0;
	__Cur_Handle_Index++;
	hScok = __Cur_Handle_Index;
}