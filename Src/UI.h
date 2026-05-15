
//============================================================================
// Name               : UI.h
// Author             : James Floe
// Revision History   :
//    Rev. 1 - 07/02/2024
//           - Initial creation of the UI interface
//           - Provides declarations for the UseUI class and its functionalities
//============================================================================
// Description        : This module defines the interface for the user interface (UI)
//                      functionalities. It includes enums for sub-menus and list menus,
//                      along with function pointers for handling different menu actions.
//                      It also declares the UseUI class with functions for managing UI
//                      interactions.
//============================================================================
#ifndef BUGTRACKERPRO_UI_H
#define BUGTRACKERPRO_UI_H


#include <iostream>
#include <array>
#include <string>
#include <fstream>

class UseUI {

private:
    std::fstream customerFile;
    std::fstream employeeFile;
    std::fstream productFile;

public:

    UseUI();
    ~UseUI();

    // Enum for sub-menus (corresponds to listMenuActions array)
    enum subMenus {
        main,
        optionMngCust,
        optionMngEmpl,
        optionMngBug,
        optionMngFtr,
        optionEditBug,
        optionEditCust,
        optionEditEmpl,
        optionEditFtr,
        optionAddProduct,
        numOfSubMenus
    };

    // Enum for list menus (corresponds to subMenuActions array)
    enum listMenus {
        optionlistCusts,
        optionListBugs,
        optionListProds,
        optionListFtrs,
        numOfListMenus
    };


//----------------------------------------------------------------------------
    void update();
// Description: Main loop that contains switch cases for choosing which
// current menu to display.
//----------------------------------------------------------------------------
    void showMenu(
        subMenus // in
    );
// Description: Utilizes subMenus enum to decide which menu to display and
// calls that menus display function.
//----------------------------------------------------------------------------
    void showMenu(
        listMenus // in
    );
// Description: Overloaded for listMenu enum.
//----------------------------------------------------------------------------
    void mngCust();
// Description: Displays the Manager Customers menu.
//----------------------------------------------------------------------------
    void mngEmpl();
// Description: Displays the Manager Employees menu.
//----------------------------------------------------------------------------
    void mngBug();
// Description: Displays the Manager Bugs menu.
//----------------------------------------------------------------------------

    void mngFeature();
// Description: Displays the Manager Products menu.
//----------------------------------------------------------------------------


    void mngProducts();
// Description: Displays the Manager Products menu.
//----------------------------------------------------------------------------

    void editBug();
// Description: Displays the Edit Bug menu.
//----------------------------------------------------------------------------
    void editCust();
// Description: Displays the Edit Customer menu.
//----------------------------------------------------------------------------
    void editEmpl();
// Description: Displays the Edit Employee menu.
//----------------------------------------------------------------------------
    void editFtr();
// Description: Displays the Edit Feature menu.
//----------------------------------------------------------------------------
    void editProduct();
// Description: Displays the Add Product menu.
//----------------------------------------------------------------------------
    int listCusts();
// Description: Displays a list of Customers.
//----------------------------------------------------------------------------
    int listEmpls();
// Description: Displays a list of Employees.
//----------------------------------------------------------------------------
    void listBugs();
// Description: Displays the Manager Customers menu.
//----------------------------------------------------------------------------
    int listProds();
// Description: Displays the Manager Customers menu.
//----------------------------------------------------------------------------
    void listFtrs();
// Description: Displays a list of Features.
//----------------------------------------------------------------------------


};

#endif //BUGTRACKERPRO_UI_H
