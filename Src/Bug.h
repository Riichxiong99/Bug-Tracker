#ifndef BUGTRACKERPRO_BUG_H
#define BUGTRACKERPRO_BUG_H

#include <string>
#include "Utils.h"

class Bug {
private:
    char changeID[10];
    char bugDescription[100];
    char bugDate[10];
    char priority[10];

    // For differentiating between customer and Employee
    SubmitterType submitterType;
    char submitterName[100];


public:
    Bug();

    Bug(const std::string&changeID,
        const std::string& bugDescription,
        const std::string& bugDate,
        const std::string& priority,
        SubmitterType submitterType,
        const std::string& submitterName);

    const char *getChangeId() const;

    const char *getBugDescription() const;

    const char *getBugDate() const;

    const char *getPriority() const;

    void printDebugInfo() const;

};


#endif //BUGTRACKERPRO_BUG_H
