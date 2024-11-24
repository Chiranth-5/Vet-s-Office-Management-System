#include "Address.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <iomanip>

// Defining constructors
Address::Address()
{
    // a default constructor that takes no parameters.
}

Address::Address(const std::string &lStreet, const std::string &lCity, const std::string &lState, const size_t &lZipCode)
{
    // a parameterized constructor that takes values for each member variable in the above order to create an Address object.
    setStreet(lStreet);
    setCity(lCity);
    setState(lState);
    setZip(lZipCode);
}

// Defining setters and getters for each member variables
void Address::setStreet(const std::string &lStreet)
{
    std::string lStreett = lStreet;
    transform(lStreett.begin(), lStreett.end(), lStreett.begin(), toupper);
    street = lStreett;
}
std::string Address::getStreet()
{
    return street;
}
void Address::setCity(const std::string &lCity)
{
    std::string lCityy = lCity;
    transform(lCityy.begin(), lCityy.end(), lCityy.begin(), toupper);
    city = lCityy;
}
std::string Address::getCity()
{
    return city;
}
void Address::setState(const std::string &lState)
{
    std::string lStatee = lState;
    transform(lStatee.begin(), lStatee.end(), lStatee.begin(), toupper);
    state = lStatee;
}
std::string Address::getState()
{
    return state;
}
void Address::setZip(const size_t &lZipCode)
{
    zipCode = lZipCode;
}
size_t Address::getZip()
{
    return zipCode;
}



//Defining Operator overloading

// The operator>> function takes istream& (for cin) and Address& (for Address object ) as parameters and returns istream& (for cin). 
// It will be declared as a friend of Address class.
// The overloaded >> operator sets the values for all member variables using user input. 
// The Autograder will send inputs in the following sequence. As always, the <> aren't included in the actual inputs. 
// A new line indicates that the enter/return key has been pressed:
// <STREET>
// <CITY>
// <STATE>
// <ZIPCODE>

std::istream& operator >> (std::istream& is, Address& address)
{
    //is >> address.street >> address.city >> address.state >> address.zipCode;
    // std::string inputStreet;
    // std::getline(is, inputStreet);  // Read the street
    // address.setStreet(inputStreet);  //Set the street to upper
    // std::string inputCity;
    // std::getline(is, inputCity);  
    // address.setStreet(inputCity);
    std::getline(is, address.street);
    address.setStreet(address.street);
    std::getline(is, address.city);  
    address.setCity(address.city);  // Read the city
    std::getline(is, address.state); 
    address.setState(address.state);  // Read the state
    is >> address.zipCode; // Read the zipcode
    is.ignore();
    
    return is;
}

// The operator<< function takes ostream& (for cout) and Address& (for Address object ) as parameters and returns ostream& (for cout). 
// The overloaded << operator displays the Address object in format specified below. It will be declared as a friend of Address class.
// the output must match the following format exactly! What is between the <> will be your member variables. 
// Do not include the <> characters in your output. Be sure to end each line.
// The left side of the ':' will be a field of 13 characters, then the colon character ':', 
// then a field of 21 characters for a total of 35 characters.
// STREET       :             <Street>
// CITY         :               <City>
// STATE        :              <State>
// ZIP CODE     :                <zip>

std::ostream& operator << (std::ostream& os, Address& address)
{
    os << std::left << std::setw(13) << "STREET" << ":" << std::setw(21) << std::right << address.street << std::endl;
    os << std::left << std::setw(13) << "CITY" << ":" << std::setw(21) << std::right<< address.city << std::endl;
    os << std::left << std::setw(13) << "STATE" << ":" << std::setw(21) << std::right<< address.state << std::endl;
    os << std::left << std::setw(13) << "ZIP CODE" << ":" << std::setw(21) << std::right<< address.zipCode << std::endl;

    return os;
}