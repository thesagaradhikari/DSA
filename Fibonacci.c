#include<stdio.h>
int fibo(int a)
{
    if(a==1||a==2)
    return 1;
    else
    return fibo(a-1)+fibo(a-2);
}
int main()
{
    int n=1;
    while(n){
    printf("Enter the place of Fibonacci number:-");
    scanf("%d",&n);
    printf("The Fibonacci number in palce %d is:- %d\n",n,fibo(n));
    }
    return 0;
}
//this program is not suitable for higher term so concept of memoization is used
