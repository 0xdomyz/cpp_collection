// gcc -o string string.c && ./string

void main()
{

    char *string = "Hello, World!";
    char *multi_line_string = "Hello, \
    World!";
    char *string_with_escape = "Hello, \nWorld!";
    char *string_with_escape2 = "Hello, \tWorld!";
    char *string_with_escape3 = "Hello, \x20World!"; // \x20 is space
    char *joined_string = "Hello, "
                          "World!";
    char *joined_string2 = "Hello, "
                           "World!"
                           "How are you?";
}