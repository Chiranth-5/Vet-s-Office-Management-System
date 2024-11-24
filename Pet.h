// Pet
// // - name : std::string
// // - DOB : Date
// // - type : std::string
// // - breed : std::string
// // +Pet()
// // +Pet(const std::string&, const Date&, const int&, const std::string&)
// // +getName() : std::string
// // +getDOB() : Date
// // +getType() : std::string
// // +getBreed() : std::string
// // +setName(const std::string&) : void
// // +setDOB(const int&, const int&, const int&) : void
// // +setType(const int&) : void
// // +setBreed(const std::string&) : void
// // +operator<<(ostream&, Pet&) : ostream& : friend
// // +operator>>(istream&, Pet&) : istream& : friend

#ifndef PET_H
#define PET_H

#include <string>
// #include <vector>
// #include <iostream>
#include "Date.h"

class Pet
{
    private:
        std::string name;
        Date DOB;
        std::string type;
        std::string breed;
    
    public:
        //Declaring Constructors;
        Pet();
        Pet(const std::string&, const Date&, const int&, const std::string&);

        //Decalring getters and setters
        std::string getName();
        Date getDOB(); 
        std::string getType();
        std::string getBreed();
        void setName(const std::string&);
        void setDOB(const int&, const int&, const int&);
        void setType(const int&);
        void setBreed(const std::string&);

        friend std::ostream& operator << (std::ostream& os, Pet& pet);
        friend std::istream& operator >> (std::istream& is, Pet& pet);

};


#endif