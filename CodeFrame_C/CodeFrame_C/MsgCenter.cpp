#include "MsgCenter.h"
#include "ui_msg_def.h"
#include "UIManager.h"
#include "NPCManager.h"
#include "NetManager.h"
MsgCenter* MsgCenter::_instance = new MsgCenter();
MsgCenter* MsgCenter::Instance()
{
    return _instance;
}

void MsgCenter::AnasysisMsg(const MsgBase& tmpMsg)
{
    ManagerID id = tmpMsg.GetManager();
    switch (id)
    {
    case ManagerID::UI:
    {
        UIManager::Instance()->SendMsg(tmpMsg);
    }
    break;
    case ManagerID::NPC:
    {
        NPCManager::Instance()->SendMsg(tmpMsg);
    }
    break;
    case ManagerID::Net:
    {        
        NetManager::Instance()->SendMsg(tmpMsg);
    }
    break;
    case ManagerID::BroadCast:
    {
        MsgCenter::BroadCastMsg(tmpMsg);
    }
        break;
    default:
        break;
    }
}

void MsgCenter::OnInit()
{
    UIManager::Instance()->OnInit();
    NPCManager::Instance()->OnInit();
    NetManager::Instance()->OnInit();
}

void MsgCenter::BroadCastMsg(const MsgBase &tmpMsg)
{   
    // 消息的有差别广播
    switch (tmpMsg.msgId)
    {
    case BroadCastMsgID::broadTest:
    {
        UIManager::Instance()->ProcessEvent(tmpMsg);
        NPCManager::Instance()->ProcessEvent(tmpMsg);
    }
    default:
        break;
    }
}