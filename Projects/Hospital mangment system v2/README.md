# Hospital Queue Management System Documentation

## Introduction
This document provides an overview and documentation for a C++ program that simulates a hospital queue management system. The system is designed to manage patients in different specializations and prioritize them based on their urgency status. Below, we'll explain the program's structure, classes, and functions.

## Program Structure
- **main.cpp**: The main entry point for the program.
- **hospitalQueue Struct**: Represents a queue for a specific specialization. It includes an array of patient names, a status array indicating the urgency of each patient, the queue's length, and the specialization ID.
- **HospitalSystem Struct**: Manages multiple hospitalQueue instances, simulating the entire hospital's queue system.
- **menu() Function**: Displays the main menu and obtains user input.
- **addPatient() Function**: Adds a new patient to the appropriate specialization queue.
- **getNextPatient() Function**: Retrieves the next patient from a specific specialization queue.
- **printAllPatient() Function**: Prints all patients in each specialization queue.

## hospitalQueue Struct
- **Names[queueSize]**: An array to store patient names.
- **status[queueSize]**: An array to store the status (urgent or normal) of each patient.
- **len**: The length of the queue.
- **spec**: The specialization ID.

### Methods
- **hospitalQueue(int spec = -1)**: Constructor for initializing a specialization queue.
- **add(string name, bool st)**: Adds a patient to the queue, either at the front (urgent) or end (normal) based on the urgency status.
- **addEnd(string &name)**: Adds a patient to the end of the queue.
- **addFront(string &name)**: Adds a patient to the front of the queue.
- **GetFront()**: Retrieves and processes the next patient in the queue.
- **print()**: Prints information about patients in the queue, including their names and status (urgent or normal).

## HospitalSystem Struct
- **queue[Special]**: An array of hospitalQueue instances, one for each specialization (from 1 to 20).

### Methods
- **HospitalSystem()**: Constructor for initializing the hospitalQueue instances for each specialization.
- **run()**: The main control loop for the hospital queue management system.
- **menu()**: Displays the main menu and returns the user's choice.
- **addPatient()**: Allows the user to add a new patient to the appropriate specialization queue.
- **getNextPatient()**: Allows the user to get the next patient from a specific specialization queue.
- **printAllPatient()**: Prints all patients in each specialization queue.

## Usage
To run the program, compile the `main.cpp` file and execute the resulting binary. The program will provide a menu for users to interact with the hospital queue management system.

## Conclusion
This hospital queue management system provides a straightforward yet effective way to manage patients in different specializations, prioritizing them based on their urgency status. Users can add patients, retrieve the next patient, and view the patient queues for all specializations. Additional features and enhancements can be incorporated to extend the system's capabilities and usability.
