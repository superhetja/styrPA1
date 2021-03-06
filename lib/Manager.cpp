#include <iostream>
#include "queue"
#include "../constants/sizes.cpp"
#include "LinkedListInt.cpp"
#include "PriorityQueue.cpp"
#include "PCB.cpp"
#include "LinkedList.cpp"
#include "RCB.cpp"


using namespace std;

class Manager
{
private:
    int _myNumber; //how many processes we have
    PriorityQueue *readyList; // was *process
    PCB **processes;
    RCB **resources;
    PCB* running;
    queue<int> *availablePCBIndex;


public:
    Manager();
    ~Manager();
    void init();
    void destroy(int);
    int recDestroy(int, int);
    void request(int);
    void release(int);
    void releaseFromProcess(int* resource, int* process);
    void timeout(); // mögulega annarstaðar
    void scheduler();
    void clearLists();
    void create(int priority);
    //void setMyNumber(int myNumber);
};
// Constructor
//should init all list aand get back to square 0
Manager::Manager(){
    _myNumber = 0;
    availablePCBIndex = new queue<int>;
    readyList = new PriorityQueue();

    processes = new PCB*[PCB_SIZE];
    resources = new RCB*[RCB_SIZE];
    for(int i = 0; i < RCB_SIZE; i++){
        resources[i] = new RCB();
    }
    for (int i = 0; i < PCB_SIZE; i++){
        availablePCBIndex->push(i);
    }
    

    create(0);

}

// Deconstructor
Manager::~Manager()
{
    clearLists();
    cout << "Manager was deleted" << endl;
}


void Manager::create(int priority){
    // allocate new PCB[j]
    PCB* myNewPCB = new PCB(priority);
    processes[availablePCBIndex->front()] = myNewPCB;
    myNewPCB->setIndex(availablePCBIndex->front());
    // insert j into list of children i
    // (j is the new process, i is its parent)
    if (!readyList->isEmpty()){
        PCB* parent = processes[*readyList->getFirst()];
        parent->addChild(myNewPCB->getIndex());

        myNewPCB->setParent(parent);
    }
    // parent = i
    // children = NULL
    // resource = NULL
    //insert j into RL (ready list)
    readyList->addProcess(new int(myNewPCB->getIndex()), priority);
    // display "process j created"
    //cout << "Process " << myNewPCB->getIndex() << " created" << endl;
    availablePCBIndex->pop();
    scheduler();
}
    // delete myNewPCB          <---

void Manager::clearLists() {
    while(!readyList->isEmpty()) {
        readyList->removeProcess(readyList->getFirst(), *processes[*readyList->getFirst()]->getPriority());
    }
}


int Manager::recDestroy(int integer, int count){
    PCB* p = processes[integer];
    int* index = new int(integer);
    while(p->hasChildren()){
        count += recDestroy(*p->popChild(), count);
    }
    //p->getParent()->removeChild(integer);
    if(p->isReady()){
        readyList->removeProcess(index, *p->getPriority());
    }/* else {
    
        NodeInt *head = p->getResources()->getHead();
        cout << "inside destroy" << endl;
        while(head != nullptr){
            cout << "whileloop" << endl;
            if(resources[*head->data]->hasWaitingProcess(index)){
                cout << "insdie if" << endl;
                resources[*head->data]->removeProcess(index);
                break;
            }
            head = head->next;
        }

        
    }*/
    //TODO: release all resources of j
    LinkedListInt *ll = p->getResources();
    int* i;
    while(*ll->getSize() != 0){
        i = ll->removeFirst();
        if(!p->isReady()){
            if(resources[*i]->hasWaitingProcess(index)){
                resources[*i]->removeProcess(index);
            } else {
                releaseFromProcess(i, index);
            }
        } else {
            releaseFromProcess(i, index);
        }

    }

	//free PCB of j
    delete processes[integer]; //dont know
    availablePCBIndex->push(integer);
    return 1;
}

void Manager::destroy(int integer){
    
    //destroy(j)
	//for all k in children of j destroy(k)
    if (integer > PCB_SIZE || !processes[integer]){
        cout << -1;
    } else {
        int count = recDestroy(integer, 0);
        scheduler();
    }

    //cout << count << " processes destroyed" << endl;
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
   //check if has resource or on waitlist
    //resoucre 
    if( integer>RCB_SIZE || !resources[integer]){
        cout << -1;
        return;
    }
    int* index = readyList->getFirst();
    PCB* p = processes[*readyList->getFirst()];
    RCB* r = resources[integer];
    if( (!r->hasWaitingProcess(index)) && (!p->hasResource(new int(integer)))){
        if (r->isFree()){
            r->changeState();
            p->addResources(integer);
            //cout << "resource " << integer << " allocated" << endl;
        } else {
            p->changeState();
            r->addToWaitList(index);
            //cout << "process " << p << " blocked" << endl;
            readyList->removeProcess(index, *p->getPriority());
        }
    }
    scheduler();
}

void Manager::release(int integer){
    PCB* p = processes[*readyList->getFirst()];
    int* index = new int(integer);
    if(!p->hasResource(index)){
        cout << -1;
        return;
    }
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
    releaseFromProcess(index, readyList->getFirst());   
   /*
   RCB* r = resources[integer];

   readyList.front()->removeResource(integer);
   if(r->hasWaitingProcesses()){
       PCB* j = r->popWatingList();
       readyList.push(j);
       j->changeState();
       j->addResources(integer);

   } else {
       r->changeState();
   }*/
    // Q: should this be called only when re(r) or also when destroy(p)?
   //cout << "resource " << integer << " realeased" << endl; 
   scheduler();
}

void Manager::releaseFromProcess(int* resource, int* process){
    RCB* r = resources[*resource];
    PCB* p = processes[*process];
    p->removeResource(resource);
    if(r->hasWaitingProcesses()){
        PCB* j = processes[*r->popWatingList()];
        readyList->addProcess(new int(j->getIndex()),*j->getPriority());
        j->changeState();
        j->addResources(*resource);

    } else {
        r->changeState();
    }
}

void Manager::timeout(){
    /*
    timeout()
	move process i from head of RL to end of RL
	scheduler()
    */
   //TODO check if running
   PCB* p = processes[*readyList->getFirst()];
   readyList->addProcess(new int(p->getIndex()), *p->getPriority());
   readyList->removeProcess(new int(p->getIndex()), *p->getPriority());
   scheduler();
}

void Manager::scheduler(){
    /*
    scheduler()
	find process i currently at the head of RL
	display: "process i running"
    */
   //cout << "Process " << *readyList->getFirst() << " running" << endl;;
   cout << *readyList->getFirst() << " ";
}

