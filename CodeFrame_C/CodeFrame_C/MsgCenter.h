#pragma once
#include "MsgBase.h"

#ifndef _MSGCENTER_H_
#define _MSGCENTER_H_


class MsgCenter
{
public:
    MsgCenter(){};
    ~MsgCenter(){};
    void OnInit();
    inline void SendToMsg(const MsgBase &tmpMsg)
    {
        AnasysisMsg(tmpMsg);
    }

    void BroadCastMsg(const MsgBase &tmpMsg);
    static MsgCenter* Instance();
private:
    static MsgCenter* _instance;
    void AnasysisMsg(const MsgBase &tmpMsg);
};

#endif // !_MSGCENTER_H_