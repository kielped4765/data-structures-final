#ifndef CHAINEDHASHTABLE_H
#define CHAINEDHASHTABLE_H

#include <vector>
#include "FlightRecord.h"

struct Node {
    FlightRecord record;
    Node* next;
};

class ChainedHashTable {
    private:

        std::vector<Node*> buckets;
        size_t bucketCount;
        size_t itemCount;
        size_t rehashIndex;
        bool rehashing;
        std::vector<Node*> newBuckets;
        size_t newBucketCount;

        size_t hashFunction(const std::string& key) const;
        void insertIntoBuckets(std::vector<Node*>& targetBuckets, size_t targetBucketCount, const FlightRecord& record);
        void moveOneBucket();
        void startRehashing();

    public:
        ChainedHashTable(size_t initialBucketCount = 10);
        ~ChainedHashTable();

        void insert(const FlightRecord& record);
        bool find(const std::string& aircraftID, FlightRecord& outRecord) const;
        bool remove(const std::string& aircraftID);
        bool update(const std::string& aircraftID, const FlightRecord& updatedRecord);
        double loadFactor() const;
};

#endif