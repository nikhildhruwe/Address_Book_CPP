#include <iostream>
#include "AddressBook.h"
using namespace std;

void addPersonDetails(AddressBook &addressBookObj){
    string firstName, lastName, address, city, state, phone;
    int zip;
    bool check = false;

    cout << "\nEnter First Name : ";
    cin >> firstName;
    cout << "Enter Last Name : ";
    cin >> lastName;
    check = addressBookObj.isNamePresentInAddressBook(firstName, lastName);
    if (check == true){
        return;
    }
    cin.ignore();
    cout << "Enter Address : ";
    getline(cin, address);
    cout << "Enter City : ";
    getline(cin, city);
    cout << "Enter State : ";
    getline(cin, state);
    cout << "Enter Zip : ";
    cin >> zip;
    cout << "Enter Phone Number : ";
    cin >> phone;
    PersonDetails personObj(firstName, lastName, address, city, state, zip, phone);
    addressBookObj.addPerson(personObj);
}

void displayOptions(){
    bool status = true;
    int choice;
    AddressBook addressBookObj;
    while (status){
        cout <<" Select Options: " << "\n1.Add Person.\n2.Display Details.\n3.Edit Person Details.\n4.Delete Person's Contact\n5.Exit" << endl;
        cin >> choice;
        switch (choice){
        case 1:
            addPersonDetails(addressBookObj);
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