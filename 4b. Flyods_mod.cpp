#include<iostream>
#include<climits>
#include<ctime>
using namespace std;
 
int min(int a, int b) {
    return (a < b) ? a : b;
}
 
void floyds(int p[10][10], int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j && p[i][k] != INT_MAX && p[k][j] != INT_MAX)
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}
 
int main() {
    int p[10][10], w, n, e, u, v, i, j;
   
    cout << "\nEnter the number of vertices: ";
    cin >> n;
    cout << "\nEnter the number of edges:\n";
    cin >> e;
 
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            p[i][j] = (i == j) ? 0 : INT_MAX;
    }
 
    for (i = 1; i <= e; i++) {
        cout << "\nEnter the end vertices of edge " << i << " with its weight:\n";
        cin >> u >> v >> w;
        p[u][v] = w;
    }
 
    cout << "\nMatrix of input data:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            cout << p[i][j] << "\t";
        cout << "\n";
    }
 
    clock_t start = clock();
 
    floyds(p, n);
 
    clock_t end = clock();
   
    cout << "\nTransitive closure:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            cout << (p[i][j] == INT_MAX ? "INF" : to_string(p[i][j])) << "\t";
        cout << "\n";
    }
 
    cout << "\nThe shortest paths are:\n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i != j && p[i][j] != INT_MAX)
                cout << "\n<" << i << "," << j << ">=" << p[i][j];
 
    double execution_time = double(end - start) / CLOCKS_PER_SEC;
 
    // Display execution time
    cout << "\nTime taken by function: " << fixed << execution_time << " seconds" << endl;
 
    return 0;
}
