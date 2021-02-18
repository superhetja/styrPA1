class NodeRCB { 
public: 
    RCB *data; 
    NodeRCB* next; 
}; 

class LinkedListRCB
{
private:
    NodeRCB *head, *tail;
public:
    LinkedListRCB();
    ~LinkedListRCB();
    void createNode(RCB* process);
    void removeNode();
};

LinkedListRCB::LinkedListRCB() {
    head = NULL;
    tail = NULL;
}

LinkedListRCB::~LinkedListRCB() {
    
}

void LinkedListRCB::createNode(RCB* process){
    NodeRCB *temp = new NodeRCB();
    temp->data = process;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    temp = NULL;
}

// is this right with only 1 or 2 nodes?
void LinkedListRCB::removeNode(){
    NodeRCB *temp = head;
    head = temp->next;
    temp = NULL;
}
