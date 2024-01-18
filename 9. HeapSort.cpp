#include <iostream>
#include <sys/time.h>
#include <sys/resource.h>
using namespace std;

void heapSort(int a[], int n);
void siftDown(int a[], int root, int bottom);

int main() {
    int a[100], n, i;
    struct timeval tv1, tv2;
    struct rusage r_usage;

    cout << "Enter the number of elements" << endl;
    cin >> n;

    cout << "Enter the elements" << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];

    gettimeofday(&tv1, nullptr);
    heapSort(a, n);
    gettimeofday(&tv2, nullptr);

    cout << "Sorted elements are" << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    
    cout << "\nTime taken by Heap sort = " << (double)(tv2.tv_usec - tv1.tv_usec) << " microseconds" << endl;

    getrusage(RUSAGE_SELF, &r_usage);
    cout << "Memory usage: " << r_usage.ru_maxrss << " kilobytes" << endl;

    return 0;
}

void heapSort(int a[], int n) {
    int i, temp;

    for (i = n - 1; i >= 0; i--)
        siftDown(a, i, n - 1);

    for (i = n - 1; i >= 1; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        siftDown(a, 0, i - 1);
    }
}

void siftDown(int a[], int root, int bottom) {
    int done, maxChild, temp;

    done = 0;
    while ((root * 2 <= bottom) && (!done)) {
        if (root * 2 == bottom)
            maxChild = root * 2;
        else if (a[root * 2] > a[root * 2 + 1]) // left child greater than right child
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;

        if (a[root] < a[maxChild]) // exchange root with maxchild
        {
            temp = a[root];
            a[root] = a[maxChild];
            a[maxChild] = temp;
            root = maxChild;
        } else
            done = 1;
    }
}
