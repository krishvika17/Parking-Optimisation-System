# Parking-Optimisation-System

**Project Description:**

The Smart Parking Optimization System is a C++ application that models a parking lot using a graph and efficiently allocates parking slots. It uses Breadth-First Search (BFS) to identify the nearest available slot from a given entry point, minimizing search time and improving allocation efficiency.
The system supports real-time operations such as parking a vehicle, freeing a slot, and displaying current slot occupancy through a simple command-line interface.

**Key Highlights:**

- Modeled parking layout using graph (adjacency list) representation
- Implemented BFS traversal to find nearest available parking slot
- Enabled real-time updates for parking and vacancy management
- Designed a clean, modular and interactive CLI-based system
- Focused on efficient data handling using queues and vectors

**Working:**

- The parking area is represented as a graph where each node corresponds to a parking slot.
- Connections between nodes define possible movement paths within the parking lot.
- When a user requests parking, BFS is applied from the entry point to locate the nearest free slot.
- Once allocated, the slot is marked as occupied.
- Users can also vacate slots, updating availability dynamically.
- The system continuously maintains and displays the current status of all slots.
