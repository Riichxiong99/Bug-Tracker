cmake_minimum_required(VERSION 3.28)
project(BugTrackerPro)

set(CMAKE_CXX_STANDARD 17)

add_executable(BugTrackerPro Src/main.cpp
        Src/UI.h
        Src/Bug.h
        Src/Employee.h
        Src/Features.h
        Src/Bug.cpp
        Src/Customer.h
        Src/Customer.cpp
        Src/FileOperationsManager.h
        Src/Products.cpp
        Src/Employee.cpp
        Src/Features.cpp
        Src/Utils.h
        Src/UI.cpp
)
