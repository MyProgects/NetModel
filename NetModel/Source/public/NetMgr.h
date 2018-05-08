#pragma once

#include "NetworkDef.h"

typedef unsigned int Handle;

struct HSock
{
	HSock(unsigned int id = 0, void* pInSock = nullptr):dwID(id),pSock(pInSock) {}

	inline bool operator < (const HSock& RSock) const
	{
		if ((pSock < RSock.pSock) || (pSock == RSock.pSock && dwID < RSock.dwID))
		{
			return true;
		}
		return false;
	}

	inline bool operator == (const HSock& RSock) const
	{
		return pSock == RSock.pSock && dwID == RSock.dwID;
	}

	inline bool IsValid() const
	{
		return dwID != 0 && pSock != nullptr;
	}

	unsigned int dwID;
	void* pSock;
};

// 
enum SocketFlag
{
	SF_16BIT_WIN	= (1 << 0),
	SF_32BIT_WIN	= (1 << 1),
	SF_16BIT_LINUX	= (1 << 2),
	SF_32BIT_LINUX	= (1 << 3),
	SF_NO_DELAY		= (1 << 4)
};

enum SendResult
{
	SR_SUCCESS		= 0,
	SR_NET_ERROR	= 1, //网络错误(一般是已经断开了)
	SR_NET_BUSY		= 2, // 网络繁忙(一般是发送缓冲满了)
	SR_NET_CLOSED	= 3,
	SR_PARAM_ERROR	= 4
};

// 网络管理类
class NetMgr
{
public:
	NetMgr();
	~NetMgr();

	bool Initialize();
	void Finialize();

	void Update();

	bool Connect(const char* pIP, int iPort, int iTimeOut, int iBuffSize = MIN_BUFFER_SIZE, int iFlag = SF_16BIT_WIN);
	bool Listen(int iPort, int iNum = 8, int iBuffSize = MIN_BUFFER_SIZE, int iFlag = SF_16BIT_WIN);
	void Disconnect(const HSock& rSock);
	SendResult Send(const HSock& rSock, void* pData, int iSize);
	bool Recv(Handle hSocket, char* pBuff, int BuffSize, int& ByteRecv);
	bool Ping(const char* pIP, std::function<void(bool, int)> fCallback);
	
private:
	bool CreateSock(unsigned int& hScok, const char* pIP, int iPort, int iBuffSize, int iFlag, int ForceUDP);
	void ReleaseSock(unsigned int hSock);
};