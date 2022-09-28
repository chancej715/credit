/**
 * Credit card number validation program for Problem Set 1
 *
 * Written by Chance Johnson 2022-09-28
 * */

/**
 * American Express numbers start with 34 or 37
 * MasterCard numbers start with 51, 52, 53, 54, or 55
 * All Visa numbers start with 4
 * */

/**
 * Two parts to this assignment:
 *  1. Determine whether the CC is American Express, Mastercard, or Visa
 *      - I'll start with this first, because it should be pretty easy
 *
 *  2. Determine if it's a valid CC
 * */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Value range of 0 to 18446744073709551615
    unsigned long cc = 0;

    // If the user doesn't enter a number, cc will be 0
    while (!cc)
    {
        printf("Number: ");
        scanf("%lu", &cc);

        // Clear the buffer
        while ((getchar()) != '\n');
    }
}