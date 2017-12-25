#include "NPCEventCtrl.h"
#include "ui_msg_def.h"
#include "iostream"
using namespace std;

NPCEventCtrl* NPCEventCtrl::_instance = new NPCEventCtrl();
NPCEventCtrl* NPCEventCtrl::Instance()
{
    return _instance;
}

int NPCEventCtrl::ProcessEvent(MsgBase tmpMsg)
{
    switch (tmpMsg.msgId)
    {
    case UIMsgID::AddBlood:
    {
        cout << "NPC_AddBlood" << endl;
    }
    break;
    case BroadCastMsgID::broadTest:
    {
        cout << "NPC Received msg from net module!!!" << endl;
    }
    break;
    default:
        break;
    }

    return 1;
}


void NPCEventCtrl::OnInit()
{
    unsigned short msgIds[2] = {
        UIMsgID::AddBlood,
        BroadCastMsgID::broadTest,
    };


    RegistSelf(Instance(), msgIds);
}


void NPCEventCtrl::OnUpdate()
{
    //Ã¿Ö¡Ë¢ÐÂ
}

void NPCEventCtrl::OnDestroy()
{
    // Ïú»Ù
}