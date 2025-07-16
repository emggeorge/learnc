/*
    Program to compute the final number of a upc code.

    This is the solution provided by the book, so credit to A.N. King.

    Steps:
        1. Get user input and store each digit as its own int. This means there
           will be 11 ints total. It is specified that the input variables
           are 1d, so it will only store one digit. Order matters, so it makes me 
           curious about a future approach that would use arrays.
        2. Add first, third, fifth, seventh, ninth and eleventh digits to a first
           sum and second, fourth, sixth, eigth, and tenth digits to a second sum.
           This is possible because the inital inputs are saved in the same order 
           as the number.
        3. Print the check number by performing the operations in the print statement.
           The book example does this in two steps while I will do it in one.

    The book example is much easier to read and understand than my initial attempt.
    It uses slightly more space (but only slightly because my approach required so
    many extra variables), but the big O of space is the same. The time complexity is
    also the same between the two programs, but mine does always require more steps due
    to the loops needed to make the sums.

    tldr: Main benefit of this program is readability by a signigicant margin.
*/

#include <stdio.h>

int main () {
    // Obtain pre-check upc numbers
    int d;
    int i1, i2, i3, i4, i5;
    int j1, j2, j3, j4, j5;
    int firstSum, secondSum;

    printf("Enter the first (single) digit: ");
    scanf("%1d", &d);
    printf("Enter the first group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
    printf("Enter the second group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

    // Perform operations
    firstSum = d + i2 + i4 + j1 + j3 + j5;
    secondSum = i1 + i3 + i5 + j2 + j4;

    printf("Check digit: %d\n", 9 - ((firstSum * 3 + secondSum - 1) % 10));

    return 0;
}
