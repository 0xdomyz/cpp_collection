// gcc -o prompt prompt.c && ./prompt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    // prompt for a string
    char *str = malloc(100);
    printf("Enter a string: ");
    scanf("%s", str);

    // print the string
    printf("You entered: %s\n", str);

    // print the length of the string
    printf("The length of the string is: %lu\n", strlen(str));

    // free the memory
    free(str);

    // prompt for program to exit
    printf("Press enter to exit");
    getchar();
    getchar(); // getchar() twice to read the newline character

    return 0;
}
