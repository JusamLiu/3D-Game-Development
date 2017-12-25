#include "NetManager.h"
#include "MsgCenter.h"
#include "NetEventCtrl.h"

NetManager* NetManager::_instance = new NetManager();
NetManager* NetManager::Instance()
{
    return _instance;
}
void NetManager::SendMsg(MsgBase tmpMsg)
{
    if (tmpMsg.GetManager() == ManagerID::Net)
    {
        NetManager::ProcessEvent(tmpMsg);
    }
    else
    {
        MsgCenter::Instance()->SendToMsg(tmpMsg);
    }
}

void NetManager::OnInit()
{
    NetEventCtrl::Instance()->OnInit();
}