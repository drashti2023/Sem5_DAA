#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

// Read array from file
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

// Swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    // Random pivot to prevent skewed partitions
    int pivotIndex = low + rand() % (high - low + 1);
    swap(&arr[pivotIndex], &arr[high]);  // Move random pivot to end

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}


// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort left and right partitions
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[N];
    clock_t start, end;
    double time_taken;

    const char *cases[] = {"BEST", "WORST", "AVERAGE"};
    const char *files[] = {
        "C:/Users/kulde/Desktop/SEMESTER 5/DAA/txtFiles/best_case_100000.txt",
        "C:/Users/kulde/Desktop/SEMESTER 5/DAA/txtFiles/worst_case_100000.txt",
        "C:/Users/kulde/Desktop/SEMESTER 5/DAA/txtFiles/average_case_100000.txt"
    };

    for (int i = 0; i < 3; i++) {
        if (readArrayFromFile(files[i], arr, N)) {
            printf("\nPerforming Quick Sort for %s case:\n", cases[i]);

            start = clock();
            quickSort(arr, 0, N - 1);
            end = clock();

            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000 ;

            printf("%s Case Sort Time: %f ms\n", cases[i], time_taken);
        }
    }

    return 0;
}
