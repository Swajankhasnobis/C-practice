#include <stdio.h>

int extendedEuclidean(int a, int b) {
    int A1 = 1, A2 = 0, A3 = a;
    int B1 = 0, B2 = 1, B3 = b;
    int Q;

    printf("A1\tA2\tA3\tB1\tB2\tB3\tQ\n");

    while (B3 != 0) {
        Q = A3 / B3;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", A1, A2, A3, B1, B2, B3, Q);

        int T1 = A1 - Q * B1;
        int T2 = A2 - Q * B2;
        int T3 = A3 - Q * B3;

        A1 = B1; A2 = B2; A3 = B3;
        B1 = T1; B2 = T2; B3 = T3;
    }

    if (A3 != 1) return -1;
    return (A1 % b + b) % b;
}

int main() {
    int a, b;
    printf("Enter values for a and b: ");
    scanf("%d %d", &a, &b);
    int result = extendedEuclidean(a, b);
    if (result == -1)
        printf("Modular inverse does not exist.\n");
    else
        printf("Modular inverse of %d mod %d is: %d\n", a, b, result);
    return 0;
}
