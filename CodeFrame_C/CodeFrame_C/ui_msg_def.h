
enum UIMsgID:unsigned short
{
    Start = ManagerID::UI,
    AddBlood,
    KillBoss ,
    End,
};

enum BroadCastMsgID :unsigned short
{
    Init = ManagerID::BroadCast,
    broadTest,

    Over,
};