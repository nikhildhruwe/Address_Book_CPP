#pragma once
#include "Person.h"
#include <vector>
using namespace std;

class AddressBook{
    public :
        vector <PersonDetails> personDetailsList;
        void addPerson(PersonDetails);
        void showPersonDetails();
        void editPersonDetails();
        void deletePersonDetails();
        bool isNamePresentInAddressBook(string, string);
};