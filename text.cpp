#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    char *c = new char('k');
    char *k = c;

    cout << "c: " << c << endl;
    cout << "k: " << k << endl;
    delete c;
    cout << "c: " << c << endl;
    cout << "k: " << k << endl;


}
