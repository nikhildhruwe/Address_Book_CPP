#pragma once
#include <iostream>
using namespace std;

class PersonDetails{
    public :
        string firstName, lastName, address, city, state, phone;
        int zip;
        
        PersonDetails(string firstName, string lastName, string  address, string  city, string  state, int zip, string phone);
};