#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#endif

// Function to generate random integers
void generateRandomIntegers(int *arr, int n) {
    srand(time(NULL)); // Initialize random seed
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000; // Generate random integers up to 999999
    }
}

// Bubble Sort algorithm
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Selection Sort algorithm
void selectionSort(int *arr, int n) {
    int minIndex;
    for (int i = 0; i < n-1; i++) {
        minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap arr[minIndex] and arr[i]
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort algorithm
void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Pindahkan elemen yang lebih besar dari key ke posisi satu di depannya
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


// Function to save sorted and unsorted arrays to a file
void saveToFile(int *arr, int n, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

int main() {
    int step = 100000; // Step for increasing array size
    int max_size = 1000000; // Maximum array size
    int *arr = (int*)malloc(max_size * sizeof(int));

    for (int size = step; size <= max_size; size += step) {
        // Generate random integers
        generateRandomIntegers(arr, size);

        struct timespec start, end;
        double time_taken;

        // Bubble Sort
        #ifdef _WIN32
        // For Windows
        LARGE_INTEGER frequency;
        LARGE_INTEGER t1, t2;
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&t1);
        bubbleSort(arr, size);
        QueryPerformanceCounter(&t2);
        time_taken = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
        #else
        // For other platforms
        clock_gettime(CLOCK_MONOTONIC, &start);
        bubbleSort(arr, size);
        clock_gettime(CLOCK_MONOTONIC, &end);
        time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1000;
        #endif
        printf("Waktu yang dibutuhkan untuk Bubble Sort dengan %d elemens: %.2fms\n", size, time_taken);
        saveToFile(arr, size, "bubble_sorted.txt");

        // Selection Sort
        #ifdef _WIN32
        QueryPerformanceCounter(&t1);
        selectionSort(arr, size);
        QueryPerformanceCounter(&t2);
        time_taken = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
        #else
        clock_gettime(CLOCK_MONOTONIC, &start);
        selectionSort(arr, size);
        clock_gettime(CLOCK_MONOTONIC, &end);
        time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1000;
        #endif
        printf("waktu yang dibutuhkan untuk Selection Sort dengan %d elemens: %.2fms\n", size, time_taken);
        saveToFile(arr, size, "selection_sorted.txt");

        // Insertion Sort
        #ifdef _WIN32
        QueryPerformanceCounter(&t1);
        insertionSort(arr, size);
        QueryPerformanceCounter(&t2);
        time_taken = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
        #else
        clock_gettime(CLOCK_MONOTONIC, &start);
        insertionSort(arr, size);
        clock_gettime(CLOCK_MONOTONIC, &end);
        time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1000;
        #endif
        printf("waktu yang dibutuhkan untuk Insertion Sort dengan %d elements: %.2fms\n", size, time_taken);
        saveToFile(arr, size, "insertion_sorted.txt");
    }

    free(arr); // Free memory allocated for array

    return 0;
}
