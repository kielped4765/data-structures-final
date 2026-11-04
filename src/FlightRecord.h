#ifndef FLIGHTRECORD_H
#define FLIGHTRECORD_H

#include <string>

struct FlightRecord {
    std::string aircraftID;
    int altitude;
    int speed;
    std::string status;
    std::string healthCheck;
};

#endif