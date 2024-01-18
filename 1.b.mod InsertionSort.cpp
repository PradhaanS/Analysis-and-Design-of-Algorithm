#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class InsertionSort {
private:
    int arr[200];

public:
    void sort() {
        int n = 200;

        // Input of array elements
        srand(time(0));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;
        }

        // Unsorted array
        cout << "UNSORTED ARRAY:" << endl;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Apply insertion sort algorithm on the array
        for (int k = 1; k < n; k++) {
            int temp = arr[k];
            int j = k - 1;
            while (j >= 0 && temp <= arr[j]) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = temp;
        }

        // Print the sorted array
        cout << "SORTED ARRAY:" << endl;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    InsertionSort obj;

    clock_t start = clock();
    obj.sort();
    clock_t end = clock();
    double execution_time = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Time taken by function: " << fixed<< execution_time << " seconds" << endl;

   
    return 0;
}
