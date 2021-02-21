using namespace std;
class RCB
{
private:
    bool _state; //true if free else false
    queue<PCB*> *_waitlist; //TODO fix coorect value
public:
    RCB();
    ~RCB();
    void addToWaitList(PCB *process);
    void removeFromWaitList();
    bool isFree();
    void changeState();
    friend ostream& operator<<(ostream& out, const RCB *rcb);
    
};

RCB::RCB()
{
    _state = true;
    _waitlist = NULL;
}

RCB::~RCB()
{
}

void RCB::addToWaitList(PCB *process){
    _waitlist->push(process);
}

bool RCB::isFree(){
    return this->_state;
}

void RCB::removeFromWaitList(){
    _waitlist->pop();
}

void RCB::changeState(){
    _state = !_state;
}

ostream& operator<<(ostream& out, const RCB *rcb){
    out << "RCB state: (";
    out << rcb->_state;
    out << ")";
    return out;
}