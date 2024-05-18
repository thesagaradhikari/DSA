#include<stdio.h>
long long fact(int a)
{
    if(a==0){return 1;}
    else {return a*fact(a-1);}
}
int main()
{
    int n;
    while(n>=0){
    printf("Enter the number to obtain the factorial:-");
    scanf("%lld",&n);
    printf("Factorial calculated of %d is:- %lld\n",n,fact(n));}
    return 0;
}