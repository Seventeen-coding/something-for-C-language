/*
<errno.h>	报告错误条件的宏
*/
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <string.h>
extern int errno;
int main(void)
{
    FILE *fp;

    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Value of errno: %d\n", errno);
        char *err = strerror(errno);
        fprintf(stderr, "Error opening file: %s\n", err);
    }
    else
    {
        fclose(fp);
    }
    double  val;

    val = sqrt(-10);
    if (errno == EDOM)
    {
        printf("Invalid value \n");
    }
    else
    {
        printf("Valid value\n");
    }


    val = sqrt(10);
    if (errno == EDOM)
    {
        printf("Invalid value\n");
    }
    else
    {
        printf("Valid value\n");
    }

    double x;
    double value;

    x = 2.000000;
    value = log(x);

    if (errno == ERANGE)
    {
        printf("Log(%f) is out of range\n", x);
    }
    else
    {
        printf("Log(%f) = %f\n", x, value);
    }

    x = 1.000000;
    value = log(x);

    if (errno == ERANGE)
    {
        printf("Log(%f) is out of range\n", x);
    }
    else
    {
        printf("Log(%f) = %f\n", x, value);
    }

    x = 0.000000;
    value = log(x);

    if (errno == ERANGE)
    {
        printf("Log(%f) is out of range\n", x);
    }
    else
    {
        printf("Log(%f) = %f\n", x, value);
    }
    return 0;
}
