#pragma once
#include "MsgBase.h"
#include "ManagerBase.h"

#ifndef _NetManager_H_
#define _NetManager_H_

class NetManager :public ManagerBase
{
public:

    ~NetManager(){};
    void OnInit();
    void SendMsg(MsgBase tmpMsg);
    static NetManager* Instance();
private:
    NetManager(){};
    static NetManager* _instance;
};

#endif