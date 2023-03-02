// gcc -o array_pointer array_pointer.c && ./array_pointer

int main(void)
{
    // pointer to array
    int ar[10];
    int *ip;
    int(*ar10i)[10]; /* pointer to array of 10 ints */

    ip = ar;     /* address of first element */
    ip = &ar[0]; /* address of first element */
    ar10i = &ar; /* address of whole array */

    // multi-dimensional arrays
    int ar2d[5][4];
    int(*ar4i)[4]; /* pointer to array of 4 ints */

    for (ar4i = ar2d; ar4i < &(ar2d[5]); ar4i++)
        (*ar4i)[2] = 0; /* ar2d[n][2] = 0 */

    // array as function argument
    void f(int ar[10]);
    void f(int *ar);
    void f(int ar[]); /* since the size of the array is irrelevant! */
}