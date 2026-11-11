#include "ChainedHashTable.h"
#include <iostream>
#include <functional>

// Consturctor set-up: Setting up the hash table with an inital number of empty buckets
ChainedHashTable::ChainedHashTable(size_t initialBucketCount)
   : buckets(initialBucketCount, nullptr),  // creating the bucket array and starting each bucket as empty
    bucketCount(initialBucketCount),
    itemCount(0),
    rehashIndex(0),
    rehashing(false),
    newBucketCount(0) {
    }

// Deconstructor set-up: frees all dynamically allocated nodes to prevent memory leaks by removing all nodes from the hash table. 
ChainedHashTable::~ChainedHashTable() {
    // Delete every node in the current bucket array
    for (Node* bucket : buckets) {
        while (bucket != nullptr) {
            Node* temp = bucket;
            bucket = bucket->next;
            delete temp;
        }
    }
    // If rehashing was still in progress, also delete nodes in the new bucket array using the same process as above.
    if (rehashing) {
        for (Node* bucket : newBuckets) {
            while (bucket != nullptr) {
                Node* temp = bucket;
                bucket = bucket->next;
                delete temp;
            }
        }
    }
}

// uses a hash function to turn the key into a bucket index within the table size
size_t ChainedHashTable::hashFunction(const std::string& key) const {
    // creates our hash object for strings using the variable hasher
    std::hash<std::string> hasher;
    // hashes the key and compresses the result into a valid bucket index and returns that compressed bucket index
    return hasher(key) % bucketCount;
}

// inserts a flight record into the chosen bucket array
void ChainedHashTable::insertIntoBuckets(std::vector<Node*>& targetBuckets, size_t targetBucketCount, const FlightRecord& record) {
    // create a hash object for strings
    std::hash<std::string> hasher;

    // hash the aircraft ID and compress it into a valid bucket index
    size_t index = hasher(record.aircraftID) % targetBucketCount;
    
    // creates a new node in dynamic memory to store the flight record
    Node* newNode = new Node{record, nullptr};
    
    // points the new node to the current first node (targetBuckets[index]) in the bucket chain 
    newNode->next = targetBuckets[index];

    // makes the bucket point to the new node so it becomes the new front
    targetBuckets[index] = newNode;
}

// insert function for adding a new flight record to the hash table
void ChainedHashTable::insert(const FlightRecord& record) {

    // if rehashing is already happening, insert into the new bucket array and not the old bucket array
    if (rehashing) {
        insertIntoBuckets(newBuckets, newBucketCount, record);
    }

    // Otherwise, insert into current bucket array
    else {
        insertIntoBuckets(buckets, bucketCount, record);
    }

    // Increase the total number of stored records
    itemCount++;

    // If the table is getting too full, start rehashing
    if (!rehashing && loadFactor() > 0.6) {
        startRehashing();
    }
}

// Checks and returns how full the hash table currently is
double ChainedHashTable::loadFactor() const {
    return static_cast<double>(itemCount) / bucketCount;
}

// Starts the incremental rehashing process by creating a larger new bucket array
void ChainedHashTable::startRehashing() {
    rehashing = true;
    rehashIndex = 0;
    newBucketCount = bucketCount * 2;
    newBuckets.resize(newBucketCount, nullptr);
}
