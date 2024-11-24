#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address
{
    private:
        std::string street;
        std::string city;
        std::string state;
        size_t zipCode;

    public:
        //Declaring constructors.
        Address();
        Address(const std::string&, const std::string&, const std::string&, const size_t&);

        //Declaring setters and getters
        void setStreet(const std::string&);
        std::string getStreet();
        void setCity(const std::string&);
        std::string getCity();
        void setState(const std::string&);
        std::string getState();
        void setZip(const size_t&);
        size_t getZip();

        friend std::istream& operator >> (std::istream& is, Address& address);
        friend std::ostream& operator << (std::ostream& os, Address& address);
       
        

};

#endif
