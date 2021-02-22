#include "./lib/LinkedListInt.cpp"

#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    LinkedListInt* head = new LinkedListInt();
    head->createNode(1);
    head->createNode(2);
    head->createNode(3);
    head->removeNode(3);
    NodeInt *haus = head->getHead();
  
    cout << haus->data << endl;
    haus = haus->next;
    cout << haus->data << endl;
    haus = haus->next;
    cout << haus->data << endl;
    haus = haus->next;
    cout << haus->data << endl;
    haus = haus->next;

    


}
