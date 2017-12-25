#include "UIManager.h"
#include "MsgCenter.h"
#include "UIEventCtrl.h"


UIManager* UIManager::_instance = new UIManager();
UIManager*UIManager::Instance()
{
    return _instance;
}
void UIManager::SendMsg(MsgBase tmpMsg)
{
    if (tmpMsg.GetManager() == ManagerID::UI)
    {
        UIManager::ProcessEvent(tmpMsg);
    }
    else
    {
        MsgCenter::Instance()->SendToMsg(tmpMsg);
    }
}
void UIManager::OnInit()
{
    UIEventCtrl::Instance()->OnInit();
}