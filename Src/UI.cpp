//============================================================================
// Name               : UI.cpp
// Author             : Richard Xiong
// Revision History   :
//    Rev. 1 - 07/15/2024
//           - Initial creation of the UI implementation
//           - Provides definitions for the UseUI class functions
//    Rev. 2 - 07/16/2024
//           - Implemented menu options for the UI and completed functions.
//           - Added input validation to the functions
//============================================================================
// Description        : This module defines the implementation for the user interface (UI)
//                      functionalities. It includes definitions for sub-menus and list menus,
//                      and functions for handling different menu actions.
//============================================================================
#include <iostream>
#include <regex>
#include <limits>
#include "Product.h"
#include "FileOperationsManager.h"
#include "Utils.h"
#include "Customer.h"
#include "UI.h"



using namespace std;

UseUI::UseUI() {
    customerFile.open("../data/customers.dat", ios::in | ios::out | ios::binary | ios::app);
    employeeFile.open("../data/employees.dat", ios::in | ios::out | ios::binary | ios::app);
    productFile.open("../data/products.dat", ios::in | ios::out | ios::binary);

    if (!customerFile.is_open() || !employeeFile.is_open() || !productFile.is_open()) {
        cerr << "Failed to open one or more files." << endl;
        throw runtime_error("Failed to open files");
    }
}

UseUI::~UseUI() {
    if (customerFile.is_open()) customerFile.close();
    if (employeeFile.is_open()) employeeFile.close();
    if (productFile.is_open()) productFile.close();
}

void UseUI::update() {
    bool running = true;
    char choice;

    while (running) {
        cout << "Main Menu:\n";
        displayLineOfStars(21);
        cout << "1. Manage Customers\n";
        cout << "2. Manage Employees\n";
        cout << "3. Manage Bugs\n";
        cout << "4. Manage Features\n";
        cout << "5. Print Report\n";
        cout << "6. Backup Data\n";
        cout << "7. Manage product\n";
        cout << "8. Exit Program\n";


        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case '1':
                showMenu(optionMngCust);
                break;
            case '2':
                showMenu(optionMngEmpl);
                break;
            case '3':
                showMenu(optionMngBug);
                break;
            case '4':
                showMenu(optionMngFtr);
                break;
            case '5':
                //showMenu(optionPrintReport);
                break;
            case '6':
                //showMenu(optionBackUpData);
                break;
            case '7':
                showMenu(optionAddProduct);
                break;
            case '8':
                running = false;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}

void displayMenu(const string &title, const vector<string> &options) {
    cout << title << endl;
    displayLineOfStars(21);

    for (size_t i = 0; i < options.size(); i++) {
        if (i == options.size() - 1) {
            cout << "n. " << options[i] << endl;
        } else {
            cout << i + 1 << ". " << options[i] << endl;
        }
    }
}

void displayCustomerMenu() {
    string title = "Manage Customer Menu";
    vector<string> vec = {"List Customers", "Add Customer", "Return to previous menu"};

    displayMenu(title, vec);

}

void displayEmployeeMenu() {
    string title = "Manage Employee Menu";
    vector<string> vec = {"List Employee", "Add Employee", "Return to previous menu"};

    displayMenu(title, vec);

}

void displayBugMenu() {
    string title = "Manage Bug Menu";
    vector<string> vec = {"List Bugs", "Add Bug", "Return to previous menu"};

    displayMenu(title, vec);

}

void displayBugEditMenu() {
    string title = "Are you submitting on behalf of a customer or as an Employee?";
    vector<string> vec = {"Customer", "Employee", "Return to previous menu"};
    displayMenu(title, vec);
}

void displayProductMenu() {
    string title = "Manage Product Menu";
    vector<string> vec = {"List Products", "Add Products", "Return to previous menu"};
    displayMenu(title, vec);
}

void displayFeatureEditMenu() {
    string title = "Are you submitting on behalf of a customer or as an Employee?";
    vector<string> vec = {"Customer", "Employee", "Return to previous menu"};
    displayMenu(title, vec);
}

string getDate() {
    auto t = std::time(nullptr);
    auto* tm = std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(tm, "%Y-%m-%d");
    return oss.str();
}

int productCount(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return -1;
    }
    std::streampos fileSize = file.tellg();
    int count = fileSize / sizeof(Product);
    return count;
}
int customerCount(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return -1;
    }
    std::streampos fileSize = file.tellg();
    int count = fileSize / sizeof(Customer);
    return count;
}
int employeeCount(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file for employee count." << std::endl;
        return -1;
    }
    std::streampos fileSize = file.tellg();
    int count = fileSize / sizeof(Employee);
    return count;
}

