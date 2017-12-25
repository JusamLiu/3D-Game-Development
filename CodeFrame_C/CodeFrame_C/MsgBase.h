#pragma once
#include "FrameTools.h"
#include <string>
class MsgBase
{
public:
    unsigned short msgId;


    inline ManagerID GetManager()const
    {
        return (ManagerID)((msgId / FrameTools::MsgSpan) * FrameTools::MsgSpan);
    }

    inline MsgBase(){ msgId = 0; };
    inline MsgBase(const unsigned short tmpMsgId){ msgId = tmpMsgId; };
    inline void ChangeEventId(const unsigned short tmpId);
};

class DefaultMsg :public MsgBase
{

};
class StringMsg :public MsgBase
{
public:
    char* msgString;
};

class IntMsg :public MsgBase
{
public:
    int value;
};

class StructMsg:public MsgBase
{
public:
    struct data;
};