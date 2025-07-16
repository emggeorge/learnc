/*
    Program to reverse the numbers in an array from user input.
    From page 164 of C Programming: A Modern Approach by A. N. King

    This version does allows the user to decide the length of the array
    before inputting. Update from page 174.

    The trick will be to not reverse the numbers in the array, but rather
    to print them in reverse order from the original array.
*/

#include <stdio.h>

int main () {
    int length;

    printf("How many numbers do you want to reverse? ");
    scanf("%d", &length);

    int userArray[length];


    printf("Enter %d numbers: ", length);
    for (int i = 0; i < length; i++) {
        scanf("%d", &userArray[i]);
    }
         
    printf("In reverse order: ");
    for (int i = length - 1; i >= 0; i--) {
        printf("%d", userArray[i]);
    }
    printf("\n");

    return 0;
}