#ifndef FLIGHTRECORD_H
#define FLIGHTRECORD_H

#include <string>

// Stores one aerospace flight record. This is our blueprint for inserting data in our cpp file.
struct FlightRecord {
    std::string aircraftID;
    int altitude;
    int speed;
    std::string status;
    std::string healthCheck;
};

#endif