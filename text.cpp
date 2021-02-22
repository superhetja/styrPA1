#include "queue"
#include "iostream"
#include "./lib/LinkedListInt.cpp"
using namespace std; 

int main(){
  
  LinkedListInt *a = new LinkedListInt();
  int* three = new int(3);
  int* five = new int(5);
  int* six = new int(6);
  a->createNode(three);
  a->createNode(five);
  a->createNode(six);
  a->removeNode(five);
  a->removeNode(three);
  cout << "here" << endl;
  a->removeNode(six);
  cout << "here" << endl;
  NodeInt* haus = a->getHead();

  


  return 0;
}
