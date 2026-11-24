# Design Notes

## Data Structure Choice
This project uses a chained hash table to store aerospace themed flight records

## Key and Value Design
Each flight record uses 'aircraftID' as the key. The associated data includes altitude, speed, status, and health check fields.

## Collision Handling 
Collisions are handled using separate chaining. If two aircraft IDs hash to the same bucket, both records can still be stored in the same bucket chain.

## Resizing Strategy
When the load factor becomes too high, the table begins incremental rehashing. Instead of moving every record at once, the table creates a larger bucket array and gradually moves old buckets into the new table.

## Incremental Rehashing Behavior
During rehashing, records may temporarily exist in either the old table or the new table. With that in mind, lookup, update, and delete operations must check both tables so that records remain accessibly during migration.

## Testing Approach
The project was tested through a console based demo in 'main.cpp'. The demo inserts records, searches for a record, updates one, removes another, and finally prints the table before and after those operations. 