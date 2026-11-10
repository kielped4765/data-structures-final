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