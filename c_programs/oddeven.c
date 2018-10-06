#include <stdio.h>

int oddeven()
{
    int number;

    // True if the number is perfectly divisible by 2
    printf("\nEnter an integer to find if its odd/even number: ");
    scanf("%d", &number);

    if(number % 2 == 0)
        printf("%d is even.\n", number);
    else
        printf("%d is odd.\n", number);

    return 0;
}
