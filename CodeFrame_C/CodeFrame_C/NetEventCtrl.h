#include "NetBase.h"

#ifndef _NETEventCtrl_H_
#define _NETEventCtrl_H_


class NetEventCtrl :public NetBase
{
public:
    NetEventCtrl(){};
    ~NetEventCtrl(){};
    int ProcessEvent(MsgBase tmpMsg);
    void OnInit();
    void OnUpdate();
    void OnDestroy();
    static NetEventCtrl* Instance();
private:
    static NetEventCtrl* _instance;
};
#endif