#include "../constants/processStates.cpp"
#include <vector>

using namespace std;

class PCB
{
private:
    int _state;
    PCB* _parent;
    vector<PCB*> _children;
    int _resources;
    int _priority;


public:
    PCB(int priority);
    ~PCB();
    int test();
};

PCB::PCB(int priority)
{
    _state = READY;
    _priority = priority;
    
}

PCB::~PCB()
{
}
