//Greatest common divisor is also highest common factor
#include <stdio.h>
int gcd(int n1, int n2)
{
    if (n2 == 0)
        return n1;
    else
        return gcd(n2, n1 % n2);//gcd(n2,remainder of n1/n2)using Euclidean algorithm 
}
int main()
{
    int num1, num2;
    printf("Enter 1st number to find G.C.D:- ");
    scanf("%d", &num1);
    printf("Enter 2nd number to find G.C.D:- ");
    scanf("%d", &num2);
    printf("G.C.D of %d and %d is %d.", num1, num2, gcd(num1, num2));
    return 0;
}
