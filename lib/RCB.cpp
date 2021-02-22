using namespace std;
class RCB
{
private:
    bool _state; //true if free else false
    LinkedListInt *_waitlist; //TODO fix coorect value

public:
    RCB();
    ~RCB();
    void addToWaitList(int process);
    void removeProcess(int process);
    bool isFree();
    void changeState();
    friend ostream& operator<<(ostream& out, const RCB *rcb);
    bool hasWaitingProcesses();
    int popWatingList();
    
};

RCB::RCB()
{
    _state = true;
    _waitlist = new LinkedListInt();
}

RCB::~RCB()
{
}

void RCB::addToWaitList(int process){
    _waitlist->createNode(process);
}

bool RCB::isFree(){
    return this->_state;
}

void RCB::removeProcess(int process){
    _waitlist->removeNode(process);
}

bool RCB::hasWaitingProcesses(){
    return !_waitlist->isEmpty();
}

int RCB::popWatingList(){
    return _waitlist->removeFirst();
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