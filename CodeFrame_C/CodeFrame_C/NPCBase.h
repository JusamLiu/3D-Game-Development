#pragma once
#include "ScriptBase.h"
#include "NPCManager.h"
#include "MsgBase.h"

class NPCBase :public ScriptBase
{
public:
    //unsigned short [100];

    inline void RegistSelf(ScriptBase* event, unsigned short msgs[])
    {
        NPCManager::Instance()->ResgisterMsg(event, msgs);
    }

    inline void UnRegistSelf(ScriptBase event, unsigned short msgs[])
    {
        NPCManager::Instance()->UnResgisterMsg(event, msgs);
    }

    inline void SendMsg(MsgBase msg)
    {
        NPCManager::Instance()->SendMsg(msg);
    }
    int ProcessEvent(MsgBase tmpMsg){ return -1; };
};
