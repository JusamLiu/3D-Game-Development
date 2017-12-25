#pragma once
#include "MsgBase.h"
#include "ManagerBase.h"

#ifndef _NPCManager_H_
#define _NPCManager_H_

class NPCManager :public ManagerBase
{
public:

    ~NPCManager(){};
    void OnInit();
    void SendMsg(MsgBase tmpMsg);
    static NPCManager* Instance();
private:
    NPCManager(){};
    static NPCManager* _instance;
};

#endif