#include <iostream>
#include <vector>
using namespace std;

class PersonDetails{
    public :
        string firstName, lastName, address, city, state, phone;
        int zip;
    public :
        PersonDetails(string, string, string, string, string, int, string);
};

PersonDetails :: PersonDetails(string firstName, string lastName, string  address, string  city, string  state, int zip, string phone){
    this->firstName = firstName; 
    this->lastName = lastName;
    this->address = address;
    this->city = city;
    this->state = state;
    this->zip = zip;
    this->phone = phone;
}

class AddressBook{
    public :
        void addPersonDetails();
        void showPersonDetails();
};
vector <PersonDetails> personDetailsList;

void AddressBook :: addPersonDetails(){
    string firstName, lastName, address, city, state, phone;
    int zip;

    cout << "\nEnter First Name : ";
    cin >> firstName;
    cout << "Enter Last Name : ";
    cin >> lastName;
    cin.ignore();
    cout << "Enter Address : ";
    getline(cin,address);
    cout << "Enter City : ";
    getline(cin, city);
    cout << "Enter State : ";
    getline(cin, state);
    cout << "Enter Zip : ";
    cin >> zip;
    cout << "Enter Phone Number  :";
    cin >> phone;
    PersonDetails personObj(firstName, lastName, address, city, state, zip, phone);
    personDetailsList.push_back(personObj);
}

void AddressBook :: showPersonDetails(){
    cout << "\nPerson Details \n---------------" << endl;
    for (int i = 0; i < personDetailsList.size(); i++){
    cout << "\nNAME: " << personDetailsList[i].firstName  << " " << personDetailsList[i].lastName << ", ADDRESS: "
     << personDetailsList[i].address << ", CITY: " << personDetailsList[i].city << ", STATE: "<< personDetailsList[i].state <<
    ", ZIP-CODE: " << personDetailsList[i].zip << ", PHONE: " << personDetailsList[i].phone << endl;
    }
}

void displayOptions(){
    bool status = true;
    int choice;
    AddressBook addressBookObj;
    while (status){
        cout <<"  Select Options: " << "\n1.Add Person.\n2.Display Details.\n3.Exit" << endl;
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