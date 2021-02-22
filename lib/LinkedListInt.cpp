#include <iostream>
using namespace std;

class NodeInt { 
public: 
    int* data; 
    NodeInt* next; 
}; 

class LinkedListInt
{
private:
    NodeInt *head, *tail;
    int _size;
public:
    LinkedListInt();
    ~LinkedListInt();
    void createNode(int *i);
    void removeNode(int *i);
    int* getSize();
    NodeInt* getHead();
    int* removeFirst();
    void doStuff();
};

LinkedListInt::LinkedListInt() {
    head = nullptr;
    tail = nullptr;
    _size = 0;
}

LinkedListInt::~LinkedListInt() {
    
}

void LinkedListInt::createNode(int *i){
    NodeInt *temp = new NodeInt();
    temp->data = i;
    temp->next = nullptr;
    if(head == nullptr){
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    temp = nullptr;
    _size++;
    cout << i << endl;

}

// is this right with only 1 or 2 nodes?
void LinkedListInt::removeNode(int *i){
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
    _size--;
    //delete temp;
}
NodeInt* LinkedListInt::getHead(){
    return head;
}

int* LinkedListInt::getSize(){
    return &_size;
}

int* LinkedListInt::removeFirst(){
    NodeInt* node = head;
    head = node->next;
    int *i = node->data;
    delete node;
    return i;
}

void LinkedListInt::doStuff(){
    cout << "someStuf" << endl;
}
