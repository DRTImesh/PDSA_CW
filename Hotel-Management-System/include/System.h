#ifndef SYSTEM_H
#define SYSTEM_H

#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "Customer.h"
#include "Hotel.h"

class System {

private:



public:
   
    void mainMenu();
    void add();
    void display();
    void rooms();
    void edit();
    int check(int);
    void modify(int);
    void deleteRec(int);
    Hotel() {
    customerList = nullptr;
    topOfStack = -1;
}

};



#endif 
