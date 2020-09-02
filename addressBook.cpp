#include "AddressBook.h"

void AddressBook :: addPerson(PersonDetails personObj){   
    personDetailsList.push_back(personObj);
}

void AddressBook ::editPersonDetails(PersonDetails &personObj){
    cout << "Enter Address : ";
    getline(cin, personObj.address);
    cout << "Enter City : ";
    getline(cin, personObj.city);
    cout << "Enter State : ";
    getline(cin, personObj.state);
    cout << "Enter Zip : ";
    cin >> personObj.zip;
    cout << "Enter Phone Number : ";
    cin >> personObj.phone;
}

void AddressBook :: showPersonDetails(vector<PersonDetails> personList){
    cout << "\nPerson Details \n---------------" << endl;
    for (int i = 0; i < personList.size(); i++){
        personList[i].displayPersonDetails();
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
            cout << "Record Found." << endl;
            editPersonDetails(personDetailsList[i]);   
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

bool AddressBook :: isNamePresentInAddressBook(string firstName, string lastName){
   for (int i = 0; i < personDetailsList.size(); i++){
        if  (personDetailsList[i].firstName == firstName && personDetailsList[i].lastName == lastName){
            cout << "Name already present in address book." << endl;
            return true;
        }
   }

    return false;
}

void AddressBook :: sortByName(){
    vector<PersonDetails> sortedList = personDetailsList;
    for (int i = 0; i < sortedList.size()- 1; i++ ){
        for (int j = 0; j < sortedList.size() - i - 1; j++){
            string fullName1 = sortedList[j].firstName + sortedList[j].lastName;
            string fullName2 = sortedList[j + 1].firstName + sortedList[j + 1].lastName;
            if (fullName1 > fullName2)
                swap(sortedList[j], sortedList[j+1]);
        }
    }
}

void AddressBook ::sortByCity(){
    vector<PersonDetails> sortedList = personDetailsList;
      for (int i = 0; i < sortedList.size()- 1; i++ ){
        for (int j = 0; j < sortedList.size() - i - 1; j++){
            if ( sortedList[j].city > sortedList[j + 1].city)
                swap(sortedList[j], sortedList[j+1]);
        }
    }

    showPersonDetails(sortedList);
}

void AddressBook ::sortByState(){
    vector<PersonDetails> sortedList = personDetailsList;
    for (int i = 0; i < sortedList.size()- 1; i++ ){
        for (int j = 0; j < sortedList.size() - i - 1; j++){
            if ( sortedList[j].state > sortedList[j + 1].state)
                swap(sortedList[j], sortedList[j+1]);
        }
    }

    showPersonDetails(sortedList);
}

void AddressBook ::sortByZip(){
    vector<PersonDetails> sortedList = personDetailsList;
    for (int i = 0; i < sortedList.size()- 1; i++ ){
        for (int j = 0; j < sortedList.size() - i - 1; j++){
            if (sortedList[j].zip > sortedList[j+1].zip ){
                swap(sortedList[j], sortedList[j+1]);
            }
        }
    }

    showPersonDetails(sortedList);
}

void AddressBook :: viewByCityAndState(string city, string state){
    int flag = 0;
    cout << endl;
    for (int i = 0; i < personDetailsList.size(); i++ ){
        if (personDetailsList[i].city == city && personDetailsList[i].state == state){
            flag = 1;
            personDetailsList[i].displayPersonDetails();
            cout << endl;
        }
    }

    if (flag != 1)
    cout << "No Such Record Found.";
    cout << endl;
}

void AddressBook :: viewByCityOrState(string city, string state){
    int flag = 0;
    cout << endl;
    for (int i = 0; i < personDetailsList.size(); i++ ){
        if (personDetailsList[i].city == city || personDetailsList[i].state == state){
            flag = 1;
            personDetailsList[i].displayPersonDetails();
            cout << endl;
        }
    }

    if (flag != 1)
    cout << "No Such Record Found.";
    cout << endl;
}