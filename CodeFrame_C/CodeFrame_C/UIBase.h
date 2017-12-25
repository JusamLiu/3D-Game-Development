#pragma once
#include "ScriptBase.h"
#include "UIManager.h"
#include "MsgBase.h"

class UIBase :public ScriptBase
{
public:
    //unsigned short [100];

    inline void RegistSelf(ScriptBase* event, unsigned short msgs[])
    {
        UIManager::Instance()->ResgisterMsg(event, msgs);
    }

    inline void UnRegistSelf(ScriptBase event, unsigned short msgs[])
    {
        UIManager::Instance()->UnResgisterMsg(event, msgs);
    }

    inline void SendMsg(MsgBase msg)
    {
        UIManager::Instance()->SendMsg(msg);
    }
    int ProcessEvent(MsgBase tmpMsg){ return -1; };
};
