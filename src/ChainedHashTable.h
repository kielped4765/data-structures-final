#ifndef CHAINEDHASHTABLE_H
#define CHAINEDHASHTABLE_H

#include <vector>
#include "FlightRecord.h"

// Node used in the linked-list chain for each bucket in the hash table
struct Node {
    // Stores our flight records in the chain using the variable record
    FlightRecord record;
    Node* next;
};
// chained hash table class that stores and manages the flight records
class ChainedHashTable {
    // fields that remain unchangeable outside of this class. 
    private:

        std::vector<Node*> buckets;
        size_t bucketCount;
        size_t itemCount;
        size_t rehashIndex;
        bool rehashing;
        std::vector<Node*> newBuckets;
        size_t newBucketCount;

        // converts a key into a new bucket index
        size_t hashFunction(const std::string& key) const;

        // inserts a record into a chosen bucket array
        void insertIntoBuckets(std::vector<Node*>& targetBuckets, size_t targetBucketCount, const FlightRecord& record);
        // moving one bucket from the old table to a new table during incremental rehashing
        void moveOneBucket();
        // starts the incremental rehashing process
        void startRehashing();

    // fields that can be utilized and modified in other functions and files.
    public:

        // creates a hash table with an inital bucket count
        ChainedHashTable(size_t initialBucketCount = 10);

        // our deconstructor that clean up all dynamically allocated nodes when the table is destroyed
        ~ChainedHashTable();

        void insert(const FlightRecord& record);
        bool find(const std::string& aircraftID, FlightRecord& outRecord) const;
        bool remove(const std::string& aircraftID);
        bool update(const std::string& aircraftID, const FlightRecord& updatedRecord);
        double loadFactor() const;
};

#endif