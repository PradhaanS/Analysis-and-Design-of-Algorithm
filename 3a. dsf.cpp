#include <iostream>
using namespace std;

int n, a[10][10], i, j, v[10], count = 0;

void dfs(int x) {
    count++;
    v[x] = count;
    if (v[x] != 0)
        cout << x << "\t";

    int k;
    for (k = 1; k <= n; k++)
        if (a[x][k] == 1 && v[k] == 0)
            dfs(k);
}

int main() {
    cout << "Enter no. of Nodes: ";
    cin >> n;
    cout << "Enter the Adjacency Matrix:\n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];

    for (i = 1; i <= n; i++)
        v[i] = 0;
    cout << "\nDFS:\t";
    clock_t start = clock();
    for (i = 1; i <= n; i++)
        if (v[i] == 0)
            dfs(i);
    clock_t end = clock();

    cout << "\n";
    double execution_time = double(end - start) / double(CLOCKS_PER_SEC);

    // Display execution time
	cout << "Time taken by function: " << fixed<< execution_time << " seconds" << endl;


    return 0;
}
