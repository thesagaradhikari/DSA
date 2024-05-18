#include <iostream>
#include <cmath>
using namespace std;

int BinarySearch(int A[], int l, int r, int key)
{
    int m = floor((l + r) / 2);
    while (l <= r)
    {
        if (key == A[m])
        {
            return m + 1;// to start the position from 1
        }
        else if (key < A[m])
        {
            r = m - 1;
        }
        else
            l = m + 1;
        m = floor((l + r) / 2);
    }
    return -1;
}

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
    int A[10000], n, i, key;
    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        A[i] = rand();
    }

    cout << "Before sorting" << endl;
    display(A, n);

    quicksort(A, 0, n - 1);//binary search works only for sorted element

    cout << "After sorting" << endl;
    display(A, n);

    cout << "Enter key: ";
    cin >> key;
    cout << "Key is at pos: " << BinarySearch(A, 0, n - 1, key) << endl;

    return 0;
}
