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
    PersonDetails personObj(firstName, lastName);
    personObj.address = address;
    personObj.city = city;
    personObj.state = state;
    personObj.zip = zip;
    personObj.phone = phone;
    addressBookObj.addPerson(personObj);
}

void displayAddressBook(AddressBook addressBookObj){
    addressBookObj.showPersonDetails(addressBookObj.personDetailsList);  
}

void sortByCityStateOrZip(AddressBook addressBookObj){
    int choice;
    cout << "\n Select to sort by any of the follwing:\n1.City.\n2.State.\n3.Zip." << endl;
    cin >> choice;
    switch (choice){
    case 1:
        addressBookObj.sortByCity();
        break;
    case 2:
        addressBookObj.sortByState();
        break;
    case 3:
        addressBookObj.sortByZip();
        break;    
    default:
        cout << "Invalid Choice." << endl;
        break;
    }
}

void viewByCityAndState(AddressBook addressBookObj){
    string city, state;
    cin.ignore();
    cout << "Enter City : " << endl;
    getline(cin, city);
    cout << "Enter State : " << endl;
    getline(cin, state);
    cout << "\nPerson information with city : " << city << " and state : " << state << endl;
    addressBookObj.viewByCityAndState(city, state);
}

void viewByCityOrState(AddressBook addressBookObj){
    string city, state;
    cin.ignore();
    cout << "Enter City : " << endl;
    getline(cin, city);
    cout << "Enter State : " << endl;
    getline(cin, state);
    cout << "\nPerson information with city : " << city << " or state : " << state << endl;
    addressBookObj.viewByCityOrState(city, state);
}

void displayOptions(){
    bool status = true;
    int choice;
    AddressBook addressBookObj;
    while (status){
        cout <<" Select Options: " << "\n1.Add Person.\n2.Display Details.\n3.Edit Person Details.\n4.Delete Person's Contact."
        "\n5.Sort By Name.\n6.Sort By City / State / Zip.\n7.View Person By City And State.\n8.View Person By City Or State.\n9.Exit" << endl;
        cout << "Enter : ";
        cin >> choice;
        switch (choice){
        case 1:
            system("clear");
            addPersonDetails(addressBookObj);
            cout << endl;
            break;
        case 2:
            system("clear");
            displayAddressBook(addressBookObj);
            cout << endl;
            break;
        case 3:
            system("clear");
            addressBookObj.editPersonDetails();
            break;
        case 4:
            system("clear");
            addressBookObj.deletePersonDetails();
            cout << endl;
            break;
        case 5:
            system("clear");
            addressBookObj.sortByName();
            cout << endl;
            break;
        case 6:
            system("clear");
            sortByCityStateOrZip(addressBookObj);
            cout << endl;
            break;
        case 7:
            system("clear");
            viewByCityAndState(addressBookObj);
            cout << endl;
            break; 
        case 8:
            system("clear");
            viewByCityOrState(addressBookObj);
            cout << endl;
            break;               
        case 9:
            status = false;
            break;
        default:
            system("clear");
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