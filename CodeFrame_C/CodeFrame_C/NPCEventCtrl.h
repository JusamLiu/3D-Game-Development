#include "NPCBase.h"

#ifndef _NPCEventCtrl_H
#define _NPCEventCtrl_H


class NPCEventCtrl :public NPCBase
{
public:
    NPCEventCtrl(){};
    ~NPCEventCtrl(){};
    int ProcessEvent(MsgBase tmpMsg);
    void OnInit();
    void OnUpdate();
    void OnDestroy();
    static NPCEventCtrl* Instance();
private:
    static NPCEventCtrl* _instance;

};


#endif 