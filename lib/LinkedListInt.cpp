class NodeInt { 
public: 
    int data; 
    NodeInt* next; 
}; 

class LinkedListInt
{
private:
    NodeInt *head, *tail;
public:
    LinkedListInt();
    ~LinkedListInt();
    void createNode(int i);
    void removeNode();
};

LinkedListInt::LinkedListInt() {
    head = NULL;
    tail = NULL;
}

LinkedListInt::~LinkedListInt() {
    
}

void LinkedListInt::createNode(int i){
    NodeInt *temp = new NodeInt();
    temp->data = i;
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
void LinkedListInt::removeNode(){
    NodeInt *temp = head;
    head = temp->next;
    temp = NULL;
}
