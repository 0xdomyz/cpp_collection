// gcc -o ctype ctype.c && ./ctype

#include <ctype.h>
#include <stdio.h>

int main(void)
{

    // example usage of functions

    printf("isalnum('a') = %d\n", isalnum('a'));
    printf("isalnum('1') = %d\n", isalnum('1'));
    printf("isalnum(1) = %d\n", isalnum(1));

    printf("isalpha('a') = %d\n", isalpha('a'));

    // control characters are characters that have a code less than 32 or equal to 127
    printf("iscntrl('\\n') = %d\n", iscntrl('\n'));

    printf("isdigit('1') = %d\n", isdigit('1'));
    printf("isdigit(1) = %d\n", isdigit(1));

    // printing character except space are: ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~
    printf("isgraph('!') = %d\n", isgraph('!'));
    printf("isprint(' ') = %d\n", isprint(' '));

    printf("islower('a') = %d\n", islower('a'));
    printf("isupper('A') = %d\n", isupper('A'));

    printf("ispunct('!') = %d\n", ispunct('!'));

    printf("isspace(' ') = %d\n", isspace(' '));

    printf("isxdigit(3) = %d\n", isxdigit(3));
    printf("isxdigit(0x3) = %d\n", isxdigit(0x3));
    printf("isxdigit('3') = %d\n", isxdigit('3'));

    // input a string and convert all the letters' cases
    int c;

    while ((c = getchar()) != EOF)
    {
        if (isalpha(c))
        {
            if (isupper(c))
            {
                c = tolower(c);
            }
            else
            {
                c = toupper(c);
            }
        }
        putchar(c);
    }

    return 0;
}