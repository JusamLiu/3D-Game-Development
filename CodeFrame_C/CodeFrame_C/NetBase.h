#pragma once
#include "ScriptBase.h"
#include "NetManager.h"
#include "MsgBase.h"

class NetBase :public ScriptBase
{
public:
    //unsigned short [100];

    inline void RegistSelf(ScriptBase* event, unsigned short msgs[])
    {
        NetManager::Instance()->ResgisterMsg(event, msgs);
    }

    inline void UnRegistSelf(ScriptBase event, unsigned short msgs[])
    {
        NetManager::Instance()->UnResgisterMsg(event, msgs);
    }

    inline void SendMsg(MsgBase msg)
    {
        NetManager::Instance()->SendMsg(msg);
    }
    int ProcessEvent(MsgBase tmpMsg){ return -1; };
};
