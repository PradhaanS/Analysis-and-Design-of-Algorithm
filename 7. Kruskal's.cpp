#include <iostream>
using namespace std;
int cost[100][100], parent[100], i, j, x, y, n;
void find_min();
int find_set(int i);
void union_sets(int i, int j);
int main() {
    int count = 0, tot = 0, flag = 0;
    cout << "Enter the number of vertices" << endl;
    cin >> n;
    cout << "Enter the cost matrix" <<endl;
    cout << "Enter 999 for No edges and self loops" <<endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> cost[i][j];
        }
        parent[i] = 0;
    }
    clock_t start = clock();
    while (count != n - 1) {
        find_min();
        int set_x = find_set(x);
        int set_y = find_set(y);
        if (set_x != set_y) {
            cout << "\n" << x << "----->" << y << "==" << cost[x][y] << endl;
            count++;
            tot += cost[x][y];
            union_sets(set_x, set_y);
        }
        cost[x][y] = cost[y][x] = 999;
    }
    clock_t end = clock();
    double execution_time = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\nThe total cost of the minimum spanning tree = " << tot << endl;
    cout<<"";
	cout << "Time taken by function: " << fixed<< execution_time << " seconds" << endl;
    return 0;
}
void find_min() {
    int m = 999;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (cost[i][j] < m) {
                m = cost[i][j];
                x = i;
                y = j;
            }
}
int find_set(int i) {
    while (parent[i] != 0) {
        i = parent[i];
    }
    return i;
}
void union_sets(int i, int j) {
    parent[j] = i;
}
