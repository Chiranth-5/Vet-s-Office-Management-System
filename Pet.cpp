#include "Pet.h"
#include <iostream>
    using std::cout;
    using std::cin;
    using  std::endl;
#include <iomanip>
    using std::setw;
    using std::setfill;
    using std::right;
    using std::left;
#include<algorithm>
#include<string>

Pet::Pet()
{

}

Pet::Pet(const string& name, const Date& DOB, const int& type, const string& breed)
{
    setName(name);
    this->DOB = DOB;
    setType(type);
    setBreed(breed);
}

void Pet::setName(const string& name)
{
    this->name = name;
    transform(this->name.begin(), this->name.end(), this->name.begin(), toupper);
}

void Pet::setDOB(const int& month, const int& day, const int& year)
{
    Date DOB = Date(month, day, year);
    this->DOB = DOB;
}

void Pet::setType(const int& typeInt)
{
    switch(typeInt)
    {
        case 1:
        {
            this->type = "DOG";
            break;
        }
        case 2:
        {
            this->type = "CAT";
            break;
        }
        case 3:
        {
            this->type = "BIRD";
            break;
        }
        case 4:
        {
            this->type = "SNAKE";
            break;
        }
        default:
        {
            cout << "Enter new type: " << endl;
            getline(cin, this->type);
            transform(type.begin(), type.end(), type.begin(), toupper);
            break;
        }
    }
}

void Pet::setBreed(const string& breed)
{
    this->breed = breed;
    transform(this->breed.begin(), this->breed.end(), this->breed.begin(), toupper);
}

string Pet::getName()
{
    return name;
}

Date Pet::getDOB()
{
    return DOB;
}

string Pet::getType()
{
    return type;
}

string Pet::getBreed()
{
    return breed;
}


std::ostream& operator<<(std::ostream& output, Pet& pet)
{
    output << left << setw(13) << "NAME" << ": " << setw(20) << right << pet.getName() << endl;
    output << left << setw(13) << "DOB" << ": " << setw(20) << right << pet.DOB.dateString();
    cout << endl;
    output << left << setw(13) << "TYPE" << ": " << setw(20) << right << pet.getType() << endl;
    output << left << setw(13) << "BREED" << ": " << setw(20) << right << pet.getBreed() << endl;
    return output;
}

std::istream& operator>>(std::istream& input, Pet& pet)
{
    cout << "Enter pet name: " << endl;
    getline(input, pet.name);
    transform(pet.name.begin(), pet.name.end(), pet.name.begin(), toupper);

    int day;
    int month;
    int year;

    cout << "Enter date of birth\nMonth: " << endl;
    input >> month;
    input.ignore();
    cout << "Day: " << endl;
    input >> day;
    input.ignore();
    cout << "Year: " << endl;
    input >> year;
    input.ignore();

    pet.setDOB(month, day, year);

    int typeInt;
    cout << "Type: " << endl;
    input >> typeInt;
    input.ignore();
    pet.setType(typeInt);

    cout << "Breed: " << endl;
    getline(input, pet.breed);
    transform(pet.breed.begin(), pet.breed.end(), pet.breed.begin(), toupper);

    return input;
}