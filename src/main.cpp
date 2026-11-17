#include "ChainedHashTable.h"
#include <iostream>

// main function where the program begins
int main() {
    ChainedHashTable table;

    // creating the first flight record
    FlightRecord record1;
    record1.aircraftID = "F15-001";
    record1.altitude = 34000;
    record1.speed = 1500;
    record1.status = "cruising";
    record1.healthCheck = "nominal";

    // insert the first flight record into the hash table
    table.insert(record1);

    // creating the second flight record
    FlightRecord record2;
    record2.aircraftID = "F18-002";
    record2.altitude = 36000;
    record2.speed = 1800;
    record2.status = "climbing";
    record2.healthCheck = "nominal";

    // insert the second flight record into the hash table
    table.insert(record2);

    // display the contents of the hash table
    table.display();

    // a variable to store the found flight record
    FlightRecord foundRecord;

    // search for the first flight record by aircraft ID
    if (table.find("F15-001", foundRecord)) {
        std::cout << "Found record: " << foundRecord.aircraftID
                  << ", Altitude: " << foundRecord.altitude
                  << ", Speed: " << foundRecord.speed
                  << ", Status: " << foundRecord.status
                  << ", Health: " << foundRecord.healthCheck << std::endl;
    }   else {
            std::cout << "Record not found." << std::endl;
    }

    // create an updated version of the first flight record
    FlightRecord updatedRecord1;
    updatedRecord1.aircraftID = "F15-001";
    updatedRecord1.altitude = 38000;
    updatedRecord1.speed = 1555;
    updatedRecord1.status = "ascending";
    updatedRecord1.healthCheck = "nominal";

    if (table.update("F15-001", updatedRecord1)) {
        std::cout << "Record updated successfully." << std::endl;
    }   else {
        std::cout << "Update failed." << std::endl;
    }

    // remove the second flight record from the hash table
    if (table.remove("F18-002")) {
        std::cout << "Record removed successfully." << std::endl;
    }   else {
            std::cout << "Remove failed." << std::endl;
    }

    // display contents of table again after update and remove operations were included
    table.display();

    return 0;
}





