#ifndef HOTEL_H
#define HOTEL_H

#include <string>

struct Hotel {
    std::string name;
    std::string location;
    int totalRooms;
    int availableRooms;
    float roomRate;
};

#endif