#include <iostream>
#include <fstream>
#include "queue"
#include "vector"

#include "lib/Manager.cpp"
#include "constants/priority.cpp"
using namespace std;

void shell(string commands);
string getNextWord(string command);
string getFirstWord(string command);
Manager *manager;

int main(int argc, char *argv[]){
    if (argc > 1){
        ifstream myFile(argv[1]);
        for(string line; getline(myFile, line);){
            //cout << line << endl;
            shell(line);
        }
    }
    return 0;

}

void shell(string commands){
    int integer = 0;
    string command = getFirstWord(commands);
    if (command == string("in")){
        //TODO init()
        cout << "init" << endl;
        manager = new Manager();

    }
    else if (command == string("cr")){
        integer = stoi(getNextWord(commands));
        manager->create(integer);
        cout << "cr" << " " << "Integer: " << integer << endl;
    }
    else if (command == string("de")){
        //TODO destroy()
        integer = stoi(getNextWord(commands));
        manager->destroy(integer);
        cout << "destroy" << endl;
    }
    else if (command == string("rq")){
        //TODO request()
        integer = stoi(getNextWord(commands));
        manager->request(integer);
        cout << "request" << " " << "Integer: " << integer << endl;
    }
    else if (command == string("rl")){
        //TODO release()
        integer = stoi(getNextWord(commands));
        manager->release(integer);
        cout << "release" << " " << "Integer: " << integer << endl;
    }
    else if (command == string("to")){
        //TODO timeout()
        cout << "Timeout" << endl;
    }
    else {
        cout << "-1" << endl;
    }
}

string getNextWord(string command){
    return command.substr(command.find(" ") + 1);
}

string getFirstWord(string command) {
    return command.substr(0, command.find(" "));
}