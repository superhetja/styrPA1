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
    int _PCBIndex;


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
    int* popChild();
    void removeChild(int integer);

    PCB* getParent();
    LinkedListInt* getResources();
    int getIndex();

    bool hasResources();
    bool isReady();
    bool hasChildren();
    
    friend ostream& operator<<(ostream& out, const PCB *pcb);
};

PCB::PCB(int priority) {
    // TODO: child and resources = null
    _state = true;
    _priority = priority;
    _children = new LinkedListInt();
    _resources = new LinkedListInt();
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
    _PCBIndex = i;
}

void PCB::addChild(int process) {
    _children->createNode(new int(process));
}

void PCB::addResources(int resource){
    _resources->createNode(new int(resource));
}

void PCB::removeResource(int resource){
    _resources->removeNode(new int(resource));
}



bool PCB::hasChildren(){
    return _children->getSize() != 0;
}

bool PCB::hasResources(){
    return _resources->getSize() != 0;
}

int* PCB::popChild(){
    int* p = _children->removeFirst();
    return p;
}

void PCB::removeChild(int integer){
    _children->removeNode(new int(integer));
}

PCB* PCB::getParent(){
    return _parent;
}

LinkedListInt* PCB::getResources(){
    return _resources;
}

ostream& operator<<(ostream& out, const PCB *pcb){
    out << "PCB( state: ";
    out << pcb->_state;
    out << " index: ";
    out << pcb -> _PCBIndex;
    out << ")";
    return out;
}

int PCB::getIndex(){
    return _PCBIndex;
}