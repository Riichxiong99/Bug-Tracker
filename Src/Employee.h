//
// Created by icebankyouu on 7/21/24.
//

#ifndef BUGTRACKERPRO_EMPLOYEE_H
#define BUGTRACKERPRO_EMPLOYEE_H



#include <iostream>

class Employee {

private:
    char name[30];
    char employeeID[10];
    char email[50];
    char phoneNumber[12];
    char department[40];
public:
    // Default constructor
    Employee();

    Employee(const std::string& name,
             const std::string employeeID,
             const std::string& email,
             const std::string& phoneNumber,
             const std::string& department);

    const char *getName() const;

    const char *getEmployeeID() const;

    const char *getEmail() const;

    const char *getPhoneNumber() const;

    const char *getDepartment() const;

    void printDebugInfo();

};


#endif //BUGTRACKERPRO_EMPLOYEE_H
