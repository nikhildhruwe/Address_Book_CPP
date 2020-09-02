#include "AddressBook.h"

void AddressBook :: addPerson(PersonDetails personObj){   
    personDetailsList.push_back(personObj);
}

void AddressBook :: showPersonDetails(){
    cout << "\nPerson Details \n---------------" << endl;
    for (int i = 0; i < personDetailsList.size(); i++){
        personDetailsList[i].displayPersonDetails();
        cout << endl;
    }
}

void AddressBook :: editPersonDetails(){
    int flag = 0;
    string firstName, lastName;

    cout << "\nEnter first name : ";
    cin >> firstName;
    cout << "Enter last name : ";
    cin >> lastName;
    for (int i = 0; i < personDetailsList.size(); i++){
        if  (personDetailsList[i].firstName == firstName && personDetailsList[i].lastName == lastName){
            flag = 1;
            cin.ignore();
            cout << "Record Found, Edit the details" << endl;
            cout << "Enter Address : ";
            getline(cin, personDetailsList[i].address);
            cout << "Enter City : ";
            getline(cin, personDetailsList[i].city);
            cout << "Enter State : ";
            getline(cin, personDetailsList[i].state);
            cout << "Enter Zip : ";
            cin >> personDetailsList[i].zip;
            cout << "Enter Phone Number : ";
            cin >> personDetailsList[i].phone;    
        }
    }

    if (flag != 1)
        cout << "No Such Record Found.";
    cout << endl;
}

void AddressBook :: deletePersonDetails(){
    int flag = 0;
    string firstName, lastName;
    vector<PersonDetails> :: iterator personObj;

    cout << "\nEnter first name : ";
    cin >> firstName;
    cout << "Enter last name : ";
    cin >> lastName;
    for (personObj = personDetailsList.begin();  personObj != personDetailsList.end(); personObj++){
        if  (personObj->firstName == firstName && personObj->lastName == lastName){
            flag = 1;
            cout << "Record Found, Deleting persons information from address book." << endl;
            personDetailsList.erase(personObj);
            break;
        }
    }

    if (flag != 1)
        cout << "No Such Record Found.";
    cout << endl;
}