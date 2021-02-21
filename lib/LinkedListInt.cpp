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
    NodeInt* getHead();
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
void LinkedListInt::removeNode(int i){
    NodeInt *temp = head;
    
    if (temp->data == i) {head = temp->next;}
    else {
        while (temp->next != NULL ){
            if (temp->next->data == i){
                if (temp->next == tail){
                    tail = temp;
                    tail->next = NULL;
                    break;
                }
                else {
                    temp->next = temp->next->next;

                }
            }
            
        temp = temp->next;        
        }
    }
    
    delete temp;
}
    NodeInt* LinkedListInt::getHead(){
        return head;
    }
