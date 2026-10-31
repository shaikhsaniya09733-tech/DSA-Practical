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
    cout << "Vertex " << vertices - 1 << " added.\n";
}

void insertEdge() {
    int u, v, i;
    cout << "Enter two vertex numbers: ";
    cin >> u >> v;

    if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
        cout << "Invalid vertex number.\n";
        return;
    }

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

    cout << "Edge deletion completed.\n";
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

void traverseBFS(int start, vector<bool>& visited) {
    queue<int> q;
    int v, i, x;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        v = q.front();
        q.pop();
        cout << v << " ";

        for (i = 0; i < (int)adj[v].size(); i++) {
            x = adj[v][i];

            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

void BFS() {
    int start, i;

    if (vertices == 0) {
        cout << "Graph is empty.\n";
        return;
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= vertices) {
        cout << "Invalid starting vertex.\n";
        return;
    }

    vector<bool> visited(vertices, false);

    cout << "BFS Traversal: ";
    traverseBFS(start, visited);
    cout << endl;

    for (i = 0; i < vertices; i++) {
        if (!visited[i]) {
            cout << "Vertex " << i << " is disconnected from "
                 << start << ".\n";
        }
    }
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
    int start, i;

    if (vertices == 0) {
        cout << "Graph is empty.\n";
        return;
    }

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

    for (i = 0; i < vertices; i++) {
        if (!visited[i]) {
            cout << "Vertex " << i << " is disconnected from "
                 << start << ".\n";
        }
    }
}

bool isReachable(int start, int target) {
    vector<bool> visited(vertices, false);
    queue<int> q;

    int v, i, x;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        v = q.front();
        q.pop();

        if (v == target)
            return true;

        for (i = 0; i < (int)adj[v].size(); i++) {
            x = adj[v][i];

            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    return false;
}

void checkPath() {
    int source, destination;

    if (vertices == 0) {
        cout << "Graph is empty.\n";
        return;
    }

    cout << "Enter source and destination: ";
    cin >> source >> destination;

    if (source < 0 || destination < 0 ||
        source >= vertices || destination >= vertices) {
        cout << "Invalid vertex number.\n";
        return;
    }

    if (isReachable(source, destination))
        cout << "Path is available.\n";
    else
        cout << "Path unavailable: vertices are disconnected.\n";
}

void compareTraversal() {
    int start;

    if (vertices == 0) {
        cout << "Graph is empty.\n";
        return;
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= vertices) {
        cout << "Invalid starting vertex.\n";
        return;
    }

    vector<bool> visited(vertices, false);

    cout << "\nBFS before/after update comparison:\n";
    cout << "Current BFS traversal: ";
    traverseBFS(start, visited);
    cout << "\n";

    for (int i = 0; i < vertices; i++)
        visited[i] = false;

    cout << "Current DFS traversal: ";
    DFSUtil(start, visited);
    cout << "\n";
    cout << "Compare this result with the traversal recorded before updating.\n";
}

void updateGraph() {
    int choice;

    vector<vector<int> > oldGraph(vertices);

    for (int i = 0; i < vertices; i++)
        oldGraph[i] = adj[i];

    int oldVertices = vertices;

    cout << "\n1. Insert Vertex\n";
    cout << "2. Insert Edge\n";
    cout << "3. Delete Vertex\n";
    cout << "4. Delete Edge\n";
    cout << "Enter update choice: ";
    cin >> choice;

    switch (choice) {
        case 1: insertVertex(); break;
        case 2: insertEdge(); break;
        case 3: deleteVertex(); break;
        case 4: deleteEdge(); break;
        default:
            cout << "Invalid choice.\n";
            return;
    }

    cout << "\nGraph after update:\n";
    displayList();

    cout << "\nPrevious graph had " << oldVertices
         << " vertices; updated graph has " << vertices << " vertices.\n";

    cout << "Traversal comparison: run BFS/DFS before and after the update "
         << "to compare the results.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== MODIFIED GRAPH OPERATIONS =====\n";
        cout << "1. Insert Vertex\n";
        cout << "2. Insert Edge\n";
        cout << "3. Delete Vertex\n";
        cout << "4. Delete Edge\n";
        cout << "5. Display Adjacency Matrix\n";
        cout << "6. Display Adjacency List\n";
        cout << "7. BFS Traversal\n";
        cout << "8. DFS Traversal\n";
        cout << "9. Update Graph\n";
        cout << "10. Check Path Connectivity\n";
        cout << "11. Compare Traversal\n";
        cout << "12. Exit\n";
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
            case 10: checkPath(); break;
            case 11: compareTraversal(); break;
            case 12: cout << "Program ended.\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 12);

    return 0;
}
