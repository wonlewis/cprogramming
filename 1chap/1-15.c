#include <stdio.h>
#define LOWER 0;
#define UPPER 300
#define STEP 20

float conversion(float fahr);

int main()
{
    float fahr, celsius;
    fahr = LOWER;
    while (fahr <= UPPER)
    {
        celsius = conversion(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }
}

float conversion(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}