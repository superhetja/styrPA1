#include <iostream>
using namespace std;

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
    void removeNode(int i);
    bool isEmpty();
    NodeInt* getHead();
    int removeFirst();
};

LinkedListInt::LinkedListInt() {
    head = nullptr;
    tail = nullptr;
}

LinkedListInt::~LinkedListInt() {
    
}

void LinkedListInt::createNode(int i){
    NodeInt *temp = new NodeInt();
    temp->data = i;
    temp->next = nullptr;
    cout << "CREATE NODE "<< i <<endl;
    if(head == nullptr){
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    temp = nullptr;
}

// is this right with only 1 or 2 nodes?
void LinkedListInt::removeNode(int i){
    NodeInt *temp = head;
    
    if (temp->data == i) {
        head = temp->next;
        }
    else {
        while (temp->next != nullptr ){
            if (temp->next->data == i){
                NodeInt* node = temp->next;
                if (temp->next == tail){
                    tail = temp;
                    tail->next = nullptr;
                } else {
                    temp->next = temp->next->next;
                }
                delete node;
                break;
            }
            
            temp = temp->next;        
        }
    }
    temp = nullptr;
    //delete temp;
}
NodeInt* LinkedListInt::getHead(){
    return head;
}

bool LinkedListInt::isEmpty(){
    return head == nullptr;
}

int LinkedListInt::removeFirst(){
    NodeInt* node = head;
    head = node->next;
    int i = node->data;
    delete node;
    return i;
}
