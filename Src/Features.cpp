
#include "Features.h"
#include <cstring>
#include <iostream>

Features::Features() {};
Features::Features(const std::string& changeID,
                   const std::string& featureDescription,
                   const std::string& featureDate,
                   const std::string& priority,
                   SubmitterType submitterType,
                   const std::string& submitterName)
        :submitterType(submitterType) {

    std::strncpy(this->featureDescription, featureDescription.c_str(), sizeof(this->featureDescription) - 1);
    this->featureDescription[sizeof(this->featureDescription) - 1] = '\0';

    std::strncpy(this->featureDate, featureDate.c_str(), sizeof(this->featureDate) - 1);
    this->featureDate[sizeof(this->featureDate) - 1] = '\0';

    std::strncpy(this->submitterName, submitterName.c_str(), sizeof(this->submitterName) - 1);
    this->submitterName[sizeof(this->submitterName) - 1] = '\0';

    std::strncpy(this->priority, priority.c_str(), sizeof(this->priority) - 1);
    this->priority[sizeof(this->priority) - 1] = '\0';

    std::strncpy(this->changeID, changeID.c_str(), sizeof(this->changeID) - 1);
    this->changeID[sizeof(this->changeID) - 1] = '\0';

}


SubmitterType Features::getSubmitterType() const {
    return submitterType;
}
void Features::setSubmitterType(SubmitterType submitterType) {
    Features::submitterType = submitterType;
}
const char *Features::getPriorityName() const {
    return priority;
}


const char *Features::getSubmitterName() const {
    return submitterName;
}
const char *Features::getFeatureDate() const {
    return featureDate;
}
const char *Features::getFeatureDescription() const {
    return featureDescription;
}

void Features::printDebugInfo() const {
    std::cout << "Feature Debug Info:" << std::endl;
    std::cout << "Change ID: " << changeID << std::endl;
    std::cout << "Description: " << featureDescription << std::endl;
    std::cout << "Date: " << featureDate << std::endl;
    std::cout << "Priority: " << priority << std::endl;
    std::cout << "Submitter Type: " << (submitterType == CUSTOMER ? "Customer" : "Employee") << std::endl;
    std::cout << "Submitter Name: " << submitterName << std::endl;

}