
#include "Employee.h"
#include <cstring>
Employee::Employee() {};

Employee::Employee(const std::string &name, const std::string employeeID, const std::string &email, const std::string &phoneNumber,
                   const std::string &department) {

    std::strncpy(this->name, name.c_str(), sizeof(this->name) - 1);
    this->name[sizeof(this->name) - 1] = '\0';

    std::strncpy(this->employeeID, employeeID.c_str(), sizeof(this->name) - 1);
    this->employeeID[sizeof(this->employeeID) - 1] = '\0';


    std::strncpy(this->email, email.c_str(), sizeof(this->email) - 1);
    this->email[sizeof(this->email) - 1] = '\0';

    std::strncpy(this->phoneNumber, phoneNumber.c_str(), sizeof(this->phoneNumber) - 1);
    this->phoneNumber[sizeof(this->phoneNumber) - 1] = '\0';

    std::strncpy(this->department,department.c_str(),sizeof(this->department) - 1);
    this->department[sizeof(this->department) - 1] = '\0';
}
void Employee::printDebugInfo()  {
    std::cout << "Customer Debug Info:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Employee ID: " << employeeID << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Department: " << department << std::endl;
}

const char *Employee::getName() const {
    return name;
}

const char *Employee::getEmployeeID() const {
    return employeeID;
}



const char *Employee::getEmail() const {
    return email;
}

const char *Employee::getPhoneNumber() const {
    return phoneNumber;
}

const char *Employee::getDepartment() const {
    return department;
}
