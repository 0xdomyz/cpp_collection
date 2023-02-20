// gcc -o qualified_pointers qualified_pointers.c && ./qualified_pointers

int main()
{
    int i;            /* i is an ordinary int */
    const int ci = 1; /* ci is a constant int */
    int *pi;          /* pi is a pointer to an int */
    const int *pci;   /* pci is a pointer to a constant int */
                      /* and now the more complicated stuff */

    /* cpi is a constant pointer to an int */
    int *const cpi = &i;

    /* cpci is a constant pointer to an constant int */
    const int *const cpci = &ci;
}