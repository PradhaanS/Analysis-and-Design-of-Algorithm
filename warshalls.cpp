#include<iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

void warshall(int p[10][10], int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                p[i][j] = max(p[i][j], p[i][k] && p[k][j]);
}

int main() {
    int p[10][10] = {0}, n, e, u, v, i, j;

    cout << "\nEnter the number of vertices: ";
    cin >> n;
    cout << "\nEnter the number of edges: ";
    cin >> e;

    for (i = 1; i <= e; i++) {
        cout << "\nEnter the end vertices of edge " << i << ": ";
        cin >> u >> v;
        p[u][v] = 1;
    }

    cout << "\nMatrix of input data: \n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            cout << p[i][j] << "\t";
        cout << "\n";
    }
    clock_t start = clock();
  
    warshall(p, n);

    clock_t end = clock();
    
    

    cout << "\nTransitive closure: \n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            cout << p[i][j] << "\t";
        cout << "\n";
    }
    double execution_time = double(end - start) / double(CLOCKS_PER_SEC);

    // Display execution time
	cout << "Time taken by function: " << fixed<< execution_time << " seconds" << endl;
    return 0;
}
