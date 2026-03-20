#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> occupied;

// Add connection
void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

// Park vehicle
void park(int slot) {
    if (occupied[slot]) {
        cout << "Slot already occupied!\n";
    } else {
        occupied[slot] = true;
        cout << "Vehicle parked at slot " << slot << endl;
    }
}

// Leave slot
void leave(int slot) {
    if (!occupied[slot]) {
        cout << "Slot already empty!\n";
    } else {
        occupied[slot] = false;
        cout << "Slot " << slot << " is now free\n";
    }
}

// BFS for nearest free slot
int findNearest(int start, int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (!occupied[curr]) return curr;

        for (int next : graph[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return -1;
}

// Display status
void display(int n) {
    cout << "\nParking Status:\n";
    for (int i = 0; i < n; i++) {
        cout << "Slot " << i << ": "
             << (occupied[i] ? "Occupied" : "Free") << endl;
    }
}

int main() {
    int n = 6;
    graph.resize(n);
    occupied.resize(n, false);

    // Parking layout
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 5);

    int choice;

    while (true) {
        cout << "\n1. Park\n2. Leave\n3. Find Nearest\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int slot;
            cin >> slot;
            park(slot);
        }
        else if (choice == 2) {
            int slot;
            cin >> slot;
            leave(slot);
        }
        else if (choice == 3) {
            int start;
            cin >> start;
            int res = findNearest(start, n);

            if (res == -1)
                cout << "No free slot available\n";
            else
                cout << "Nearest free slot: " << res << endl;
        }
        else if (choice == 4) {
            display(n);
        }
        else {
            break;
        }
    }

    return 0;
}
