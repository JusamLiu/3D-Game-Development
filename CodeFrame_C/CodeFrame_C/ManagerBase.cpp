#include "ManagerBase.h"
ManagerBase::ManagerBase()
{   
    eventTree = new std::map<unsigned short, ScriptNode>();
}

ManagerBase::~ManagerBase()
{
    eventTree->clear();
}
int ManagerBase::ProcessEvent(const MsgBase& tmpMsg)
{
    //策略模式循环执行

    if (eventTree->count(tmpMsg.msgId) == 0)
    {
        return -1;
    }
    else
    {
        ScriptNode tmp = eventTree->at(tmpMsg.msgId);
        while (true)
        {
            tmp.script->ProcessEvent(tmpMsg);
            if (tmp.next == NULL)
            {
                return -1;
            }
            else
            {
                tmp = *(tmp.next);
            }
        }
    }

    /*for (std::map<unsigned short, ScriptNode>::iterator it = eventTree->begin(); it != eventTree->end();++it)
    {
    if (it->first == tmpMsg.msgId)
    {
    it->second.script->ProcessEvent(tmpMsg);
    }
    }*/
    return 1;
}

void ManagerBase::ResgisterMsg(ScriptBase* tmpEvent, const unsigned short msgIds[])
{
    for (int i = 0; i < sizeof(msgIds) / sizeof(msgIds[0]); i++)
    {
        ScriptNode *tmp = new ScriptNode(tmpEvent);
        ResgisterMsg(msgIds[i], *tmp);
    }
}

void ManagerBase::ResgisterMsg(unsigned short id, ScriptNode& node)
{

    if (eventTree->count(id) == 0)
    {
        eventTree->insert(std::map<unsigned short, ScriptNode>::value_type(id,node));
    }
    else
    {
        ScriptNode tmp = eventTree->at(id);
        while (tmp.next != NULL)
        {
            tmp = *(tmp.next);
        }
        tmp.next = &node;
    }

}

void ManagerBase::UnResgisterMsg(unsigned short id, ScriptBase& node)
{
    if (eventTree->count(id))
    {
        return;
    }
    else
    {
        ScriptNode tmp = eventTree->at(id);
        if (tmp.script == &node)
        {
            ScriptNode header = tmp;

            if (header.next != NULL)
            {
                eventTree->at(id) = *tmp.next;
                header.next = NULL;
            }
            else
            {
                eventTree->erase(id);
            }

        }
        else
        {
            while (tmp.next != NULL && tmp.next->script != &node)
            {
                tmp = *tmp.next;
            }

            if (tmp.next->next !=NULL)
            {
                ScriptNode curNode = *(tmp.next);
                tmp.next = curNode.next;
                curNode.next = NULL;
            }
            else
            {
                tmp.next = NULL;
            }
        }
    }
}
void ManagerBase::UnResgisterMsg(ScriptBase& tmpEvent, const unsigned short msgIds[])
{
    for (int i = 0; i < sizeof(msgIds) / sizeof(msgIds[0]); i++)
    {
        UnResgisterMsg(msgIds[i], tmpEvent);
    }
}