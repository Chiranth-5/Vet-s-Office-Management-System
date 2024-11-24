#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <iostream>
#include "Address.h"
#include "Pet.h"

class Person
{
    private:
        std::string fName;
        std::string lName;
        Address address;
        std::vector<Pet*> pets;

    public:
        //Declaring Constructors.
        Person();
        Person(const std::string& firstName, const std::string& lastName, const Address& address);
        Person(const std::string& firstName, const std::string& lastName);
        
        //Declaring Setters and Getters
        void setFName(const std::string&);
        std::string getFName();
        void setLName(const std::string&);
        std::string getLName();
        void setAddress(const Address&);
        Address& getAddress();
        std::vector<Pet*>& getPets();
        void setStreet(const std::string&);
        void setCity(const std::string&);
        void setState(const std::string&);
        void setZip(const size_t&);

        friend void operator + (std::vector<int>& plus, Pet* pet);
        
        friend void operator - (std::vector<int>& vec, const std::string& str);

        friend std::istream& operator >> (std::istream& is, Person& person);
        
        friend std::ostream& operator << (std::ostream& os, Person& person);

        //Decalring Methods
        bool searchPet(const std::string& petName);
        void addPet();
        void deletePet(); 

};

#endif