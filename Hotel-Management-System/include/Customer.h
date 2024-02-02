#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

struct Customer {
    int room_no;
    std::string name;
    std::string address;
    std::string phone;
    int days;
    float fare;
};

#endif
