
#ifndef BUGTRACKERPRO_UTILS_H
#define BUGTRACKERPRO_UTILS_H

#include "UI.h"
#include <limits>
#include <regex>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;
enum SubmitterType {CUSTOMER,EMPLOYEE};



static void displayLineOfStars(int numStars) {
    for (int i = 0; i < numStars; i++) {
        std::cout << "*";
    }
    std::cout << std::endl;
}


// Static variables for ID generation
static int nextCustomerID = 1;
static int nextProductID = 1;
static int nextEmployeeID = 1;
static int nextBugID = 1;
static int nextFeatureID = 1;

// Static functions for ID generation
static int generateCustomerID() {
    return nextCustomerID++;
}

static int generateProductID() {
    return nextProductID++;
}

static int generateEmployeeID() {
    return nextEmployeeID++;
}

static int generateBugID() {
    return nextBugID++;
}

static int generateFeaturesID() {
    return nextFeatureID++;
}

static std::string formatID(int id) {
    std::stringstream ss;
    ss << std::setw(6) << std::setfill('0') << id;
    return ss.str();
}



#endif //BUGTRACKERPRO_UTILS_H
