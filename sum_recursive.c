#include <stdio.h>

int sumRecursive(int n) {
    if (n == 0)
        return 0;
    
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    return num + sumRecursive(n - 1);
}

int main() {
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Sum of entered numbers = %d\n", sumRecursive(n));

    return 0;
}