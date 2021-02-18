#include <iostream>
#include <fstream>
#include "queue"
#include "vector"

#include "lib/Manager.cpp"
#include "constants/priority.cpp"

using namespace std;
string getNextWord(string command);
string getFirstWord(string command);

int main(int argc, char *argv[]){
    /*
    //scope 1 (main)
    if (2>3){
        //scope2 (if)
    }

    cout << "hello world!" << endl;
    printf("Hello again, what is your name?\n");
    string userName = "";
    
    cin >> userName;


    // Multiwords from user input
    getline(cin, userName);

    cout << "Hello " << userName << " Welcome to the jungle" << endl;
    printf("Complete sentence: %s, second word: %sn \n", getFirstWord(userName).c_str(), getNextWord(userName).c_str());
    
   cout << "hello world"<< endl;
   if (argc > 1){
        ifstream myFile(argv[1]);

        for(string line; getline(myFile, line);){
            cout << line << endl;
    }
     }
    
    // Basic class calls

    Manager myMan = Manager();
    cout << myMan.getMyNumber() << endl;
    myMan.setMyNumber(10);
    cout << myMan.getMyNumber() << endl;
   
    Manager myMan2 = Manager();
    cout << myMan2.getMyNumber() << endl;
    myMan2.setMyNumber(1500);
    cout << myMan2.getMyNumber() << endl;
    */
    // calling classes with pointer

    
    // A process descriptor array PCB[16]
    //queue<PCB*> processes;

    
    // A RCB array of size 4
    //queue<RCB*> resources;
    // A RL with priority levels 0, 1, 2
    // An array of 3 elements is good but vector is also good
    //vector<queue<int> > readyList;



    //Manager* myMan = new Manager(&processes);
    //myMan->create(PRIORITY_LOW);
    //PCB* firstValue = processes.front();
    //processes.pop();

    //cout << firstValue << endl;
    return 0;

}

string getNextWord(string command){
    return command.substr(command.find(" ") + 1);
}

string getFirstWord(string command) {
    return command.substr(0, command.find(" "));
}
