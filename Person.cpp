#include "Person.h"

PersonDetails :: PersonDetails(string firstName, string lastName, string  address, string  city, string  state, int zip, string phone){
    this->firstName = firstName; 
    this->lastName = lastName;
    this->address = address;
    this->city = city;
    this->state = state;
    this->zip = zip;
    this->phone = phone;
}

void PersonDetails :: displayPersonDetails(){
    cout << "NAME: " << firstName << " " << lastName << ", ADDRESS: " << address << ", CITY: " << city << ", STATE: "
    << state << ", ZIP-CODE: " << zip << ", PHONE: " << phone << endl;    
}