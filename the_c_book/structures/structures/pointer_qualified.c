// gcc pointer_qualified.c -o pointer_qualified && ./pointer_qualified

#include <stdio.h>
#include <stdlib.h>

struct somestruct
{
    int i;
};

main()
{
    struct somestruct *ssp, s_item;
    const struct somestruct *cssp;

    s_item.i = 1; /* fine */
    ssp = &s_item;
    ssp->i += 2; /* fine */
    cssp = &s_item;
    // cssp->i = 0; /* not permitted - cssp points to const objects */

    exit(EXIT_SUCCESS);
}