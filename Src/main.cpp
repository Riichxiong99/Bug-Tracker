#include <iostream>
#include "FileOperationsManager.h"
#include "UI.h"
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;

    initialization();
    UseUI ui;
    ui.update();

    return 0;
}