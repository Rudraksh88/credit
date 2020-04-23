#include <stdio.h>
#include <math.h>
// #include <cs50.h>

int main(void)
{
    long long number; // Variable for CC/DC number

    do // Loop to get a valid input
    {
        printf("Number: ");
        scanf("%lld", &number);
    }
    while (number <= 0);

    int digit[16]; // Int array for storing individual digits
    
    int i = 15; // Counter for digit extraction loop
    while (i >= 0) // Loop to pull out each digit from number
    {
        digit[i] = number % 10;
        // printf("%d ", digit[i]);
        i--;
        number /= 10;
    }

    
    int product[8]; // Int array for storing product of digit< > and integer 2 
    for (int j = 0, k = 0 ; j <= 14 ; j += 2, k++)
    {
        // int k = 0;
        product[k] = digit[j] * 2;
        // k++;
    }

    /*int p_digit_sum = 0, prod_sum = 0;
    for (int t = 0; t <= 7 ; t++)
    {
        p_digit_sum = product[t][1] + product[t][2];
        prod_sum += p_digit_sum;
    }*/

    int count = 0, pit_sum = 0, pit[16]; // Loop to calculate sum of products' digits
    for (int m = 0, n = 1; (m + n) <= 30; m += 2, n += 2)
    {
        pit[m] = product[count] % 10;
        pit[n] = product[count] / 10;
        pit_sum += pit[m] + pit[n]; 
        count += 1;
    }

    int odd_sum = 0; // Int var for sum of off digits (digits which were not underlined initially)
    for (int x = 1; x <= 15 ; x += 2) // Loop to calculate sum of odd digits
    {
        odd_sum += digit[x];
    }

    int total = pit_sum + odd_sum; // Total Sum

    int num_length = (int)log10(number) + 1; // Calculates length of Card number

    // Final loop to determine which Bank the card belongs according to the number ranges
    
    if (total % 10 == 0) // Checks if the final sum's last digit is 0
    {
        if (num_length == 16) // Loop for Number length 16
        {
            if (5100000000000000 <= number && number < 5600000000000000)
            {
                printf("MASTERCARD\n");
            }
            else if (4000000000000000 <= number && number < 5000000000000000)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }

        }
        else if (num_length == 15) // Loop for number length 15
        {
            if (340000000000000 <= number && number < 350000000000000)
            {
                printf("AMEX\n");
            }
            else if (370000000000000 <= number && number < 380000000000000)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (num_length == 13) // Loop for number length 13
        {
            if (400000000000 <= number && number < 5000000000000)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else 
        {
            printf("INVALID\n");
        }

    }
    else 
    {
        printf("INVALID\n");
    }
    
}