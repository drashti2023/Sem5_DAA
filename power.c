#include <stdio.h>
int main() {
    int a, b, result = 1;
    printf("Enter base (a) and exponent (b): ");
    scanf("%d %d", &a, &b);

    int i = 1;
    while (i <= b) {
        result *= a;
        i++;
    }

    printf("%d^%d = %d\n", a, b, result);
    return 0;
}
