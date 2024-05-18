#include<iostream>
#include<chrono>
#include<cstdlib>
using namespace std;
void swapp(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y=temp;
}
//void display(int A[], int n)
//{
  //  for(int i=0;i<n;i++)
    //{
      //  cout<<A[i]<<" ";
    //}
    //cout<<endl;;

//}

void insertionSort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i - 1;
        int temp = A[i];
        while (i >= 0 && temp < A[j])
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = temp;
    }
}
 int main()
{
     int A[10000],n,i;
     cout<<"Enter n";
     cin>>n;
     for (int i = 0; i < n; i++)
     {
         A[i]=rand();
     }
     //cout<<"Before sorting"<<endl;
    // display (A,n);
      auto t1=chrono::high_resolution_clock::now();
     insertionSort(A,n);
      auto t2=chrono::high_resolution_clock::now();
     auto duration=chrono::duration_cast<chrono::microseconds>(t2-t1);
     cout<<"Time="<<duration.count()<<endl;
    // cout<<"After sorting"<<endl;
    // display(A,n);
     return 0;
    
 }