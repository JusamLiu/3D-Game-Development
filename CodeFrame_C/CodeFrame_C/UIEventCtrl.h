#include "UIBase.h"

#ifndef _UIEVENTCTRL_H
#define _UIEVENTCTRL_H


class UIEventCtrl :public UIBase
{
public:
    UIEventCtrl(){};
    ~UIEventCtrl(){};    
    int ProcessEvent(MsgBase tmpMsg);
    void OnInit();
    void OnUpdate();
    void OnDestroy();
    static UIEventCtrl* Instance();
private:
    static UIEventCtrl* _instance;
    
};


#endif // !_UIEVENTCTRL_H