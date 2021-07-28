#include <iostream>
#include "User.h"
#include <cctype>
#include "../ControlCenterApp/ControlCenter.h"

const int maxOption = 12;

void printMainMenu() {
    cout << "\t\tMain menu" << endl;
    cout << "1.Add Entries*" << endl;
    cout << "2.Change Entries" << endl;
    cout << "3.Remove Entries" << endl;
    cout << "4.Update Information" << endl;
    cout << "5.Print Your Information" << endl;
    cout << "6.Print Travel Record on any date" << endl;
    cout << "7.Print Contact Record on any date" << endl;
    cout << "8.Print Record on any date" << endl;
    cout << "9.Print All Travel Record" << endl;
    cout << "10.Print All Contact Record" << endl;
    cout << "11.Print All Record" << endl;
    cout << "12.Exit" << endl << endl;
    cout << "*Entries are in-person exchanges you made or places you visited" << endl << endl;
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
string printGreeting() {
    string fullName;
    cout << "Welcome to Contact Tracing App. Your fullname is: ";
    getline(cin, fullName);
    cout << endl;
    cout << "Very nice to serve you, " << fullName << endl << endl;
    return toLower(fullName);
}
int main()
{
    User user(printGreeting());
    ControlCenter controlCenter;
    controlCenter.addUserToCollection(user.getName());
    while (true) {
        printMainMenu();
        switch (askCommand()) {
        case 1:
            user.addRecord();
            break;
        case 2:
            user.changeRecord();
            break;
        case 3:
            user.removeRecord();
            break;
        case 4:
            user.updateInfo();
            break;
        case 5:
            user.printInfo();
            break;
        case 6:
            user.printTravelRecordOn();
            break;
        case 7:
            user.printContactRecordOn();
            break;
        case 8:
            user.printRecordOn();
            break;
        case 9:
            user.printAllTravelRecord();
            break;
        case 10:
            user.printAllContactRecord();
            break;
        case 11:
            user.printAllRecord();
            break;
        case 12:
            user.closeFile();
            return 0;
        }
    }
}










