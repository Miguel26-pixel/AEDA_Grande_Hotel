cmake_minimum_required(VERSION 3.15)
project(grande_hotel_central)

set(CMAKE_CXX_STANDARD 14)


add_executable(grande_hotel_central main.cpp Employee.cpp Room.cpp Client.cpp 
DataBase.cpp Product.cpp Book.cpp Files.cpp Date.cpp Login.cpp Employee.h Room.h Client.h
DataBase.h Product.h Book.h  Files.h Date.h InputValidation.cpp InputValidation.h Search.cpp 
Search.h UserInterface.cpp UserInterface.h Login.h Exception.h menu.h Finances.cpp
Finances.h BuyProduct.cpp BuyProduct.h Vehicle.h Vehicle.cpp bst.h binaryTree.h ClientInitial.cpp ClientInitial.h)


# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")

    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)
