#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

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

// Insertion Sort implementation
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Optional: print sorted array
void printArray(int arr[], int n) {
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[N];
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
            printf("\nPerforming Insertion Sort for %s case:\n", cases[i]);

            start = clock();
            insertionSort(arr, N);
            end = clock();

            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

            printArray(arr, N);  // Optional: comment if not needed
            printf("%s Case Sort Time: %f ms\n", cases[i], time_taken);
        }
    }

    return 0;
}
