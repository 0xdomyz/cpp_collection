// gcc -o bitfields bitfields.c && ./bitfields

#include <stdio.h>

struct
{
    /* field 4 bits wide */
    unsigned field1 : 4;
    /*
     * unnamed 3 bit field
     * unnamed fields allow for padding
     */
    unsigned : 3;
    /*
     * one-bit field
     * can only be 0 or -1 in two's complement!
     */
    signed field2 : 1;
    /* align next field on a storage unit */
    unsigned : 0;
    unsigned field3 : 6;
} full_of_fields;

int main(void)
{
    /* set the fields */
    full_of_fields.field1 = 0x5;
    full_of_fields.field2 = -1;
    full_of_fields.field3 = 0x3f;

    /* print the fields */
    printf("field1: %x\n", full_of_fields.field1);
    printf("field2: %x\n", full_of_fields.field2);
    printf("field3: %x\n", full_of_fields.field3);

    return 0;
}
