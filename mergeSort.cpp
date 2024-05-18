#include <iostream>
#include <chrono>
#include <cmath>
#include <cstdlib>
using namespace std;

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void merge(int A[], int l, int m, int r)
{
    int i = l;
    int k = l;
    int j = m + 1;
    int c[100000];
    while (i <= m && j <= r)
    {
        if (A[i] < A[j])
            c[k++] = A[i++];
        else
            c[k++] = A[j++];
    }
    for (; i <= m; i++, k++)
        c[k] = A[i];
    for (; j <= r; j++, k++)
        c[k] = A[j];
    for (i = l; i <= r; i++)
        A[i] = c[i];
}

void mergeSort(int A[], int l, int r)
{
    if (l < r)
    {
        int m = floor((l + r) / 2);
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

int main()
{
    int A[100000], n, i;
    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        A[i] = rand();  
    }

    cout << "Before sorting" << endl;
    display(A, n);

    auto t1 = chrono::high_resolution_clock::now();
    mergeSort(A, 0, n - 1);
    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1);
    cout << "Time taken for sorting: " << duration.count() << " microseconds" << endl;

    cout << "After sorting" << endl;
    display(A, n);

    return 0;
}
