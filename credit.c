/**
 * Credit card number validation program for Problem Set 1
 *
 * Written by Chance Johnson 2022-09-28
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Value range of 0 to 18446744073709551615
    unsigned long cc = 0;

    // If the user doesn't enter a number, cc will be 0
    while (cc < 1 || cc > 9999999999999999)
    {
        printf("Number: ");
        scanf("%lu", &cc);

        // Clear the buffer
        while ((getchar()) != '\n')
            ;
    }

    /**
     *  The following code up to the end of the do-while loop is inspired from
     *  https://www.geeksforgeeks.org/c-program-to-print-all-digits-of-a-given-number/
     *
     *  Particularly, the <NUM> % 10 = the last digit of the number
     *  and then
     *  <NUM> / 10 = Same number with one less digit
     * */

    // The value will never be larger than 9999999999999999 (+1 for sentinel)
    int ccArr[17], ccArrBack[17];
    int d;
    int i = 0;
    int t = 0;

    // Continues looping until "cc" reaches 0
    do
    {
        // Get last digit of entered number
        d = cc % 10;

        // Add digit to new array
        ccArrBack[i] = d;
        i++;

        // Divide number by 10 to get next to last digit
        cc = cc / 10;
    } while (cc > 0);

    // Copy the backwards array to a new forwards array
    while (i > 0)
    {
        ccArr[t] = ccArrBack[i - 1];
        i--;
        t++;
    }
























    /**
     * I SHOULD PUT THE VALIDATION CHECK HERE??
     * */

    /**
     * Luhn's algorithm:
     * 1. Multiply every other digit by 2, starting with the number's second-to-last digit
     *      - Add those products' digits together
     * 2. Add the sum to the sum of the digits that weren't multiplied by 2
     * 3. If the total modulu 10 is congruent to 0, the number is valid :D
     * */

    int luhArr[17];
    int c = 0;

    // Multiply every other digit by 2, starting with the number's second-to-last digit
    for (int a = 1; a <= t; a += 2)
    {
        luhArr[c] = ccArrBack[a] * 2;
        c++;
    }

    // for (int b = 0; b < c + 1; b++)
    // {
    //     printf("%i\n", luhArr[b]);
    // }


    // Now we need to iterate through the array, separate each number, and then add it to a running total

    int luhTot = 0;

    for (int b = 0; b < 17; b++)
    {
        // For each item in the luhArr array, it will  do the following:
        // - separate each individual number and add it to a running total

        int tmp[3];
        int e = 0;

        // So I need to get the last digit of the number



        while (luhArr[b] > 0)
        {
            // Get last digit of entered number
            e = cc % 10;

            // Add digit to new array
            ccArrBack[i] = d;
            i++;

            // Divide number by 10 to get next to last digit
            cc = cc / 10;
        }

    }




































    /**
     * Check card vendor (ASSUMES VALID CARD NUMBER)
     * */

    // VISA
    if (ccArr[0] == 4)
    {
        printf("VISA\n");
    }

    // AMERICAN EXPRESS
    if (ccArr[0] == 3 && ccArr[1] == 4)
    {
        printf("AMERICAN EXPRESS\n");
    }
    else if (ccArr[0] == 3 && ccArr[1] == 7)
    {
        printf("AMERICAN EXPRESS\n");
    }

    // MASTERCARD
    if (ccArr[0] == 5 && ccArr[1] == 1)
    {
        printf("MASTERCARD\n");
    }
    else if (ccArr[0] == 5 && ccArr[1] == 2)
    {
        printf("MASTERCARD\n");
    }
    else if (ccArr[0] == 5 && ccArr[1] == 3)
    {
        printf("MASTERCARD\n");
    }
    else if (ccArr[0] == 5 && ccArr[1] == 4)
    {
        printf("MASTERCARD\n");
    }
    else if (ccArr[0] == 5 && ccArr[1] == 5)
    {
        printf("MASTERCARD\n");
    }
}