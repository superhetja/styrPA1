#include "../constants/processStates.cpp"
#include <vector>

using namespace std;

class PCB
{
private:
    int _state;
    PCB* _parent;
    LinkedListInt *_children;
    LinkedListInt *_resources; // index of the rcb
    int _priority;


public:
    PCB(int priority);
    ~PCB();
    int test();
    void setParent(PCB *process);
    void addChild(PCB *process);
};

PCB::PCB(int priority) {
    _state = READY;
    _priority = priority;
    _resources = new LinkedListInt();  
    _children = new LinkedListInt();
    _parent = NULL; 
    
}

PCB::~PCB() {

}

void PCB::setParent(PCB *process) {
    _parent = process;
}

void PCB::addChild(PCB *process) {
    _children->createNode(process);
}

