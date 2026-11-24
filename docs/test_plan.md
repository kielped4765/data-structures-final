# Test Plan

## Purpose
This test plan documents the basic behaviors of the chained hash table implementation and verifies
that insertion, lookup, update, deletion, and display all are working properly.

## Test Environment
- C++17
- CMake build system
- GNU C++ compiler
- Console based execution in the 'build/' directory

## Test Cases tested by running the program

### Test 1: Insert Flight records
* Input: *
- Create two flight records
- Insert both records into the hash table

* Expected Results: *
- Both records are stored in the table
- 'display()' shows each record in the correct bucket

* Actual Result: *
- Both records were inserted successfully
- The table output displayed both records in seperate buckets

### Test 2: Find a flight record
* Input: *
- Search for the record with aircraft ID 'F15-001'

* Expected Result: * 
- The record is found
- The record data is copied into the output variable

* Actual Result: *
- The record was found 
- The program printed the correct flight data

### Test 3: Update a flight record
* Input: *
- Update the record with aircraft ID 'F15-001'
- Change its altitude, speed, and status

* Expected Result: *
- The stored record is updated
- The new values appear in the table output

* Actual Result: *
- The update completed successfully
- The final table output showed the updated values

### Test 4: Remove a flight record
* Input: *
- Remove the record with aircraft ID 'F18-002'

* Expected Result: *
- The record is removed from the hash table
- The final table output no longer sows that record

* Actual Result: *
- The removal completed 
- The record no longer appeared in the final table output

## Results 
The test run confirmed that the hash table operations are working as intended. 