/*
    Program to reverse the numbers in an array from user input.
    From page 164 of C Programming: A Modern Approach by A. N. King

    The trick will be to not reverse the numbers in the array, but rather
    to print them in reverse order from the original array.
*/

#include <stdio.h>

#define LENGTH 10

int main () {
    int userArray[LENGTH] = {0};

    printf("Enter 10 numbers: ");
    for (int i = 0; i < LENGTH; i++) {
        scanf("%d", &userArray[i]);
    }
         
    printf("In reverse order: ");
    for (int i = LENGTH - 1; i >= 0; i--) {
        printf("%d", userArray[i]);
    }
    printf("\n");

    return 0;
}