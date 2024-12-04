#include <stdio.h>
unsigned long long squareAndMultiply(unsigned long long a, unsigned long long b, unsigned long long m) 
{
    unsigned long long result = 1;
    int c=1;
    a = a % m;  
    while (b > 0) 
    {
        if (b % 2 == 1) 
        {
            result = (result * a) % m;
            printf("Result after %d iteration is %llu\n",c,result);
            c++;
        }
        a = (a * a) % m;
        b /= 2;  
    }
    return result;
}
int main() 
{
    unsigned long long a, b, m;
    printf("Enter base (a): ");
    scanf("%llu", &a);
    printf("Enter exponent (b): ");
    scanf("%llu", &b);
    printf("Enter modulus (m): ");
    scanf("%llu", &m);
    unsigned long long result = squareAndMultiply(a, b, m);
    printf("%llu^%llu mod %llu = %llu\n", a, b, m, result);
    return 0;
}
