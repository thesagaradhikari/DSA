#include <stdio.h>
void TOH(int n, char src, char dest, char temp)
{
    if (n == 1)
        printf("Move disk %d from '%c' to '%c'\n", n, src, dest);
    else
    {
        TOH(n - 1, src, temp, dest);
        printf("Move disk %d from '%c' to '%c' \n", n, src, dest);
        TOH(n - 1, temp, dest, src);
    }
}
int main()
{
    int n;
    printf("Enter number of disk:- ");
    scanf("%d", &n);
    TOH(n, 'A', 'C', 'B');
    return 0;
}
