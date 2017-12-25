#include "NetEventCtrl.h"
#include "ui_msg_def.h"
#include "iostream"
using namespace std;

NetEventCtrl* NetEventCtrl::_instance = new NetEventCtrl();
NetEventCtrl* NetEventCtrl::Instance()
{
    return _instance;
}

int NetEventCtrl::ProcessEvent(MsgBase tmpMsg)
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
        cout << "Net Received msg from net module!!!" << endl;
    }
    break;
    default:
        break;
    }

    return 1;
}


void NetEventCtrl::OnInit()
{
    unsigned short msgIds[1] = {
        BroadCastMsgID::broadTest,
    };


    RegistSelf(Instance(), msgIds);
}


void NetEventCtrl::OnUpdate()
{
    //ÿ֡ˢ��
    //�ٶ��յ����Է���������Ϣ
    DefaultMsg *recvMsg = new DefaultMsg();
    recvMsg->msgId = BroadCastMsgID::broadTest;
    SendMsg(*recvMsg);
   
}

void NetEventCtrl::OnDestroy()
{
    // ����
}