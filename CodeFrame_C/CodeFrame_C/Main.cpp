#include "MsgCenter.h"
#include "UIEventCtrl.h"
#include "NPCEventCtrl.h"
#include "NetEventCtrl.h"
#include <iostream>
using namespace std;

int main()
{
    MsgCenter::Instance()->OnInit();
    

    NetEventCtrl::Instance()->OnUpdate();
    cout << "Game Over!!" << endl;
    return 0;
}