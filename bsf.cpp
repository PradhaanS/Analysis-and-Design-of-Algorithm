#include <iostream>
#include <queue>
using namespace std;

void BFS(int a[20][20], int source, int visited[20], int n);

int main() {
    int n, a[20][20], i, j, visited[20] = {0}, source;

    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "\nEnter the adjacency matrix:\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "\nEnter the source node: ";
    cin >> source;

    if (source < 0 || source >= n) {
        cout << "Invalid source node!";
        return 1;  // Exit with an error code
    }

    visited[source] = 1;
    clock_t start = clock();
  
    BFS(a, source, visited, n);

    clock_t end = clock();

    cout << "\nReachability of nodes from node " << source << ":\n";
    for (i = 0; i < n; i++) {
        if (visited[i] != 0)
            cout << "Node " << i << " is reachable\n";
        else
            cout << "Node " << i << " is not reachable\n";
    }
    double execution_time = double(end - start) / double(CLOCKS_PER_SEC);

    // Display execution time
	cout << "Time taken by function: " << fixed<< execution_time << " seconds" << endl;
    return 0;
}

void BFS(int a[20][20], int source, int visited[20], int n) {
    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (a[u][v] == 1 && visited[v] == 0) {
                q.push(v);
                visited[v] = 1;
            }
        }
    }
}
