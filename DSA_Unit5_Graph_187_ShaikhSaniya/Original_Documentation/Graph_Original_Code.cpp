#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100];
int vertices = 0;

void insertVertex() {
    if (vertices >= 100) {
        cout << "Maximum vertices reached.\n";
        return;
    }

    vertices++;
    cout << "Vertex " << vertices - 1
         << " added successfully.\n";
}

void insertEdge() {
    int u, v;

    cout << "Enter two vertex numbers: ";
    cin >> u >> v;

    if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
        cout << "Invalid vertex number.\n";
        return;
    }

    int i;

    for (i = 0; i < (int)adj[u].size(); i++) {
        if (adj[u][i] == v) {
            cout << "Edge already exists.\n";
            return;
        }
    }

    adj[u].push_back(v);
    adj[v].push_back(u);

    cout << "Edge added successfully.\n";
}

void deleteEdge() {
    int u, v, i;

    cout << "Enter edge vertices to delete: ";
    cin >> u >> v;

    if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
        cout << "Invalid vertex number.\n";
        return;
    }

    for (i = 0; i < (int)adj[u].size(); i++) {
        if (adj[u][i] == v) {
            adj[u].erase(adj[u].begin() + i);
            break;
        }
    }

    for (i = 0; i < (int)adj[v].size(); i++) {
        if (adj[v][i] == u) {
            adj[v].erase(adj[v].begin() + i);
            break;
        }
    }

    cout << "Edge deleted if it existed.\n";
}

void deleteVertex() {
    int v, i, j;

    cout << "Enter vertex number to delete: ";
    cin >> v;

    if (v < 0 || v >= vertices) {
        cout << "Invalid vertex number.\n";
        return;
    }

    for (i = 0; i < vertices; i++) {
        for (j = 0; j < (int)adj[i].size(); j++) {
            if (adj[i][j] == v) {
                adj[i].erase(adj[i].begin() + j);
                j--;
            } else if (adj[i][j] > v) {
                adj[i][j]--;
            }
        }
    }

    for (i = v; i < vertices - 1; i++) {
        adj[i] = adj[i + 1];
    }

    adj[vertices - 1].clear();
    vertices--;

    cout << "Vertex deleted successfully.\n";
}

void displayMatrix() {
    int i, j, k, found;

    cout << "\nAdjacency Matrix:\n";

    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            found = 0;

            for (k = 0; k < (int)adj[i].size(); k++) {
                if (adj[i][k] == j) {
                    found = 1;
                    break;
                }
            }

            cout << found << " ";
        }
        cout << endl;
    }
}

void displayList() {
    int i, j;

    cout << "\nAdjacency List:\n";

    for (i = 0; i < vertices; i++) {
        cout << i << " -> ";

        for (j = 0; j < (int)adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }
}

void BFS() {
    int start, v, i;

    cout << "Enter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= vertices) {
        cout << "Invalid starting vertex.\n";
        return;
    }

    vector<bool> visited(vertices, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        v = q.front();
        q.pop();

        cout << v << " ";

        for (i = 0; i < (int)adj[v].size(); i++) {
            int x = adj[v][i];

            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    cout << endl;
}

void DFSUtil(int v, vector<bool>& visited) {
    int i, x;

    visited[v] = true;
    cout << v << " ";

    for (i = 0; i < (int)adj[v].size(); i++) {
        x = adj[v][i];

        if (!visited[x]) {
            DFSUtil(x, visited);
        }
    }
}

void DFS() {
    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= vertices) {
        cout << "Invalid starting vertex.\n";
        return;
    }

    vector<bool> visited(vertices, false);

    cout << "DFS Traversal: ";
    DFSUtil(start, visited);
    cout << endl;
}

void updateGraph() {
    int choice;

    cout << "\nUpdate Graph:\n";
    cout << "1. Insert Vertex\n";
    cout << "2. Insert Edge\n";
    cout << "3. Delete Vertex\n";
    cout << "4. Delete Edge\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: insertVertex(); break;
        case 2: insertEdge(); break;
        case 3: deleteVertex(); break;
        case 4: deleteEdge(); break;
        default: cout << "Invalid choice.\n";
    }

    displayList();
}

int main() {
    int choice;

    do {
        cout << "\n===== GRAPH OPERATIONS =====\n";
        cout << "1. Insert Vertex\n";
        cout << "2. Insert Edge\n";
        cout << "3. Delete Vertex\n";
        cout << "4. Delete Edge\n";
        cout << "5. Display Adjacency Matrix\n";
        cout << "6. Display Adjacency List\n";
        cout << "7. BFS Traversal\n";
        cout << "8. DFS Traversal\n";
        cout << "9. Update Graph\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertVertex(); break;
            case 2: insertEdge(); break;
            case 3: deleteVertex(); break;
            case 4: deleteEdge(); break;
            case 5: displayMatrix(); break;
            case 6: displayList(); break;
            case 7: BFS(); break;
            case 8: DFS(); break;
            case 9: updateGraph(); break;
            case 10: cout << "Program ended.\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 10);

    return 0;
}
