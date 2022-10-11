/**
 * Author: Chance Johnson
 * Date: 2022-09-28
 * Description: Credit card number validation program which uses Luhn's Algorithm to determine
 * the syntactical validity of a credit card number.
 *
 * Luhn's Algorithm:
 *  1. Multiply every other digit of the card number by 2, starting with the number's
 *  second-to-last digit. Add those products' digits together.
 *  2. Add the sum to the sum of the digits that weren't multiplied by 2.
 *  3. If total modulo 10 is congruent with 0, the number is valid!
 *  
 *  If the card is valid, it then determines the card issuer by checking the first few
 *  digits of the number. This part of the program only supports Visa, American Express,
 *  and some MasterCard numbers.
 * 
 *  Designed to work only with American Express, Visa, and most MasterCard numbers.
 * */

#include <stdio.h>

void numberToArray(unsigned long number, int array[]);
unsigned long calculateNumberOfDigits(unsigned long number);

int main(void)
{
    unsigned long cardNumber = 0;

    // A valid credit card number will not be longer than 16 digits
    while (cardNumber < 1 || cardNumber > 9999999999999999)
    {
        printf("Number: ");
        scanf("%lu", &cardNumber);

        // Clear buffer to prevent endless loops upon entering certain characters, like letters
        while ((getchar()) != '\n');
    }

    int cardNumberLength = calculateNumberOfDigits(cardNumber);
    int cardNumberArray[cardNumberLength];

    // Turn the entered card number into an array
    numberToArray(cardNumber, cardNumberArray);

    // Multiply every other digit by 2, starting from the second to last digit
    int everyOtherTimesTwoTotal = 0;

    for (int i = 1; i < cardNumberLength; i += 2)
    {
        if (cardNumberArray[i])
        {
            if (cardNumberArray[i] * 2 < 10)
                everyOtherTimesTwoTotal += cardNumberArray[i] * 2; // 1 through 9, inclusive
            else
            {
                // 10 through 18, inclusive
                int tempArray[2];
                numberToArray(cardNumberArray[i] * 2, tempArray);

                // Each digit added to running total separately
                for (int j = 0; j < 2; j++)
                    everyOtherTimesTwoTotal += tempArray[j];
            }

            cardNumberArray[i] = 0;
        }
    }

    // Determine if length of card is at least 13 characters
    if (cardNumberLength < 13)
    {
        printf("INVALID\n");
        return 0;
    }

    // Add that sum to the sum of the digits that weren't multiplied by 2
    for (int i = 0; i < cardNumberLength; i++)
        everyOtherTimesTwoTotal += cardNumberArray[i];

    if (everyOtherTimesTwoTotal % 10 == 0)
    {
        // Card number is syntactically correct according to Luhn's Algorithm
        numberToArray(cardNumber, cardNumberArray);

        if (cardNumberArray[cardNumberLength - 1] == 4)
            printf("VISA\n");
        else if (cardNumberArray[cardNumberLength - 1] == 3)
            if (cardNumberArray[cardNumberLength - 2] == 4 || cardNumberArray[cardNumberLength - 2] == 7)
                printf("AMEX\n");
            else
                printf("INVALID\n");
        else if (cardNumberArray[cardNumberLength - 1] == 5)
            if (cardNumberArray[cardNumberLength - 2] + 5 < 11)
                printf("MASTERCARD\n");
            else
                printf("INVALID\n");
    }
    else
        printf("INVALID\n");

    return 0;
}

// Given a number and array, put each digit in the number into the array (backwards)
void numberToArray(unsigned long number, int array[])
{
    int lastDigit;
    int counter = 0;

    do
    {
        // Store card number digits into array
        lastDigit = number % 10;
        array[counter] = lastDigit;
        number /= 10;
        counter++;
    } while (number > 0);
}

// Given a number, return number of digits in that number
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