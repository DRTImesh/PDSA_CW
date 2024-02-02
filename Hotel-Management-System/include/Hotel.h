#ifndef HOTEL_H
#define HOTEL_H

#include <string>

struct Hotel {
    std::string name[50];
    std::string location[50];
    int totalRooms;
    int availableRooms;
    float roomRate;
};

#endif