#include "ScriptBase.h"

int ScriptBase::ProcessEvent(const MsgBase tmpMsg)
{
    return -1;
}

bool ScriptBase::operator==(ScriptBase &right)
{
    if (*this == right)
    {
        return true;
    }
    return false;
}