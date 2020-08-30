#include <iostream>
using namespace std;

class PersonDetails{
    private :
    string firstName, lastName, address, city, state, phone;
    int zip;
    public :
        PersonDetails(string, string, string, string, string, int, string);
        void showDetails();
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

void PersonDetails :: showDetails(){
    cout << "Person Details \n---------------" << endl;
    cout << "NAME: " << firstName << " " << lastName << "\nADDRESS: " << address << "\nCITY: " << city << "\nSTATE: "
    << state << "\nZIP-CODE: " << zip << "\nPHONE: " << phone << endl;

}

int main(){
    cout << "\n\tWelcome to address book problem\n" << endl;
    PersonDetails personObj("Nikhil", "Dhruwe", "Lingampally", "Hyderabad", "Telangana", 500011, "8765432101");
    personObj.showDetails();
}