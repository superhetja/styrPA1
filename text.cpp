class Klassi{
public:
  int number;
  int another;
  int* addNumbers();
  Klassi();
};

Klassi::Klassi(){
  number = 0;
  another = 0;
}

int* Klassi::addNumbers(){
  return &number+another;
}
int main() {
  
  Klassi *k = new Klassi();
  k->number = 3;
  k->another = 5;
  
  int *g = k->addNumbers();
  
  int f = 5;
  
  delete g;

  return 0;
}