#include "queue"
#include "iostream"
#include "./lib/LinkedListInt.cpp"
using namespace std; 

int main(){
  
  LinkedListInt *a = new LinkedListInt();
  a->createNode(new int(3));
  a->createNode(new int(4));
  a->createNode(new int(7));
  a->removeFirst();
  NodeInt* haus = a->getHead();
  cout << *haus->data <<endl;
  haus = haus->next;
  cout << *haus->data <<endl;
  cout << a->hasElement(new int(3))<< endl;
  


  return 0;
}
