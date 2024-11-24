#include <iostream>
#include "Address.h"
#include "Pet.h"
#include "Person.h"

int main() {
    try {
        // Test Address
        Address address1;
        std::cout << "Enter Address Details:" << std::endl;
        std::cin >> address1;
        std::cout << "\nAddress Details:" << std::endl;
        std::cout << address1;

        // Test Pet
        Pet pet1;
        std::cout << "\nEnter Pet Details:" << std::endl;
        std::cin >> pet1;
        std::cout << "\nPet Details:" << std::endl;
        std::cout << pet1;

        // Test Person
        Person person1;
        std::cout << "\nEnter Person Details:" << std::endl;
        std::cin >> person1;

        // Add Pet to Person
        std::cout << "\nAdding Pet to Person..." << std::endl;
        person1.addPet();
        
        // Display Person Details
        std::cout << "\nPerson Details:" << std::endl;
        std::cout << person1;

        // Search for a Pet
        std::string searchName;
        std::cout << "\nEnter pet name to search: ";
        std::getline(std::cin, searchName);
        if (person1.searchPet(searchName)) {
            std::cout << "Pet found: " << searchName << std::endl;
        } else {
            std::cout << "Pet not found." << std::endl;
        }

        // Remove a Pet
        person1.deletePet();

        // Display updated Person Details
        std::cout << "\nUpdated Person Details after Deleting a Pet:" << std::endl;
        std::cout << person1;
    }
    catch (const char* errMsg) {
        std::cerr << "Error: " << errMsg << std::endl;
    }

    return 0;
}