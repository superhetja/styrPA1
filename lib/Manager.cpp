#include <iostream>
#include "../constants/sizes.cpp"
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
    processes = new PCB*[PCB_SIZE];
    resoucres = new RCB*[RCB_SIZE];

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

void Manager::destroy(){
    /*
    destroy(j)
	for all k in children of j destroy(k)
	remove j from parent's list of children
	remove j from RL or waiting list
	release all resources of j 
	free PCB of j
	display: "n processes destroyed"
    */
}

void Manager::request(){
    /*
	if state of r is free
		state of r = allocated
		insert r into list of resources if process i
		display: "resource r allocated"
	else
		state of i = blocked
		move i from RL to waitlist of r
		display: "process i blocked"
		scheduler()
    */
}

void Manager::release(){
    /*
	remove r from resources list of process i
	if waitlist of r is empty
		state of r = free
	else 
		move process j from the head of waitlist of r to RL
		state of j = ready
		insert r into resources list of process j
	display: "resource r released"
    */
}

void Manager::timeout(){
    /*
    timeout()
	move process i from head of RL to end of RL
	scheduler()
    */
}

void Manager::scheduler(){
    /*
    scheduler()
	find process i currently at the head of RL
	display: "process i running"
    */
}

