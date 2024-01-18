#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
class MergeSort {
public:
    void merge(vector<int>& array, int p, int q, int r) {
        int n1 = q - p + 1;
        int n2 = r - q;

        vector<int> L(n1);
        vector<int> M(n2);

        for (int i = 0; i < n1; i++)
            L[i] = array[p + i];
        for (int j = 0; j < n2; j++)
            M[j] = array[q + 1 + j];

        int i = 0, j = 0, k = p;

        while (i < n1 && j < n2) {
            if (L[i] <= M[j]) {
                array[k] = L[i];
                i++;
            } else {
                array[k] = M[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            array[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            array[k] = M[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& array, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(array, left, mid);
            mergeSort(array, mid + 1, right);
            merge(array, left, mid, right);
        }
    }
};

int main() {
    MergeSort ob;

    vector<int> array(500);
    srand(time(0));
    for (int i = 0; i < 500; i++) {
        array[i] = rand() % 100;
    }

    cout << "UNSORTED ARRAY:" << endl;
    for (int i = 0; i < 500; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    long start = clock();
    ob.mergeSort(array, 0, array.size() - 1);
    cout << "SORTED ARRAY:" << endl;
    for (int i = 0; i < 500; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    long end = clock();
     double execution_time = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Time taken by function: " << fixed<< execution_time << " seconds" << endl;

    return 0;
}
