#include <limits.h>
#include <float.h>
#include <stdio.h>

int main()
{
    printf("The range of signed char is [%d, %d] \n", CHAR_MIN, CHAR_MAX);
    printf("The range of unsigned char is [%u, %u] \n", 0, UCHAR_MAX);
    printf("The range of signed short is [%hd, %hd] \n", SHRT_MIN, SHRT_MAX);
    printf("The range of unsigned short is [%hu, %hu] \n", 0, USHRT_MAX);
    printf("The range of signed int is [%d, %d] \n", INT_MIN, INT_MAX);
    printf("The range of unsigned int is [%u, %u] \n", 0, UINT_MAX);
    printf("The range of signed long is [%ld, %ld] \n", LONG_MIN, LONG_MAX);
    printf("The range of unsigned long is [%lu, %lu] \n", 0, ULONG_MAX);
}