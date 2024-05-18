//tailed factorial
#include<stdio.h>
long tailFact(int n,long a)//a is accumulator
{
    if(n==0||n==1){return a;}//returns 1
    else {return tailFact(n-1,a*n);}//task stacking is eliminated drastically
}
int main()
{
    int n;
    while(n>=0){
    printf("Enter the number to obtain the factorial:-");
    scanf("%ld",&n);
    printf("Factorial calculated of %d is:- %ld\n",n,tailFact(n,1));}
    return 0;
}