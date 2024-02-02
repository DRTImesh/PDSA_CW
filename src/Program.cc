
#include "../include/System.h"

#include <iostream>
#include <limits>

System::System() {
    // Initialize the hotel or load data from a file/database
    hotel = {"My Hotel", "City Center", 100, 100, 150.0};  // Initial hotel values
}

void System::mainMenu() {
    int choice;
    while (true) {
        std::cout << "\n\n\t\t\t\t*************";
        std::cout << "\n\t\t\t\t* MAIN MENU *";
        std::cout << "\n\t\t\t\t*************";
        std::cout << "\n\n\t\t\t1. Book A Room";
        std::cout << "\n\t\t\t2. Customer Record";
        std::cout << "\n\t\t\t3. Rooms Allotted";
        std::cout << "\n\t\t\t4. Edit Record";
        std::cout << "\n\t\t\t5. Exit";
        std::cout << "\n\n\t\t\tEnter Your Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                rooms();
                break;
            case 4:
                edit();
                break;
            case 5:
                std::cout << "Exiting the system. Goodbye!" << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
}

void System::add() {
    Customer newCustomer;

    std::cout << "Enter Customer Details:" << std::endl;
    std::cout << "Room no: ";
    std::cin >> newCustomer.room_no;

    if (customerMap.find(newCustomer.room_no) != customerMap.end()) {
        std::cout << "Room is already booked. Cannot add customer." << std::endl;
        return;
    }

    std::cout << "Name: ";
    std::cin >> newCustomer.name;
    std::cout << "Address: ";
    std::cin >> newCustomer.address;
    std::cout << "Phone No: ";
    std::cin >> newCustomer.phone;
    std::cout << "No of Days to Checkout: ";
    std::cin >> newCustomer.days;
    newCustomer.fare = newCustomer.days * hotel.roomRate;

    customerMap[newCustomer.room_no] = newCustomer;

    std::cout << "Room is booked successfully!" << std::endl;
}

void System::display() {
    int roomNumber;
    std::cout << "Enter room no: ";
    std::cin >> roomNumber;

    auto it = customerMap.find(roomNumber);
    if (it != customerMap.end()) {
        std::cout << "\nCustomer Details:\n";
        std::cout << "Room no: " << it->second.room_no << "\nName: " << it->second.name
                  << "\nAddress: " << it->second.address << "\nPhone no: " << it->second.phone
                  << "\nDays: " << it->second.days << "\nTotal Fare: " << it->second.fare
                  << std::endl;
    } else {
        std::cout << "Customer not found or room vacant." << std::endl;
    }
}

void System::rooms() {
    std::cout << "\n\t\t\t    List Of Rooms Allotted\n";
    std::cout << "\n\t\t\t    ----------------------\n";
    for (const auto& pair : customerMap) {
        std::cout << "Room no: " << pair.first << "\nName: " << pair.second.name
                  << "\nAddress: " << pair.second.address << "\nPhone: " << pair.second.phone
                  << "\nDays: " << pair.second.days << "\nTotal: " << pair.second.fare
                  << "\n**********************************\n";
    }
}

void System::edit() {
    int choice;
    std::cout << "Edit Menu\n";
    std::cout << "1. Modify Customer Record\n";
    std::cout << "2. Delete Customer Record\n";
    std::cout << "Enter your choice: ";
    std::
