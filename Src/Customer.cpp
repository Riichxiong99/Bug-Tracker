#include "Customer.h"
#include <cstring>

Customer::Customer() {};
// Parameterized constructor definition
Customer::Customer(const std::string customerID, const std::string &name, const std::string &email, const std::string &phoneNumber) {
    std::strncpy(this->name, name.c_str(), sizeof(this->name) - 1);
    this->name[sizeof(this->name) - 1] = '\0';

    std::strncpy(this->customerID, customerID.c_str(), sizeof(this->customerID) - 1);
    this->customerID[sizeof(this->customerID) - 1] = '\0';

    std::strncpy(this->email, email.c_str(), sizeof(this->email) - 1);
    this->email[sizeof(this->email) - 1] = '\0';

    std::strncpy(this->phoneNumber, phoneNumber.c_str(), sizeof(this->phoneNumber) - 1);
    this->phoneNumber[sizeof(this->phoneNumber) - 1] = '\0';
}


// Getter functions
const char *Customer::getName() const {
    return name;
}
const char *Customer::getCustomerId() const {
    return customerID;
}

const char *Customer::getEmail() const {
    return email;
}



const char *Customer::getPhoneNumber() const {
    return phoneNumber;
}




void Customer::printDebugInfo() const {
    std::cout << "Customer Debug Info:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Customer ID: " << customerID << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
}
