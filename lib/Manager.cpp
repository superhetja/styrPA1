#include <iostream>

#include "PCB.cpp"
#include "RCB.cpp"
using namespace std;

class Manager
{
private:
    int _myNumber; //how many processes we have
    PCB **processes;
    RCB **resoucres;
    queue<PCB*> *_processes; //PCB queue


    Manager(queue<PCB*> *processes);
    ~Manager();
    void init();
    void destroy();
    void request();
    void release();
    void timeout(); // mögulega annarstaðar
    void scheduler();
    void clearLists();
public:
    void create(int priority);
    void setMyNumber(int myNumber);
};
// Constructor
Manager::Manager(queue<PCB*> *processes)
{
    _processes = processes;
    cout << "Manager was created" << endl;
}
// Deconstructor
Manager::~Manager()
{
    clearLists();
    cout << "Manager was deleted" << endl;
}
//should init all list aand get back to square 0
void Manager::init(){
    processes = new PCB*[16];
    resoucres = new RCB*[4];

    create(0);
}

void Manager::setMyNumber(int myNumber){
    _myNumber = myNumber;
}

void Manager::create(int priority){
    // allocate new PCB[j]
    PCB* myNewPCB = new PCB(priority);
    // insert j into list of children i
    // (j is the new process, i is its parent)

    // parent = i
    // children = NULL
    // resource = NULL
    //insert j into RL (ready list)
    _processes->push(myNewPCB);
    // display "process j created"
}
    // delete myNewPCB

void Manager::clearLists() {
    while(!_processes->empty()) {
        delete _processes->front();
        _processes->pop();
    }
}