#include <stdio.h>

int main() {
    int n, i, sum = 0, num;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);
        sum += num;
    }

    printf("The sum of %d numbers is: %d\n", n, sum);
    
    return 0;
}