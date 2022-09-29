/**
 * Credit card number validation program.
 *
 * Written by Chance Johnson 2022-09-28
 *
 * This program uses Luhn's Algorithm to determine the syntactical validity of a credit
 * card number.
 *
 * The following steps are taken on the given card number:
 *
 *  1. Multiply every other digit by 2, starting with the number's second-to-last digit.
 *  Add those products' digits together.
 *
 *  2. Add the sum to the sum of the digits that weren't multiplied by 2.
 *
 *  3. If total modulo 10 is congruent with 0, the number is valid!
 *
 *  If the card is valid, it then determines the card issuer by checking the first few digits of the number.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Given a number and array, put each digit in the number into the array (backwards) */
void numberToArray(unsigned long number, int array[])
{
    int lastDigit;
    int counter = 0;

    do
    {
        /* Store card number digits into array */
        lastDigit = number % 10;
        array[counter] = lastDigit;
        number /= 10;
        counter++;
    } while (number > 0);
}

/* Given a number, return number of digits in that number */
unsigned long calculateNumberOfDigits(unsigned long number)
{
    int numberOfDigits = 0;

    while (number > 0)
    {
        numberOfDigits++;
        number /= 10;
    }

    return numberOfDigits;
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

    int cardNumberLength = calculateNumberOfDigits(cardNumber);
    int cardNumberArray[cardNumberLength];

    /* Turn the entered card number into an array */
    numberToArray(cardNumber, cardNumberArray);

    /* Multiply every other digit by 2, starting from the second to last digit */
    int everyOtherTimesTwoTotal = 0;

    for (int i = 1; i < cardNumberLength; i += 2)
    {
        if (cardNumberArray[i])
        {
            if (cardNumberArray[i] * 2 < 10)
            {
                /* 1 through 9, inclusive */
                everyOtherTimesTwoTotal += cardNumberArray[i] * 2;
            }
            else
            {
                /* 10 through 18, inclusive */
                int tempArray[3];
                numberToArray(cardNumberArray[i] * 2, tempArray);

                /* Each digit added to running total separately */
                for (int j = 0; j < 2; j++)
                    everyOtherTimesTwoTotal += tempArray[j];
            }

            cardNumberArray[i] = 0;
        }
    }

    /* Add that sum to the sum of the digits that weren't multiplied by 2 */
    for (int i = 0; i < cardNumberLength; i++)
        everyOtherTimesTwoTotal += cardNumberArray[i];

    if (everyOtherTimesTwoTotal % 10 == 0)
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}