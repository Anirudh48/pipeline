#include <stdio.h>

int fact()
{
    int n, i;
    int factorial = 1;

    printf("\nEnter an integer to find the factorial: ");
    scanf("%d",&n);

    // show error if the user enters a negativeii integer
    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist.");

    else
    {
        for(i=1; i<=n; ++i)
        {
            factorial *= i;             //  factorial = factorial*i;
        }
        printf("Factorial of %d = %d\n", n, factorial);
    }

    return 0;
}
