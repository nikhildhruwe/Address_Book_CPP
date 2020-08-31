#include <iostream>
#include "AddressBook.h"
using namespace std;

void displayOptions(){
    bool status = true;
    int choice;
    AddressBook addressBookObj;
    while (status){
        cout <<" Select Options: " << "\n1.Add Person.\n2.Display Details.\n3.Edit Person Details.\n4.Delete Person's Contact\n5.Exit" << endl;
        cin >> choice;
        switch (choice){
        case 1:
            addressBookObj.addPersonDetails();
            cout << endl;
            break;
        case 2:
            addressBookObj.showPersonDetails();
            cout << endl;
            break;
        case 3:
            addressBookObj.editPersonDetails();
            break;
        case 4:
            addressBookObj.deletePersonDetails();
            cout << endl;
            break;        
        case 5:
            status = false;
            break;
        default:
            cout << "Invalid Choice." << endl;
            break;
        }
    }
}

void welcomeMessage(){
    cout << "\n\tWelcome to address book problem\n" << endl;
}

int main(){
    welcomeMessage();
    displayOptions();
    return 0;
}