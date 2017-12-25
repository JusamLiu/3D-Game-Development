#include "UIEventCtrl.h"
#include "ui_msg_def.h"
#include "iostream"
using namespace std;

UIEventCtrl* UIEventCtrl::_instance = new UIEventCtrl();
UIEventCtrl* UIEventCtrl::Instance()
{
    return _instance;
}


int UIEventCtrl::ProcessEvent(MsgBase tmpMsg)
{
    switch (tmpMsg.msgId)
    {
    case UIMsgID::AddBlood:
    {
        cout << "UI_AddBlood" << endl;
    }
        break;
    case BroadCastMsgID::broadTest:
    {
        cout << "UI Received msg from net module!!!" << endl;
    }
        break;
    default:
        break;
    }

    return 1;
}


void UIEventCtrl::OnInit()
{
    unsigned short msgIds[2] = {
        UIMsgID::AddBlood,
        BroadCastMsgID::broadTest,
    };


    RegistSelf(Instance(), msgIds);
}


void UIEventCtrl::OnUpdate()
{
    //Ã¿Ö¡Ë¢ÐÂ


    //DefaultMsg *broadMsg;
    //broadMsg = new DefaultMsg();
    //broadMsg->msgId = BroadCastMsgID::broadTest;
    //SendMsg(*broadMsg);
}

void UIEventCtrl::OnDestroy()
{
    // Ïú»Ù
}