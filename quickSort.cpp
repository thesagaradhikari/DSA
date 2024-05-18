#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;
void swapp(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int partition(int A[], int l, int r)
{
    int x = l;
    int y = r;
    int pivot = A[l];
    while (x < y)
    {
        while (A[x] <= pivot)
        {
            x++;
        }
        while (A[y] > pivot)
        {
            y--;
        }
        if (x < y)
        {
            swapp(&A[x], &A[y]);
        }
    }
    A[l] = A[y];
    A[y] = pivot;
    return y;
}

void quicksort(int A[], int l, int r)
{
    if (l < r)
    {
        int p = partition(A, l, r);
        quicksort(A, l, p - 1);
        quicksort(A, p + 1, r);
    }
}

int main()
{
    int A[10000], n, i;
    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        A[i] = rand();
    }

    cout << "Before sorting" << endl;
    display(A, n);
    auto t1 = chrono::high_resolution_clock::now();
    quicksort(A, 0, n - 1);
    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1);
    cout << "Time=" << duration.count() << " microseconds" << endl;
    cout << "After sorting" << endl;
    display(A, n);

    return 0;
}