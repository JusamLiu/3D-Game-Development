
class FrameTools
{
public:
    static const int MsgSpan = 3000;
};
enum ManagerID
{
    GameManager = 0,
    UI = FrameTools::MsgSpan,
    Audio = FrameTools::MsgSpan * 2,
    NPC = FrameTools::MsgSpan * 3,
    Charactor = FrameTools::MsgSpan * 4,
    Asset = FrameTools::MsgSpan * 5,
    Net = FrameTools::MsgSpan * 6,
    BroadCast = FrameTools::MsgSpan * 7,
};