
#include <stdio.h>
#include <stddef.h>
#include <errno.h>

int main()
{

    errno = 0;
    if (some_library_function(arguments) < 0)
    {
        /* error processing code... */
        /* may use value of errno directly */
        /* or may use perror() */
    }
}