using namespace std;
class RCB
{
private:
    bool _state; //true if free else false
    LinkedListInt *_waitlist; 

public:
    RCB();
    ~RCB();
    void addToWaitList(int process);
    void removeProcess(int process);
    bool isFree();
    void changeState();
    friend ostream& operator<<(ostream& out, const RCB *rcb);
    bool hasWaitingProcesses();
    int* popWatingList();
    
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
    _waitlist->createNode(new int(process));
    _waitlist->doStuff();
    int* i = _waitlist->getSize();
    cout << i << endl;
    _waitlist->doStuff();
}

bool RCB::isFree(){
    return this->_state;
}

void RCB::removeProcess(int process){
    _waitlist->removeNode(new int(process));
}

bool RCB::hasWaitingProcesses(){
    cout <<"HERE"<<endl;
    NodeInt* n = _waitlist->getHead();
    cout << n->data<<endl;
    return _waitlist->getSize() != 0;
}

int* RCB::popWatingList(){
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