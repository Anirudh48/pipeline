#include <stdio.h>

int sumof2no()
{
    int firstNumber, secondNumber, sum;
    
    printf("\nEnter two integers: ");

    scanf("%d %d", &firstNumber, &secondNumber);

    sum = firstNumber + secondNumber;

    printf("Sum of %d and %d is %d\n", firstNumber, secondNumber, sum);

    return 0;
}
