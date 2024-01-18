#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class SelectionSort {
private:
    int arr[10];

public:
    void sort() {
        int min, n = 10;

        // Input of array elements
        srand(time(0));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;
        }

        // Unsorted array
        cout<<"UNSORTED ARRAY:";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Sorting of array
        for (int i = 0; i < n - 1; i++) {
            min = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }

        // Sorted array
        cout<<"SORTED ARRAY:";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
};

int main() {
    SelectionSort obj;
    
    clock_t start = clock();
    obj.sort();
    clock_t end = clock();
    double execution_time = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by function: " << fixed<< execution_time << " seconds" << endl;

    return 0;
}
