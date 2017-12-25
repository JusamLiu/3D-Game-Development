#pragma once
#include "MsgBase.h"
 class ScriptBase
{
public:
    virtual int ProcessEvent(const MsgBase tmpMsg);
    virtual bool operator == (ScriptBase& right);
};