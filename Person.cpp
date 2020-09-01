#include "Person.h"

PersonDetails :: PersonDetails(string firstName, string lastName){
    this->firstName = firstName; 
    this->lastName = lastName;
}

void PersonDetails :: displayPersonDetails(){
    cout << "NAME: " << firstName << " " << lastName << ", ADDRESS: " << address << ", CITY: " << city << ", STATE: "
    << state << ", ZIP-CODE: " << zip << ", PHONE: " << phone << endl;    
}