# Aerospace Flight Data Lookup Tool

This project implements a chained hash table in C++ to store and manage aerospace themed flight records. The hash table supports insertion, lookup, update, deletion, and incremental rehashing.
This allows the table to grow more smoothly as the number of records increases.

The goal of this project is to explore how hash tables work internally and to better understand collision handling, load factor, and resizing behavior. Instead of using a standard library hash map, this project implements the data structure manually with linked-list chaining for collision and incremental rehashing for smoother resizing.  

This makes the project useful both as a learning exercise and as a small demonstration of how hash tables can be used in real software systems that need fast key based access to data.

The program includes a simple console-based demonstration in 'main.cpp'.

It creates a sample flight record, inserts them into the table, searches for records, updates one record, removes another, and displays the table contents before and after those operations.

The project is organized using CMake, which builds the executable from the source files in the 'src/' directory. 

## Features

- Chained hash table implementation
- Flight record storage using 'aircraftID' as the key
- Collision handling through separate chaining
- Lookup by key
- Update and deletion support
- Load factor tracking
- Incremental rehashing for smoother resizing
- Console-based demo for testing and demonstration

## Project Structure

- 'src/FlightRecord.h'
    * Defines the flight record data structure
- 'src/ChainedHashTable.h'
    * Declares the hash table class and helper functions
- 'src/ChainedHashTable.cpp'
    * Implements the hash table behavior
- 'src/main.cpp'
    * Runs the console demo
- 'CMakeLists.txt'
    * Build configuration
- 'docs/'
    * Project notes, proposal, and supporting documentation

## Requirements

- CMake 3.16 or newer
- A C++17 compatible compiler
- VS Code or another C++ development environment

## Build Instructions

1. Open a terminal in the project root directory.
2. Create a build directory if it does not already exist:
    'mkdir build'
3. Move into the build directory:
    'cd build'
4. Run CMake to configure the project"
    'cmake ..'
5. Build the executable:
    'cmake --build .'

## Run Instructions

After building the project, run the executable from the build directory:

'./run_app'

On windows, the executable may be named something like:

'run_app.exe'

## Demo Behavior

The demo in 'main.cpp':

- creates a hash table
- creates sample flight records
- inserts records into the table
- displays the table
- searches for a record
- updates a record
- removes a record
- displays the table again

## Additional Notes

This project was developed to learn more about chained hash tables and incremental rehashing while working to incorporate aerospace flight records that can be interchangable. 