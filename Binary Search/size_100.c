#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int readArrayFromFile(const char *filename, int arr[], int n){
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Cannot open file: %s\n", filename);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (fscanf(f, "%d", &arr[i]) != 1) {
            printf("Error reading data at index %d\n", i);
            fclose(f);
            return 0;
        }
    }
    fclose(f);
    return 1;
}

int binarySearch(int arr[], int n, int key){
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(){
    int arr[N], key, result;
    clock_t start, end;
    double time_taken;

    const char *cases[] = {"BEST", "WORST", "AVERAGE"};
    const char *files[] = {
        "C:/Users/kulde/Desktop/SEMESTER 5/DAA/txtFiles/best_case_100.txt",
        "C:/Users/kulde/Desktop/SEMESTER 5/DAA/txtFiles/worst_case_100.txt",
        "C:/Users/kulde/Desktop/SEMESTER 5/DAA/txtFiles/average_case_100.txt"
    };

    for (int i = 0; i < 3; i++) {
        if (readArrayFromFile(files[i], arr, N)) {
            printf("\nEnter key to search for %s case: ", cases[i]);
            scanf("%d", &key);

            start = clock();
            result = binarySearch(arr, N, key);
            end = clock();

            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

            if (result != -1)
                printf("%s Case: Key found at index %d\n", cases[i], result);
            else
                printf("%s Case: Key not found\n", cases[i]);

            printf("%s Case Time: %f ms\n", cases[i], time_taken);
        }
    }

    return 0;
}