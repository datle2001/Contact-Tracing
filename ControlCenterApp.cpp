#include "ControlCenter.h"
#include <iostream>

const int maxOption = 4;

void printMainMenu() {
    cout << "\t\tMain menu" << endl;
    cout << "1.Search by location and time" << endl;
    cout << "2.Search contacts and secondary contacts" << endl;
    cout << "3.Search common contacts" << endl;
    cout << "4.Exit" << endl<< endl;
}
bool checkCommand(string input) {
    try {
        int returnCommand = stoi(input);
        if (returnCommand > maxOption || returnCommand < 1) {
            throw invalid_argument("");
        }
    }
    catch (exception invalid_argument) {
        cout << "Task # must be between 1 and " + to_string(maxOption) + ".\n\n";
        return false;
    }
    return true;
}
int askCommand() {
    string input; bool done = false;
    do {
        cout << "You want to do task #";
        getline(cin, input);
        done = checkCommand(input);
    } while (!done);

    cout << endl;
    return stoi(input);
}
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c) { return tolower(c); });
    return str;
}
void printGreeting() {
    cout << "Welcome to Control Center App.";
    cout << endl << endl;
}
int main() {
    printGreeting(); 
    ControlCenter c; c.fillCollection();
    while (true) {
        printMainMenu();
        switch (askCommand()) {
        case 1:
            c.askLocationAndTime();
            break;
        case 2:
            c.askContact();
            break;
        case 3:
            c.askList();
            break;
        case 4:
            return 0;
        }
    }
}