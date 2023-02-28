// gcc -o hide hide.c && ./hide

int a; /* visible from here onwards */

void func(void)
{
    float a; /* a different 'a' */
    {
        char a; /* yet another 'a' */
    }
    /* the float 'a' reappears */
}
/* the int 'a' reappears */

int main(void)
{
    func();
    return 0;
}