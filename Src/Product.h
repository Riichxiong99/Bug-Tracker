
#ifndef BUGTRACKERPRO_PRODUCT_H
#define BUGTRACKERPRO_PRODUCT_H

#include "Bug.h"
#include "Features.h"
#include <array>
class Product {


private:
    char productID[10];
    char productName[30];
    static const int maxBugs = 100;
    static const int maxFeatures = 100;
    int bugCount = 0;
    int featureCount = 0;
    std::array<Bug, maxBugs> bugs;
    std::array<Features, maxFeatures> features;

public:
    Product();
    Product(const std::string productID, const std::string& productName);
    void addBug(const Bug& bug);
    void addFeature(const Features& feature);
    const char *getProductName() const;
    const char *getProductId() const;


    int getFeatureCount() const;

    void setFeatureCount(int featureCount);

    void printDebugInfo() const;

    void printBugDebugInfo() const;

};


#endif //BUGTRACKERPRO_PRODUCT_H
