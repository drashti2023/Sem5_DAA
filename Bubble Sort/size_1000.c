#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

// Function to read array from file
int readArrayFromFile(const char *filename, int arr[], int n) {
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

// Bubble Sort implementation
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;  // Optimization: track if any swap happened
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;  // If no swaps in this pass, array is sorted
    }
}

int main() {
    int arr[N];
    clock_t start, end;
    double time_taken;

    const char *cases[] = {"BEST", "WORST", "AVERAGE"};
    const char *files[] = {
        "C:/Users/kulde/Desktop/SEMESTER 5/DAA/txtFiles/best_case_1000.txt",
        "C:/Users/kulde/Desktop/SEMESTER 5/DAA/txtFiles/worst_case_1000.txt",
        "C:/Users/kulde/Desktop/SEMESTER 5/DAA/txtFiles/average_case_1000.txt"
    };

    for (int i = 0; i < 3; i++) {
        if (readArrayFromFile(files[i], arr, N)) {
            printf("\nPerforming Bubble Sort for %s case:\n", cases[i]);

            start = clock();
            bubbleSort(arr, N);
            end = clock();

            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

            printf("%s Case Sort Time: %f ms\n", cases[i], time_taken);
        }
    }

    return 0;
}
