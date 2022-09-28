/**
 * Credit card number validation program.
 *
 * Written by Chance Johnson 2022-09-28
 *
 * This program uses Luhn's Algorithm to determine the syntactical validity of a credit
 * card number.
 *
 * The following steps are taken on the given card number:
 *  1. Multiply every other digit by 2, starting with the number's second-to-last digit.
 *  Add those products' digits together.
 *
 *  2. Add the sum to the sum of the digits that weren't multiplied by 2.
 *
 *  3. If total modulo 10 is congruent with 0, the number is valid!
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void numberToArray(int number, int numberArr[])
{
    int lastDigit;
    int counter = 0;

    do
    {
        /* Store card number digits into array */
        lastDigit = number % 10;
        numberArr[counter] = lastDigit;
        number /= 10;
        counter++;
    } while (number > 0);
}

int main(void)
{
    unsigned long cardNumber = 0;

    /* A valid credit card number will not be longer than 16 digits */
    while (cardNumber < 1 || cardNumber > 9999999999999999)
    {
        printf("Number: ");
        scanf("%lu", &cardNumber);

        /* Clear buffer to prevent endless loops upon entering certain characters, like letters */
        while ((getchar()) != '\n');
    }

    /**
     * STEP 1
     * */
    int cardNumberArr[17];

    numberToArray(cardNumber, cardNumberArr);

    return 0;
}