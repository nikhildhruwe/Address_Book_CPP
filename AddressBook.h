#pragma once
#include "Person.h"
#include <vector>
using namespace std;

class AddressBook{
    public :
        vector <PersonDetails> personDetailsList;
        void addPerson(PersonDetails);
        void showPersonDetails(vector<PersonDetails>);
        void editPersonDetails();
        void deletePersonDetails();
        bool isNamePresentInAddressBook(string, string);
        void sortByName();
        void sortByCity();
        void sortByState();
        void sortByZip();
};