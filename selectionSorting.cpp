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
void selectionSort(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        int smallest=A[i];
        int position=i;
        for (int j = i+1; j <n; j++)
        {
            if(A[j]<smallest)
            smallest=A[j];
            position=j;
        }
        if(i!=position)
        {
            swapp(&A[i],&A[position]);
        }
        
    }

}

 int main()
{
     int A[10000],n,i;
     cout<<"Enter n\t";
     cin>>n;
     for (int i = 0; i < n; i++)
     {
         A[i]=rand();
     }
     //cout<<"Before sorting"<<endl;
    // display (A,n);
      auto t1=chrono::high_resolution_clock::now();
     selectionSort(A,n);
      auto t2=chrono::high_resolution_clock::now();
     auto duration=chrono::duration_cast<chrono::microseconds>(t2-t1);
     cout<<"Time="<<duration.count()<<endl;
    // cout<<"After sorting"<<endl;
    // display(A,n);
     return 0;
    
 }