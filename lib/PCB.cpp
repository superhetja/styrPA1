#include "../constants/processStates.cpp"
#include <vector>

using namespace std;

class PCB
{
private:
    bool _state;
    PCB* _parent;
    LinkedListInt *_children;
    LinkedListInt  *_resources; // index of the rcb
    int _priority;
    int _pcbIndex;


public:
    PCB(int priority);
    ~PCB();
    int test();
    void setParent(PCB *process);
    void changeState();
    void setIndex(int i);

    void addChild(int process);
    void addResources(int resource);
    void removeResource(int resource);
    int popChild();
    void removeChild(int integer);

    PCB* getParent();
    LinkedListInt* getResources();

    bool hasResources();
    bool isReady();
    bool hasChildren();
    
    friend ostream& operator<<(ostream& out, const PCB *pcb);
};

PCB::PCB(int priority) {
    // TODO: child and resources = null
    _state = true;
    _priority = priority;
    
}

PCB::~PCB() {

}

bool PCB::isReady(){
    return _state;
}
void PCB::changeState(){
    _state = !_state;
}
void PCB::setParent(PCB *process) {
    _parent = process;
}

void PCB::setIndex(int i){
    _pcbIndex = i;
}

void PCB::addChild(int process) {
    _children->createNode(process);
}

void PCB::addResources(int resource){
    _resources->createNode(resource);
}

void PCB::removeResource(int resource){
    _resources->removeNode(resource);
}



bool PCB::hasChildren(){
    return !_children->isEmpty();
}

bool PCB::hasResources(){
    return !_resources->isEmpty();
}

int PCB::popChild(){
    int p = _children->removeFirst();
    return p;
}

void PCB::removeChild(int integer){
    _children->removeNode(integer);
}

PCB* PCB::getParent(){
    return _parent;
}

LinkedListInt* PCB::getResources(){
    return _resources;
}

ostream& operator<<(ostream& out, const PCB *pcb){
    out << "PCB data: ( state: ";
    out << pcb->_state;
    out << ")";
    return out;
}