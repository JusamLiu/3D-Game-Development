#pragma once
#include <map>
#include "ScriptBase.h"


class ScriptNode
{
public:
    ScriptBase* script;
    ScriptNode* next;
    inline ScriptNode(ScriptBase* tmpEvent)
    {
        this->script = tmpEvent;
        this->next = NULL;
    }
};

class ManagerBase:public ScriptBase
{
public:
    ManagerBase();
    ~ManagerBase();
    void ResgisterMsg(ScriptBase* tmpEvent, const unsigned short msgIds[]);
    void ResgisterMsg(unsigned short id, ScriptNode& node);

    void UnResgisterMsg(ScriptBase& tmpEvent, const unsigned short msgIds[]);
    void UnResgisterMsg(unsigned short id, ScriptBase& node);

    int ProcessEvent(const MsgBase& tmpMsg);
    std::map<unsigned short, ScriptNode> *eventTree;
};