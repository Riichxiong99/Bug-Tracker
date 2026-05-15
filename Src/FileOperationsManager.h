#ifndef BUGTRACKERPRO_FILEOPERATIONSMANAGER_H
#define BUGTRACKERPRO_FILEOPERATIONSMANAGER_H

#include <fstream>
#include "Customer.h"
#include "Employee.h"
#include "Utils.h"
#include "Product.h"
#include <iostream>

using namespace std;

static void initialization() {

    ifstream file1("../data/customers.dat");

    if(!file1) {
        std::fstream customersFile;
        customersFile.open("../data/customers.dat",  ios::in | ios::out | ios::binary | ios::app);
        if (!customersFile.is_open()) {
            cout << "error creating customer file" << endl;
        }
    }
    ifstream file2("../data/employees.dat");

    if (!file2) {
        std::fstream employeesFile;
        employeesFile.open("../data/employees.dat",  ios::in | ios::out | ios::binary | ios::app );
        if (!employeesFile.is_open()) {
            cout << "error creating employee file" << endl;
        }
    }

    ifstream file3("../data/products.dat");

    if (!file3) {
        std::fstream productFile;
        productFile.open("../data/products.dat", ios::in | ios::out | ios::binary | ios::app );
        if (!productFile.is_open()) {
            cout << "error creating product file" << endl;
        }
    }


}


static void writeCustomer(const Customer& customer, fstream& file) {

    if (!file) {
        std::cerr << "File stream is not open." << std::endl;
        return;
    }
    file.seekp(0, std::ios::end);
    file.write(reinterpret_cast<const char*>(&customer),sizeof(Customer));
}

static void writeEmployee(const Employee& employee, fstream& file) {

    if (!file) {
        std::cerr << "File stream is not open for employee writing." << std::endl;
        return;
    }
    file.seekp(0, std::ios::end);
    file.write(reinterpret_cast<const char*>(&employee),sizeof(Employee));
}

static void writeProduct(const Product& product,fstream& file) {

    if(!file) {
        std::cerr << "File stream for write products is not open yet" << endl;
        return;
    }

    file.seekp(0,std::ios::end);
    file.write(reinterpret_cast<const char*>(&product),sizeof(Product));
}


static void writeBug(Bug& bug, std::fstream& file, std::streampos position) {
    if (!file) {
        std::cerr << "File stream is not open." << std::endl;
        return;
    }
    file.seekg(position);
    if (!file.write(reinterpret_cast<char*>(&bug), sizeof(Bug))) {
        std::cerr << "Failed to read customer from file." << std::endl;
    }
}


// Function to return a product object

static Product readProduct(std::fstream& file, long pos) {
    if (!file.is_open()) {
        std::cerr << "Error opening file.\n";
        return Product();
    }

    Product product;
    file.seekg(pos * sizeof(Product), std::ios::beg);

    if (file.fail()) {
        std::cerr << "Error seeking to position.\n";
        file.clear();
        return Product();
    }

    file.read(reinterpret_cast<char *>(&product), sizeof(Product));

    if (file.fail()) {
        std::cerr << "Failed to read product data.\n";
        file.clear();
        return Product();
    }
    return product;
}

static Customer readCustomer(std::fstream& file, long pos) {
    if (!file.is_open()) {
        std::cerr << "Error opening file.\n";
        return Customer();
    }

    Customer customer;
    file.seekg(pos * sizeof(Customer), std::ios::beg);

    if (file.fail()) {
        std::cerr << "Error seeking to position for customer.\n";
        file.clear();
        return Customer();
    }

    file.read(reinterpret_cast<char *>(&customer), sizeof(Customer));

    if (file.fail()) {
        std::cerr << "Failed to read product data.\n";
        file.clear();
        return Customer();
    }
    return customer;
}
static Employee readEmployee(std::fstream& file, long pos) {
    if (!file.is_open()) {
        std::cerr << "Error opening file.\n";
        return Employee();
    }

    Employee employee;
    file.seekg(pos * sizeof(Employee), std::ios::beg);

    if (file.fail()) {
        std::cerr << "Error seeking to position.\n";
        file.clear();
        return Employee();
    }

    file.read(reinterpret_cast<char *>(&employee), sizeof(Employee));

    if (file.fail()) {
        std::cerr << "Failed to read product data.\n";
        file.clear();
        return Employee();
    }
    return employee;
}

static void writeProductBug(Product& product, Bug& bug, std::fstream& file, int position) {
    if (!file) {
        std::cerr << "File stream for write products is not open yet" << std::endl;
        return;
    }

    product.addBug(bug);
    //product.increaseBugCount();

    file.seekp(sizeof(Product) * position, std::ios::beg);
    std::streampos write_pos = file.tellp();
    if (write_pos != sizeof(Product) * position) {
        std::cerr << "Positioning error in file. Expected: " << sizeof(Product) * position << ", Got: " << write_pos << std::endl;
        return;
    }

    file.write(reinterpret_cast<const char*>(&product), sizeof(Product));

    if (file.fail()) {
        std::cerr << "Failed to write product data.\n";
        file.clear();  // Clear error flags
    }
}


static void writeProductFeature(Product& product, Features& feature, std::fstream& file, int position) {
    if (!file) {
        std::cerr << "File stream for write products is not open yet" << std::endl;
        return;
    }

    product.addFeature(feature);

    file.seekp(sizeof(Product) * position, std::ios::beg);
    std::streampos write_pos = file.tellp();
    if (write_pos != sizeof(Product) * position) {
        std::cerr << "Positioning error in file. Expected: " << sizeof(Product) * position << ", Got: " << write_pos << std::endl;
        return;
    }

    file.write(reinterpret_cast<const char*>(&product), sizeof(Product));

    if (file.fail()) {
        std::cerr << "Failed to write product data.\n";
        file.clear();  // Clear error flags
    }
}




#endif //BUGTRACKERPRO_FILEOPERATIONSMANAGER_H
