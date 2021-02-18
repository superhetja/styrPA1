using namespace std;
class RCB
{
private:
    bool _state; //true if free else false
    LinkedList *_waitlist; //TODO fix coorect value
public:
    RCB();
    ~RCB();
    void addToWaitList(PCB *process);
    void removeFromWaitList();
    bool isFree();
    void changeState();
};

RCB::RCB()
{
    _state = true;
    _waitlist = new LinkedList();
}

RCB::~RCB()
{
}

void RCB::addToWaitList(PCB *process){
    _waitlist->createNode(process);
}

bool RCB::isFree(){
    return this->_state;
}

void RCB::removeFromWaitList(){
    _waitlist->removeNode();
}

void RCB::changeState(){
    _state = !_state;
}