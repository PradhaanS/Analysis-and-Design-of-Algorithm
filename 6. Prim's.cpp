#include <iostream>
using namespace std;
int n, c[20][20], i, j, visited[20];
void prim();
int main() {
    cout << "Enter number of vertices" << endl;
    cin >> n;
    cout << "Enter the cost matrix" << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            cin >> c[i][j];
        visited[i] = 0;
    }
    clock_t start = clock();
    prim();
    clock_t end = clock();
    double execution_time = double(end - start) / double(CLOCKS_PER_SEC);
    cout<<"";
	cout << "Time taken by function: " << fixed<< execution_time << " seconds" << endl;
    return 0;
}
void prim() {
    int min, b, a, k, count = 0, cost = 0;
    visited[1] = 1; /* 1st vertex is visited */
    while (count < n - 1) {
        min = 999;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (visited[i] && !visited[j] && c[i][j] != 0 && min > c[i][j]) /* Fix condition */
                {
                    min = c[i][j]; /* assign c[i][j] as minimum cost */
                    a = i;
                    b = j;
                }
        if (min == 999) {
            // This means no valid edge was found
            break;
        }
        cout << a << "--->" << b << " = " << c[a][b] << endl; /* prints each edge in the MST and its cost */
        cost += c[a][b]; /* adds the minimum cost */
        visited[b] = 1;
        count++;
    } // end while
    if (count == n - 1) {
        cout << "Total cost of Spanning tree is " << cost<<endl; /* cost holds the minimum cost of the MST */
    } else {
        cout << "No spanning tree exists.";
    }
}
