#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

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

// Heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // left child
    int right = 2 * i + 2;    // right child

    // If left child is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest); // Recursively heapify affected sub-tree
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);  // Move current root to end
        heapify(arr, i, 0);      // call max heapify on reduced heap
    }
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
            printf("\nPerforming Heap Sort for %s case:\n", cases[i]);

            start = clock();
            heapSort(arr, N);
            end = clock();

            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

            printf("%s Case Sort Time: %f ms\n", cases[i], time_taken);
        }
    }

    return 0;
}
