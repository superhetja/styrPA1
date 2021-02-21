#include "../constants/processStates.cpp"
#include <vector>

using namespace std;

class PCB
{
private:
    int _state;
    PCB* _parent;
    queue<PCB*> *_children;
    queue<int*>  *_resources; // index of the rcb
    int _priority;


public:
    PCB(int priority);
    ~PCB();
    int test();
    void setParent(PCB *process);
    void addChild(PCB *process);
    friend ostream& operator<<(ostream& out, const PCB *pcb);
};

PCB::PCB(int priority) {
    _state = READY;
    _priority = priority;
    _resources = NULL;  
    _children = NULL; 
    
}

PCB::~PCB() {

}

void PCB::setParent(PCB *process) {
    _parent = process;
}

void PCB::addChild(PCB *process) {
    _children->push(process);
}

ostream& operator<<(ostream& out, const PCB *pcb){
    out << "PCB data: (";
    out << pcb->_resources;
    out << ")";
    return out;
}