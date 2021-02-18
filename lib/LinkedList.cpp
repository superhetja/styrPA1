class Node { 
public: 
    PCB *data; 
    Node* next; 
}; 

class LinkedList
{
private:
    Node *head, *tail;
public:
    LinkedList();
    ~LinkedList();
    void createNode(PCB* process);
    void removeNode();
};

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
}

LinkedList::~LinkedList() {
    
}

void LinkedList::createNode(PCB* process){
    Node *temp = new Node();
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
void LinkedList::removeNode(){
    Node *temp = head;
    head = temp->next;
    temp = NULL;
}
