// gcc linked_list.c -o linked_list && ./linked_list

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct list_ele
{
    int data;
    struct list_ele *pointer;
};

struct list_ele *
sortfun(struct list_ele *list)
{

    int exchange;
    struct list_ele *nextp, *thisp, dummy;

    /*
     * Algorithm is this:
     * Repeatedly scan list.
     * If two list items are out of order,
     * link them in the other way round.
     * Stop if a full pass is made and no
     * exchanges are required.
     * The whole business is confused by
     * working one element behind the
     * first one of interest.
     * This is because of the simple mechanics of
     * linking and unlinking elements.
     */

    dummy.pointer = list;
    do
    {
        exchange = 0;
        thisp = &dummy;
        while ((nextp = thisp->pointer) && nextp->pointer)
        {
            if (nextp->data < nextp->pointer->data)
            {
                /* exchange */
                exchange = 1;
                thisp->pointer = nextp->pointer;
                nextp->pointer =
                    thisp->pointer->pointer;
                thisp->pointer->pointer = nextp;
            }
            thisp = thisp->pointer;
        }
    } while (exchange);

    return (dummy.pointer);
}

int main(void)
{
    struct list_ele *list = NULL;
    struct list_ele *p = NULL;
    struct list_ele *q = NULL;
    int i = 0;

    // seed the random number generator
    srand(time(NULL));

    for (i = 0; i < 10; i++)
    {
        p = (struct list_ele *)malloc(sizeof(struct list_ele));

        // p->data = i;

        // assign random numbers
        p->data = rand() % 100; // 0 - 99

        p->pointer = list;
        list = p;
    }

    // print the list
    printf("The list is:\n");
    p = list;
    while (p)
    {
        printf("%d\n", p->data);
        p = p->pointer;
    }

    q = sortfun(list);

    // print the list
    printf("The list is now:\n");
    while (q)
    {
        printf("%d\n", q->data);
        q = q->pointer;
    }

    return 0;
}