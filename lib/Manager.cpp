#include <iostream>
//#include "queue"
#include "../constants/sizes.cpp"
#include "LinkedListInt.cpp"
#include "PCB.cpp"
#include "LinkedList.cpp"
#include "RCB.cpp"


using namespace std;

class Manager
{
private:
    int _myNumber; //how many processes we have
    queue<PCB*> processes; // was *process
    RCB **resources;
    PCB* running;


public:
    Manager();
    ~Manager();
    void init();
    void destroy(int);
    void request(int);
    void release(int);
    void timeout(); // mögulega annarstaðar
    void scheduler();
    void clearLists();
    void create(int priority);
    void setMyNumber(int myNumber);
};
// Constructor
//should init all list aand get back to square 0
Manager::Manager(){
    running = NULL;
    resources = new RCB*[RCB_SIZE];
    for(int i = 0; i < RCB_SIZE; i++){
        resources[i] = new RCB();
    }
    

    create(0);
}

// Deconstructor
Manager::~Manager()
{
    clearLists();
    cout << "Manager was deleted" << endl;
}

void Manager::setMyNumber(int myNumber){
    _myNumber = myNumber;
}

void Manager::create(int priority){
    // allocate new PCB[j]
    PCB* myNewPCB = new PCB(priority);
    // insert j into list of children i
    // (j is the new process, i is its parent)
    if (!processes.empty()){
        processes.front()->addChild(myNewPCB);
        myNewPCB->setParent(running);
    }
    // parent = i
    // children = NULL
    // resource = NULL
    //insert j into RL (ready list)
    processes.push(myNewPCB);
    // display "process j created"
    cout << "Process " << myNewPCB << " created" << endl;
}
    // delete myNewPCB          <---

void Manager::clearLists() {
    while(!processes.empty()) {
        delete processes.front();
        processes.pop();
    }
}

void Manager::destroy(int integer){
    
    //destroy(j)
    
	//for all k in children of j destroy(k)
	//remove j from parent's list of children
	//remove j from RL or waiting list
	//release all resources of j 
	//free PCB of j
	//display: "n processes destroyed"
    
}

void Manager::request(int integer){
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

void Manager::release(int integer){
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
   //TODO check if running
   processes.push(processes.front());
   processes.pop();
   scheduler();
}

void Manager::scheduler(){
     
    /*
    scheduler()
	find process i currently at the head of RL
	display: "process i running"
    */
   cout << "Process " << processes.front() << " running" << endl;
}

