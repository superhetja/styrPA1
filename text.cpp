#include "queue"
#include "iostream"
#include "./lib/LinkedListInt.cpp"
using namespace std; 

int main(){
  
  LinkedListInt *a = new LinkedListInt();
  cout << a->isEmpty() << endl;
  a->createNode(1);
  a->createNode(2);
  a->createNode(3);
  NodeInt* node = a->getHead();
  cout << node->data<< endl;
  cout << node->next->data<< endl;
  cout << node->next->next->data<< endl;
  cout << a->isEmpty() << endl;


  return 0;
}
