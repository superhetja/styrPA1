class PriorityQueue
{
private:
    LinkedListInt* queue0;
    LinkedListInt* queue1;
    LinkedListInt* queue2;
public:
    PriorityQueue();
    ~PriorityQueue();
    void addProcess(int* index, int priority);
    void removeProcess(int* index, int priority);
    int* getFirst();
    bool isEmpty();
};

PriorityQueue::PriorityQueue()
{
    queue0 = new LinkedListInt();
    queue1 = new LinkedListInt();
    queue2 = new LinkedListInt();
}

PriorityQueue::~PriorityQueue()
{
}

void PriorityQueue::addProcess(int* index, int priority){
    if(priority == 0){
        queue0->createNode(index);
    }
    else if(priority == 1){
        queue1->createNode(index);
    }
    else if(priority == 2){
        queue2->createNode(index);
    }
}

void PriorityQueue::removeProcess(int* index, int priority){
    if(priority == 0){
        queue0->removeNode(index);
    }
    else if(priority == 1){
        queue1->removeNode(index);
    }
    else if(priority == 2){
        queue2->removeNode(index);
    }
}

int* PriorityQueue::getFirst(){
    if (*queue2->getSize() != 0){
        return queue2->getHead()->data;
    }
    else if (*queue1->getSize() != 0){
        return queue1->getHead()->data;
    }
    else {
        return queue0->getHead()->data;
    }
}

bool PriorityQueue::isEmpty(){
    return (*queue2->getSize() == 0) && (*queue1->getSize() == 0) && (*queue0->getSize() == 0);

}