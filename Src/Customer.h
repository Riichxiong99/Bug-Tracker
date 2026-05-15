//
// Created by icebankyouu on 7/21/24.
//

#ifndef BUGTRACKERPRO_CUSTOMER_H
#define BUGTRACKERPRO_CUSTOMER_H

#include <iostream>
#include "Product.h"
#include <array>
class Customer {

private:

    char name[30];
    char customerID[10];
    char email[50];
    char phoneNumber[12];

public:
    // Default constructor
    Customer();
    Customer(const std::string customerID,
             const std::string &name,
             const std::string &email,
             const std::string &phoneNumber);


    const char *getName() const;
    const char *getCustomerId() const;
    const char *getEmail() const;
    const char *getPhoneNumber() const;



    // For debugging purposes
    void printDebugInfo() const;


};


#endif //BUGTRACKERPRO_CUSTOMER_H
