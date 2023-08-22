#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned pushNBitsFromPToRight(unsigned x, int p, int n);
unsigned turnNBitsFromRightToOne(unsigned y, int n);
unsigned combineNBitsFromRight(unsigned x, unsigned y);

int main(void) { printf("%u", setbits((unsigned)12, 3, 2, (unsigned)57)); }

unsigned pushNBitsFromPToRight(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned turnNBitsFromRightToOne(unsigned y, int n)
{
    unsigned turnNBitsFromRightToZero = (y >> n) << n;
    unsigned inverseClearedY = ~y;
    unsigned turnNBitsFromRightOfInverseClearedYToZero = (inverseClearedY >> n) << n;
    return ~turnNBitsFromRightOfInverseClearedYToZero;
}

unsigned combineNBitsFromRight(unsigned x, unsigned y)
{
    return x | y;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned a, b, result;
    a = pushNBitsFromPToRight(x, p, n);
    b = turnNBitsFromRightToOne(y, n);
    return combineNBitsFromRight(a, b);
}
