#include "NPCManager.h"
#include "MsgCenter.h"
#include "NPCEventCtrl.h"

NPCManager* NPCManager::_instance = new NPCManager();
NPCManager* NPCManager::Instance()
{
    return _instance;
}
void NPCManager::SendMsg(MsgBase tmpMsg)
{
    if (tmpMsg.GetManager() == ManagerID::NPC)
    {
        NPCManager::ProcessEvent(tmpMsg);
    }
    else
    {
        MsgCenter::Instance()->SendToMsg(tmpMsg);
    }
}

void NPCManager::OnInit()
{
    NPCEventCtrl::Instance()->OnInit();
}