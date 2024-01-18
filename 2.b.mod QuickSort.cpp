#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class QuickSort {
public:
    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1;
    }

    void sort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            sort(arr, low, pi - 1);
            sort(arr, pi + 1, high);
        }
    }

    static void printArray(int arr[], int size) {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    QuickSort ob;

    int arr[100];
    srand(time(0));
    int n = 100;

    cout << "UNSORTED ARRAY:" << endl;
    for (int i = 0; i < n; i++) {
        arr[i] = std::rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;

    long start = clock();
    ob.sort(arr, 0, n - 1);
    cout << "SORTED ARRAY" << endl;
    ob.printArray(arr, n);
    long end = clock();
    double execution_time = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Time taken by function: " << fixed<< execution_time << " seconds" << endl;
   

    return 0;
}
