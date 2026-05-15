
#include "Bug.h"
#include <iostream>
#include <cstring>

Bug::Bug() {};

Bug::Bug(const std::string& changeID,
         const std::string& bugDescription,
         const std::string& bugDate,
         const std::string& priority,
         SubmitterType submitterType,
         const std::string& submitterName)
        :submitterType(submitterType) {

    std::strncpy(this->changeID, changeID.c_str(), sizeof(this->changeID) - 1);
    this->changeID[sizeof(this->changeID) - 1] = '\0';

    std::strncpy(this->bugDescription, bugDescription.c_str(), sizeof(this->bugDescription) - 1);
    this->bugDescription[sizeof(this->bugDescription) - 1] = '\0';

    std::strncpy(this->bugDate, bugDate.c_str(), sizeof(this->bugDate) - 1);
    this->bugDate[sizeof(this->bugDate) - 1] = '\0';

    std::strncpy(this->priority, priority.c_str(), sizeof(this->priority) - 1);
    this->priority[sizeof(this->priority) - 1] = '\0';

    std::strncpy(this->submitterName, submitterName.c_str(), sizeof(this->submitterName) - 1);
    this->submitterName[sizeof(this->submitterName) - 1] = '\0';
}

const char* Bug::getChangeId() const {
    return changeID;
}



const char *Bug::getBugDescription() const {
    return bugDescription;
}

const char *Bug::getBugDate() const {
    return bugDate;
}

const char *Bug::getPriority() const {
    return priority;
}



void Bug::printDebugInfo() const {

    std::cout << "Bug Debug Info:" << std::endl;
    std::cout << "Change ID: " << changeID << std::endl;
    std::cout << "Description: " << bugDescription << std::endl;
    std::cout << "Date: " << bugDate << std::endl;
    std::cout << "Priority: " << priority << std::endl;
    std::cout << "Submitter Type: " << (submitterType == CUSTOMER ? "Customer" : "Employee") << std::endl;
    std::cout << "Submitter Name: " << submitterName << std::endl;
}