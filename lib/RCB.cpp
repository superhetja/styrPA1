using namespace std;
class RCB
{
private:
    bool _state; //true if free else false
    LinkedListInt *_waitlist; //TODO fix coorect value
public:
    RCB();
    ~RCB();
    void addToWaitList(PCB *process);
    void removeProcess(PCB *prcess);
    bool isFree();
    void changeState();
    friend ostream& operator<<(ostream& out, const RCB *rcb);
    bool hasWaitingProcesses();
    PCB* popWatingList();
    
};

RCB::RCB()
{
    _state = true;
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
    _waitlist.pop();
}

bool RCB::hasWaitingProcesses(){
    return !_waitlist.size() == 0;
}

PCB* RCB::popWatingList(){
    PCB* j = _waitlist.front();
    _waitlist.pop();
    return j;
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