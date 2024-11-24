#include "Person.h"
#include "Address.h"
#include <iostream>
    using std::cin;
    using std::cout;
    using std::endl;
#include <iomanip>
    using std::setw;
    using std::setfill;
    using std::right;
    using std::left;
#include<algorithm>
#include<string>
#include <vector>
    using std::vector;


Person::Person()
{
    setAddress(Address{"", "", "", 0});
}

Person::Person(const string& firstName, const string& lastName, const Address& address)
{
    setFName(firstName);
    setLName(lastName);
    setAddress(address);
}

Person::Person(const string& firstName, const string& lastName)
{
    setFName(firstName);
    setLName(lastName);
    setAddress(Address{"", "", "", 0});
}

void Person::setFName(const string& firstName)
{
    fName = firstName;
    transform(fName.begin(), fName.end(), fName.begin(), toupper);
}

void Person::setLName(const string& lastName)
{
    lName = lastName;
    transform(lName.begin(), lName.end(), lName.begin(), toupper);
}

void Person::setAddress(const Address& address)
{
    this->address = address;
}

void Person::setStreet(const string& street)
{
    address.setStreet(street);
}

void Person::setCity(const string& city)
{
    address.setCity(city);
}

void Person::setState(const string& state)
{
    address.setState(state);
}

void Person::setZip(const size_t& zipCode)
{
    address.setZip(zipCode);
}

string Person::getFName()
{
    return fName;
}

string Person::getLName()
{
    return lName;
}

Address& Person::getAddress()
{
    return address;
}

vector<Pet*>& Person::getPets()
{
    return pets;
}

bool Person::searchPet(const string& name)
{
    string nameCopy = name;
    transform(nameCopy.begin(), nameCopy.end(), nameCopy.begin(), toupper);
    for (auto pet: pets)
    {
        if (pet->getName() == nameCopy)
        {
            return true;
        }
    }
    return false;
}

void operator+(vector<Pet*>& pets, Pet* petPtr)
{
    pets.push_back(petPtr);
}

void operator-(vector<Pet*>& pets, const string& name)
{
    for (long unsigned int i=0; i < pets.size(); i++)
    {
        if (pets[i]->getName() == name)
        {
            pets.erase(pets.begin() + i);
        }
    }
}

void Person::addPet()
{
    Pet* petPtr = new Pet();
    cin >> *petPtr;
    if (searchPet(petPtr->getName()) == true)
    {
        throw "Pet with same name already exists.";
        return;
    }
    else
    {
        pets + petPtr;
    }

    // Pet* petPtr = new Pet();
    // try {
    //     cin >> *petPtr; // Attempt to get user input
    // }
    // catch (const char* e) {
    //     delete petPtr; // Clean up memory
    //     throw; // Re-throw the exception for the test to catch
    // }
    
    // // Check if a pet with the same name already exists
    // if (searchPet(petPtr->getName()))
    // {
    //     delete petPtr; // Clean up memory if pet exists
    //     throw "Pet with same name already exists.";
    // }
    // else
    // {
    //     pets + petPtr; // Add the pet using the overloaded + operator
    // }

}

void Person::deletePet()
{
    string name;
    cout << "Enter pet name: ";
    getline(cin, name);
    transform(name.begin(), name.end(), name.begin(), toupper);

    if (searchPet(name) == false)
    {
       throw "Pet not found.";
       return;
    }
    else
    {
        pets - name;
    }
}

std::ostream& operator<<(std::ostream& output, Person& person)
{
    output << left << setw(13) << "FIRST NAME" << ": " << setw(20) << right << person.getFName() << endl;
    output << left << setw(13) << "LAST NAME" << ": " << setw(20) << right << person.getLName() << endl;
    output << endl;
    output << left << setw(13) << "ADDRESS" << endl;
    output << person.getAddress();
    output << endl;
    output << left << setw(13) << "PETS LIST" << endl;
    if (person.pets.size() == 0)
    {
        output << "NONE" << endl;
    }
    else
    {
        for (auto pet: person.pets)
        {
            output << *pet;
            output << endl;
        }
    }
    return output;
}

std::istream& operator>>(std::istream& input, Person& person)
{
    cout << "Enter first name: " << endl;
    getline(input, person.fName);
    transform(person.fName.begin(), person.fName.end(), person.fName.begin(), toupper);
    cout << "Enter last name: " << endl;
    getline(input, person.lName);
    transform(person.lName.begin(), person.lName.end(), person.lName.begin(), toupper);
    cout << "Enter address: " << endl;
    input >> person.address;
    return input;
}