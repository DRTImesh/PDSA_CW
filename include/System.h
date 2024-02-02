
#ifndef SYSTEM_H
#define SYSTEM_H

#include "Customer.h"
#include "Hotel.h"
#include <unordered_map>
#include <vector>

class System {
private:
    Hotel hotel;
    std::unordered_map<int, Customer> customerMap;  // Using a map to store customer records

public:
    System();
    void mainMenu();
    void add();
    void display();
    void rooms();
    void edit();
    int check(int);
    void modify(int);
    void deleteRec(int);
};

#endif
