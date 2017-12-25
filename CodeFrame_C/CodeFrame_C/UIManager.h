#pragma once
#include "MsgBase.h"
#include "ManagerBase.h"
#ifndef _UIMANAGER_H_
#define _UIMANAGER_H_

class UIManager :public ManagerBase
{
public:
    
    ~UIManager(){};
    void OnInit();
    void SendMsg(MsgBase tmpMsg);
    static UIManager* Instance();
private:
    UIManager(){};
    static UIManager* _instance;
};

#endif