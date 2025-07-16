/*
    Program to compute the final number of a upc code.
    Steps:
        1. Get first three numbers of barcode from user
            - check if the number is a valid number and send error if not
            - I'm going to assume there are no strings input for now and only check 
              that the number itself is valid. This is because I don't fully understand
              how scanf works yet and don't think it's worth messing with in this example.
        2. Run a series of expressions to calculate the check number
            1. Add first, third, fifth, seventh, ninth and eleventh digits
            2. Add second, fourth, sixth, eigth, and tenth digits
            3. Multiply first sum by 3 and add it to the second sum
            4. Subtract 1 from the total
            5. Compute the remainder when the total divided by 10
            6. Subtract the remainder from 9
        3. Output the check number to the user and return the value

        Tests from the book:
        Jif Creamy Peanut Butter (18 oz.): 0 51500 24128 8
        Ocean Spray Jellied Cranberry Sauce (8 oz.): 0 31200 01005 6

    This solution was written before reading the A.N. King's solution in C Programming: A
    Modern Approach 2nd Edition. The solution in the book saves each digit individually
    which allows the sorting in the firstSum and secondSum to happen at input and avoid loops.
*/

#include <stdio.h>

// Function to ccheck if the first number input is a single positive digit
// Returns 0 if false and 1 if true bc idk how to do booleans in C
int checkFirstDigit(int first) {
    if (first >= 0 && first < 10) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the second and third numbers input are ints
// with digits.
// Same as above, using 0/1 booleans and ignoring non int inputs
// This doesn't work if there's a leading 0
// i think i need to save as a string and then convert to int if valid?
int checkGroupDigits(int groupDigit) {
    if (groupDigit > 9999 && groupDigit < 100000) {
        return 1;
    } else {
        return 0;
    }
}

// Function to perform expressions that will calculate the check
int findCheckNumber (int firstDigit, int firstGroup, int secondGroup) {
    int firstSum = firstDigit;
    int secondSum = 0;

    // Loop through all the numbers in the firstGroup and save to appropriate sum
    // An odd i means it goes to the second sum and an even i goes to first sum
    for (int i = 1; i < 6; i++) {
        int addNum = firstGroup % 10;
        if (i % 2 == 0) {
            firstSum += addNum;
        } else {
            secondSum += addNum;
        }

        firstGroup = firstGroup / 10;
    }

    // Same as last loop but now for secondGroup
    // An odd i goes to first sum and an even i goes to second sum
    for (int i = 1; i < 6; i++) {
        int addNum = secondGroup % 10;
        if (i % 2 == 0) {
            secondSum += addNum;
        } else {
            firstSum += addNum;
        }

        secondGroup = secondGroup / 10;
    }

    // Each step of the operation to make the final checkDigit
    int checkDigit = firstSum * 3;
    checkDigit = checkDigit + secondSum;
    checkDigit--;
    checkDigit = checkDigit % 10;
    checkDigit = 9 - checkDigit;

    return checkDigit;
}

int main () {
    int firstDigit;
    int firstGroup;
    int secondGroup;

    // Obtain UPC number from the user
    int test = 0;
    while (test == 0) {
        printf("Enter the first (single) digit: ");
        scanf("%d", &firstDigit);
        
        if (checkFirstDigit(firstDigit) == 1) {
            test = 1;
        } else {
            printf("Please enter only a single positive digit.\n");
        }
    }

    // Obtain first group of five digits from the user
    test = 0;
    while (test == 0) {
        printf("Enter first group of five digits: ");
        scanf("%d", &firstGroup);

        /*if(checkGroupDigits(firstGroup) == 1) {
            test = 1;
        } else {
            printf("Please enter only a positive digit with five numbers.\n");
        }*/
       test = 1;
    }

    // Obtain second group of five digits from the user
    test = 0;
    while (test == 0) {
        printf("Enter second group of five digits: ");
        scanf("%d", &secondGroup);

        /*if(checkGroupDigits(secondGroup) == 1) {
            test = 1;
        } else {
            printf("Please enter only a positive digit with five numbers\n");
        }*/
       test = 1;
    }

    int check = findCheckNumber(firstDigit, firstGroup, secondGroup);

    printf("Check digit: %d", check);

    return check;
}
