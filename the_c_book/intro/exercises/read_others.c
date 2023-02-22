// gcc -o read_others read_others.c && ./read_others

#include <stdio.h>
#include <stdlib.h>

int read_decimal(void)
{
    int n = 0;
    int ch;
    while ((ch = getchar()) != '\n')
    {
        // int
        n = n * 10 + (ch - '0');
    }
    return n;
}

int convert_to_binary(int n)
{
    // conver decimal int n to binary
    int binary = 0;
    int remainder;
    int i = 1;
    while (n != 0)
    {
        remainder = n % 2;
        n /= 2;
        binary += remainder * i;
        i *= 10;
    }
    return binary;
}

char *convert_to_hexadecimal(int n)
{
    // conver decimal int n to hexadecimal, 0 - 9, A - F
    char *hexadecimal = malloc(100 * sizeof(char));
    int remainder;
    int i = 0;
    while (n != 0)
    {
        remainder = n % 16;
        n /= 16;
        if (remainder < 10)
        {
            hexadecimal[i] = remainder + '0';
        }
        else if (remainder == 10)
        {
            hexadecimal[i] = 'A';
        }
        else if (remainder == 11)
        {
            hexadecimal[i] = 'B';
        }
        else if (remainder == 12)
        {
            hexadecimal[i] = 'C';
        }
        else if (remainder == 13)
        {
            hexadecimal[i] = 'D';
        }
        else if (remainder == 14)
        {
            hexadecimal[i] = 'E';
        }
        else if (remainder == 15)
        {
            hexadecimal[i] = 'F';
        }
        i++;
    }

    // reverse the string
    int j = 0;
    int k = i - 1;
    char temp;
    while (j < k)
    {
        temp = hexadecimal[j];
        hexadecimal[j] = hexadecimal[k];
        hexadecimal[k] = temp;
        j++;
        k--;
    }

    // end of string
    hexadecimal[i] = 0;

    // append 0x
    char *hexadecimal2 = malloc(100 * sizeof(char));
    hexadecimal2[0] = '0';
    hexadecimal2[1] = 'x';
    int l = 2;
    while (hexadecimal[l - 2] != 0)
    {
        hexadecimal2[l] = hexadecimal[l - 2];
        l++;
    }
    hexadecimal2[l] = 0;

    free(hexadecimal);

    return hexadecimal2;
}

int main(void)
{
    int n;
    printf("Enter a number: ");

    n = read_decimal();
    printf("You entered %d\n", n);

    int n2 = convert_to_binary(n);
    printf("You entered binary %d\n", n2);

    char *hexadecimal;
    hexadecimal = convert_to_hexadecimal(n);
    printf("You entered hexadecimal %s\n", hexadecimal);

    free(hexadecimal);
    return 0;
}
