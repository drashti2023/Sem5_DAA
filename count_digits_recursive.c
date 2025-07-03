#include <stdio.h>

int countDigits(int n) {
    if (n == 0)
        return 0;
    return 1 + countDigits(n / 10);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n == 0)
        printf("Total digits = 1\n");  
    else {
        printf("Total digits = %d\n", countDigits(n));
    }

    return 0;
}
