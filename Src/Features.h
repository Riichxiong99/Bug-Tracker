//
// Created by icebankyouu on 7/21/24.
//

#ifndef BUGTRACKERPRO_FEATURES_H
#define BUGTRACKERPRO_FEATURES_H


#include <string>
#include "Utils.h"


class Features {


private:
    char changeID[10];
    char featureDescription[100];
    char featureDate[10];
    char priority[10];

    // For differentiating between customer and Employee
    SubmitterType submitterType;
    char submitterName[100];


public:

    Features();

    Features(const std::string& changeID,
             const std::string& featureDescription,
             const std::string& featureDate,
             const std::string& priority,
             SubmitterType submitterType,
             const std::string& submitterName);



    SubmitterType getSubmitterType() const;

    void setSubmitterType(SubmitterType submitterType);

    const char *getPriorityName() const;

    const char *getSubmitterName() const;

    const char *getFeatureDate() const;

    const char *getFeatureDescription() const;

    void printDebugInfo() const;

};


#endif //BUGTRACKERPRO_FEATURES_H
