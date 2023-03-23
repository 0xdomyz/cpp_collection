// g++ files.cpp -o files -std=c++11 && ./files

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(void)
{
    // fopen
    FILE *fp = fopen("input.csv", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return (-1);
    }

    // print out
    char line[256];
    while (fgets(line, sizeof(line), fp))
    {
        printf("%s", line);

        // seperately print out columns as string and double
        char *col1;
        double col2;

        // get first column
        col1 = strtok(line, ",");
        printf("%s", col1);

        // get second column
        col2 = atof(strtok(NULL, ","));
        printf("%f", col2);

        printf("\n");
    }

    // fclose
    fclose(fp);

    return (0);
}