void UseUI::mngCust() {
    // Manage Customers menu implementation
    bool running = true;
    while (running) {
        displayCustomerMenu();
        string choice;
        getline(cin, choice);

        if (choice == "1") {
            listCusts();
        } else if (choice == "2") {
            editCust();
        } else if (choice == "n" || choice == "N") {
            running = false;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void UseUI::mngEmpl() {
    // Manage Employees menu implementation
    bool running = true;
    while (running) {
        displayEmployeeMenu();
        string choice;
        getline(cin, choice);

        if (choice == "1") {
            listEmpls();
        } else if (choice == "2") {
            editEmpl();
        } else if (choice == "n" || choice == "N") {
            running = false;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void UseUI::mngBug() {
    bool running = true;
    while (running) {
        displayBugMenu();
        string choice;
        getline(cin, choice);

        if (choice == "1") {
            listBugs();
        } else if (choice == "2") {
            editBug();
        } else if (choice == "n" || choice == "N") {
            running = false;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void UseUI::mngFeature() {
    bool running = true;
    while (running) {
        displayBugMenu();
        string choice;
        getline(cin, choice);

        if (choice == "1") {
            listFtrs();
        } else if (choice == "2") {
            editFtr();
        } else if (choice == "n" || choice == "N") {
            running = false;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void UseUI::mngProducts() {
    bool running = true;
    while (running) {
        displayProductMenu();
        string choice;
        getline(cin, choice);

        if (choice == "1") {
            listProds();
        } else if (choice == "2") {
            editProduct();
        } else if (choice == "n" || choice == "N") {
            running = false;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void UseUI::editCust() {
    string name;
    string email;
    string phoneNumber;

    while (true) {
        cout << "Enter the customer's name (Max Length: 30): ";
        getline(cin, name);
        if (name.length() > 0 && name.length() <= 30) {
            break;
        }
        cout << "Invalid name. Please enter a name with a maximum length of 30 characters." << endl;
    }
    regex phonePattern("\\d{10}");
    while (true) {
        cout << "Enter the customer's phone number (10 digits): ";
        getline(cin, phoneNumber);
        if (regex_match(phoneNumber, phonePattern)) {
            break;
        }
        cout << "Invalid phone number. Please enter a 10-digit phone number." << endl;
    }

    regex emailPattern(R"((\w+)(\.{1}\w+)*@(\w+)(\.\w+)+)");
    while (true) {
        cout << "Enter the customer's email: ";
        getline(cin, email);
        if (regex_match(email, emailPattern)) {
            break;
        }
        cout << "Invalid email. Please enter a valid email address." << endl;
    }

    cout << "Confirm Customer Information(Y/N)" << endl;
    char confirmation;
    cin >> confirmation;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    if (confirmation == 'Y' || confirmation == 'y') {
        Customer newCustomer(formatID(generateCustomerID()),name,email,phoneNumber);
        customerFile.clear();
        writeCustomer(newCustomer, customerFile);
        cout << "Customer has been successfully added to the database." << endl;

    } else {
        cout << "Customer addition canceled." << endl;
    }


}

void UseUI::editEmpl() {


    string name;
    string phoneNumber;
    string email;
    string department;

    // Input validation for the employee's name
    while (true) {
        cout << "Enter the employee's name (Max Length: 30): ";
        getline(cin, name);
        if (name.length() > 0 && name.length() <= 30) {
            break;
        }
        cout << "Invalid name. Please enter a name with a maximum length of 30 characters." << endl;
    }

    while (true) {
        cout << "Enter the employee's phone number: ";
        getline(cin, phoneNumber);
        if (phoneNumber.length() > 0 && phoneNumber.length() <= 15) {
            break;
        }
        cout << "Invalid phone number. Please enter a phone number with a maximum length of 15 characters."
             << endl;
    }

    while (true) {
        cout << "Enter the employee's email: ";
        getline(cin, email);
        if (email.length() > 0 && email.length() <= 50) {
            break;
        }
        cout << "Invalid email. Please enter an email with a maximum length of 50 characters." << endl;
    }


    while (true) {
        cout << "Enter the employee's department (Max Length: 30): ";
        getline(cin, department);
        if (department.length() > 0 && department.length() <= 30) {
            break;
        }
        cout << "Invalid department. Please enter a department with a maximum length of 30 characters."
             << endl;
    }

    cout << "Confirm Employee Information(Y/N)" << endl;
    char confirmation;
    cin >> confirmation;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    if (confirmation == 'Y' || confirmation == 'y') {
        Employee newEmployee(name,formatID(generateEmployeeID()),email,phoneNumber,department);
        employeeFile.clear();
        writeEmployee(newEmployee, employeeFile);
        cout << "Employee has been successfully added to the database." << endl;

    } else {
        cout << "Employee addition canceled." << endl;
    }
}

void UseUI::editBug() {
    cout << "Are you submitting on behalf of a customer or as an Employee?\n";
    cout << "1. Customer\n";
    cout << "2. Employee\n";
    cout << "n. Return to previous menu\n";

    string choice;
    SubmitterType submitterType;
    string submitterName;
    int submitterIndex;
    while (true) {
        getline(cin, choice);

        if (choice == "1") {
            submitterIndex = listCusts();
            submitterType = CUSTOMER;

            customerFile.clear();
            Customer customer = readCustomer(customerFile,submitterIndex);
            submitterName = customer.getName();
            break;

        } else if (choice == "2") {
            submitterIndex = listEmpls();
            submitterType = EMPLOYEE;

            employeeFile.clear();
            Employee employee = readEmployee(employeeFile,submitterIndex);
            submitterName = employee.getName();
            break;

        } else if (choice == "n" || choice == "N") {
            return;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    cout << "Enter the name of the product and release ID (e.g., Product 3 (release ID)):\n";
    int productIndex = listProds();


    cout << "Enter a description of the bug you are encountering:\n";
    string bugDescription;
    getline(cin, bugDescription);


    cout << "Enter a priority level of the bug (1 - Urgent, 2 - High, 3 - Medium, 4 - Low):\n";
    int priorityLevel;
    while (true) {
        cin >> priorityLevel;
        if (cin.fail() || priorityLevel < 1 || priorityLevel > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4:\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    string priorityLevelString;
    // convert priority level to string. Dont know why I did it like this but too lazy to fix now.
    if(priorityLevel == 1) {
        priorityLevelString = "Urgent";
    }

    else if (priorityLevel == 2) {
        priorityLevelString = "High";
    }

    else if (priorityLevel == 3) {
        priorityLevelString = "Medium";
    }

    else {
        priorityLevelString = "Low";
    }

    cout << "Confirm Bug request information?(Y/N)\n";
    char confirmation;
    cin >> confirmation;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (confirmation == 'Y' || confirmation == 'y') {
        Bug newBug(formatID(generateBugID()),bugDescription,getDate(),priorityLevelString,submitterType,submitterName);

        productFile.clear();
        Product newProduct = readProduct(productFile,productIndex);
        productFile.clear();

        writeProductBug(newProduct,newBug,productFile,productIndex);
        //write
        cout << "Bug successfully reported.\n";
    } else {
        cout << "New bug report has been discarded.\n";
    }
}

void UseUI::editFtr() {
    // Edit features menu implementation
    cout << "Are you submitting on behalf of a customer or as an Employee?\n";
    cout << "1. Customer\n";
    cout << "2. Employee\n";
    cout << "n. Return to previous menu\n";

    string choice;
    SubmitterType submitterType;
    string submitterName;
    int submitterIndex;
    while (true) {
        getline(cin, choice);

        if (choice == "1") {
            submitterIndex = listCusts();
            submitterType = CUSTOMER;

            customerFile.clear();
            Customer customer = readCustomer(customerFile,submitterIndex);
            submitterName = customer.getName();
            break;

        } else if (choice == "2") {
            submitterIndex = listEmpls();
            submitterType = EMPLOYEE;

            employeeFile.clear();
            Employee employee = readEmployee(employeeFile,submitterIndex);
            submitterName = employee.getName();
            break;

        } else if (choice == "n" || choice == "N") {
            return;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }




    cout << "Enter the name of the product and release ID (e.g., Product 3 (release ID)):\n";
    int productIndex = listProds();

    cout << "Enter a description of the feature you are suggesting:\n";
    string featureDescription;
    getline(cin, featureDescription);


    cout << "Enter a priority level of the Feature (1 - Urgent, 2 - High, 3 - Medium, 4 - Low):\n";
    int priorityLevel;
    while (true) {
        cin >> priorityLevel;
        if (cin.fail() || priorityLevel < 1 || priorityLevel > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4:\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    string priorityLevelString;
    // convert priority level to string. Dont know why I did it like this but too lazy to fix now.
    if(priorityLevel == 1) {
        priorityLevelString = "Urgent";
    }

    else if (priorityLevel == 2) {
        priorityLevelString = "High";
    }

    else if (priorityLevel == 3) {
        priorityLevelString = "Medium";
    }

    else {
        priorityLevelString = "Low";
    }

    cout << "Confirm Feature request information?(Y/N)\n";
    char confirmation;
    cin >> confirmation;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (confirmation == 'Y' || confirmation == 'y') {
        Features newFeature(formatID(generateFeaturesID()),featureDescription,getDate(),priorityLevelString,submitterType,submitterName);

        productFile.clear();
        Product newProduct = readProduct(productFile,productIndex);
        productFile.clear();

        writeProductFeature(newProduct,newFeature,productFile,productIndex);
        //write
        cout << "Feature successfully added.\n";
    } else {
        cout << "New Feature report has been discarded.\n";
    }

}

void UseUI::editProduct() {
    string productName;

    while (true) {
        cout << "Enter the name of the product ";
        getline(cin,productName);
        if (productName.length() > 0 && productName.length() <= 30) {
            break;
        }
    }

    cout << "Confirm product Information(Y/N) " << endl;
    char confirmation;
    cin >> confirmation;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (confirmation == 'Y' || confirmation == 'y') {
        Product newProduct(formatID(generateProductID()),productName);
        productFile.clear();
        writeProduct(newProduct,productFile);
        cout << "Product has been successfully added to the database." << endl;

    } else {
        cout << "Product addition canceled." << endl;
    }

}

int UseUI::listProds() {

    int currentIndex = 0;
    int totalProducts = productCount("../data/products.dat");
    const int pageSize = 10;
    int itemCount = 0;

    bool running = true;
    while (running) {
        productFile.clear();
        productFile.seekg(sizeof(Product) * currentIndex, ios::beg);

        vector<Product> products;
        for (int i = 0; i < pageSize; i++) {
            if (productFile.eof()) break;
            Product buffer;
            productFile.read(reinterpret_cast<char*>(&buffer), sizeof(Product));
            if (productFile) {
                products.push_back(buffer);
            }
        }

        cout << "Listing Products:\n";
        for (size_t i = 0; i < products.size(); ++i) {
            cout << i+itemCount << "." << products[i].getProductName() << "(" << products[i].getProductId() << ")" << endl;
            //products[i].printBugDebugInfo();
        }

        std::cout << "Enter 'n' to show next products, 'p' to show previous products, a number to select a product, or 'q' to return.\n";
        std::string input;
        std::getline(std::cin, input);

        if (input == "n") {
            if (currentIndex + pageSize < totalProducts) {
                currentIndex += pageSize;
                itemCount += pageSize;
            }
        } else if (input == "p") {
            if (currentIndex - pageSize >= 0) {
                currentIndex -= pageSize;
                itemCount -= pageSize;
            }
        } else if (input == "q") {
            running = false;
        } else {

            try {
                int selectedIdx = std::stoi(input);
                if (selectedIdx >= itemCount && selectedIdx < itemCount + products.size()) {
                    return selectedIdx - itemCount; // Adjust index if needed based on your system design
                } else {
                    std::cout << "Invalid selection. Please try again.\n";
                }
            } catch (const std::exception& e) {
                std::cout << "Invalid input. Please enter a valid number, 'n', 'p', or 'q'.\n";
            }
        }
    }
    return -1;
}

int UseUI::listCusts() {
    int currentIndex = 0;
    int totalCustomers = customerCount("../data/customers.dat");
    const int pageSize = 10;
    int itemCount = 0;
    bool running = true;

    while (running) {
        customerFile.clear();
        customerFile.seekg(sizeof(Customer) * currentIndex, std::ios::beg);

        std::vector<Customer> customers;
        for (int i = 0; i < pageSize; i++) {
            if (customerFile.eof()) break;
            Customer buffer;
            customerFile.read(reinterpret_cast<char*>(&buffer), sizeof(Customer));
            if (customerFile) {
                customers.push_back(buffer);
            }
        }

        std::cout << "Listing Customers:\n";
        for (size_t i = 0; i < customers.size(); ++i) {
            std::cout << (itemCount + i) << ". " << customers[i].getName() << " (" << customers[i].getCustomerId() << ")\n";
        }

        std::cout << "Enter 'n' to show next customers, 'p' to show previous customers, a number to select a customer, or 'q' to return.\n";
        std::string input;
        std::getline(std::cin, input);

        if (input == "n") {
            if (currentIndex + pageSize < totalCustomers) {
                currentIndex += pageSize;
                itemCount += pageSize;
            }
        } else if (input == "p") {
            if (currentIndex - pageSize >= 0) {
                currentIndex -= pageSize;
                itemCount -= pageSize;
            }
        } else if (input == "q") {
            running = false;
        } else {
            try {
                int selectedIdx = std::stoi(input);
                if (selectedIdx >= itemCount && selectedIdx < itemCount + customers.size()) {
                    return selectedIdx - itemCount;
                } else {
                    std::cout << "Invalid selection. Please try again.\n";
                }
            } catch (const std::exception& e) {
                std::cout << "Invalid input. Please enter a valid number, 'n', 'p', or 'q'.\n";
            }
        }
    }
    return -1;
}

int UseUI::listEmpls() {
    int currentIndex = 0;
    int totalEmployee = employeeCount("../data/employees.dat");
    const int pageSize = 10;
    int itemCount = 0;

    bool running = true;
    while (running) {
        employeeFile.clear();
        employeeFile.seekg(sizeof(Employee) * currentIndex, ios::beg);

        vector<Employee> employees;
        for (int i = 0; i < pageSize; i++) {
            if (employeeFile.eof()) break;
            Employee buffer;
            employeeFile.read(reinterpret_cast<char*>(&buffer), sizeof(Employee));
            if (employeeFile) {
                employees.push_back(buffer);
            }
        }

        cout << "Listing Employees:\n";
        for (size_t i = 0; i < employees.size(); ++i) {
            cout << i + itemCount << "." << employees[i].getName() << "(" << employees[i].getEmployeeID() << ")" << endl;
        }

        std::cout << "Enter 'n' to show next employee, 'p' to show previous employee, a number to select a employee, or 'q' to return.\n";
        std::string input;
        std::getline(std::cin, input);

        if (input == "n") {
            if (currentIndex + pageSize < totalEmployee) {
                currentIndex += pageSize;
                itemCount += pageSize;
            }
        } else if (input == "p") {
            if (currentIndex - pageSize >= 0) {
                currentIndex -= pageSize;
                itemCount -= pageSize;
            }
        } else if (input == "q") {
            running = false;
        } else {

            try {
                int selectedIdx = std::stoi(input);
                if (selectedIdx >= itemCount && selectedIdx < itemCount + employees.size()) {
                    return selectedIdx - itemCount;
                } else {
                    std::cout << "Invalid selection. Please try again.\n";
                }
            } catch (const std::exception& e) {
                std::cout << "Invalid input. Please enter a valid number, 'n', 'p', or 'q'.\n";
            }
        }
    }
    return -1;

}

void UseUI::listBugs() {
    cout << "Listing Bugs:" << endl;


}

void UseUI::listFtrs() {
    cout << "Listing Features:" << endl;

}

void UseUI::showMenu(subMenus menu) {
    // Show the corresponding sub-menu
    switch (menu) {
        case optionMngCust:
            mngCust();
            break;
        case optionMngEmpl:
            mngEmpl();
            break;
        case optionMngBug:
            mngBug();
            break;
        case optionEditBug:
            editBug();
            break;
        case optionEditCust:
            editCust();
            break;
        case optionEditEmpl:
            editEmpl();
            break;
        case optionEditFtr:
            mngFeature();
            break;
        case optionAddProduct:
            mngProducts();
            break;
        default:
            cout << "Invalid sub-menu.\n";
            break;
    }
}

void UseUI::showMenu(listMenus menu) {
    // Show the corresponding list menu
    switch (menu) {
        case optionlistCusts:
            listCusts();
            break;
        case optionListBugs:
            listEmpls();
            break;
        case optionListProds:
            listBugs();
            break;
        case optionListFtrs:
            listProds();
            break;
        default:
            cout << "Invalid list menu.\n";
            break;
    }
}
