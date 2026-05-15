#include "Product.h"
#include <iostream>
#include <cstring>

#include "Product.h"

Product::Product() {};

Product::Product(const std::string productID, const std::string& productName)
        : bugCount(0), featureCount(0) {

    std::strncpy(this->productID, productID.c_str(), sizeof(this->productID) - 1);
    this->productID[sizeof(this->productID) - 1] = '\0';

    std::strncpy(this->productName, productName.c_str(), sizeof(this->productName) - 1);
    this->productName[sizeof(this->productName) - 1] = '\0';
}

void Product::addBug(const Bug& bug) {
    if (bugCount < maxBugs) {
        bugs[bugCount++] = bug;
    } else {
        std::cerr << "Maximum number of bugs reached (" << maxBugs << ")." << std::endl;
    }
}

void Product::addFeature(const Features& feature) {
    if (featureCount < maxFeatures) {
        features[featureCount++] = feature;
    } else {
        std::cerr << "Maximum number of features reached (" << maxFeatures << ")." << std::endl;
    }
}

void Product::printDebugInfo() const {
    std::cout << "Product Name: " << productName << std::endl;
    std::cout << "Product ID: " << productID << std::endl;
    std::cout << "Number of Bugs: " << bugCount << std::endl;
    for (int i = 0; i < bugCount; ++i) {
        bugs[i].printDebugInfo();
    }
    std::cout << "Number of Features: " << featureCount << std::endl;
    for (int i = 0; i < featureCount; ++i) {
        features[i].printDebugInfo();
    }
}

const char *Product::getProductName() const {
    return productName;
}

const char *Product::getProductId() const {
    return productID;
}



int Product::getFeatureCount() const {
    return featureCount;
}

void Product::setFeatureCount(int featureCount) {
    Product::featureCount = featureCount;
}


void Product::printBugDebugInfo() const {
    for (int i = 0; i < bugCount;i++) {
        bugs[i].printDebugInfo();
    }
    cout << "Bug count is: " << bugCount << endl;
}