#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

int partition(int A[], int lb, int ub) {
    int pivot = A[lb], i = lb, j = ub;
    while (i <= j) {
        while (i <= ub && A[i] <= pivot)
            i++;
        while (j >= lb+1 && A[j] > pivot)
            j--;
        if (i < j) {
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    int t = A[j];
    A[j] = A[lb];
    A[lb] = t;
    return j;
}

void quicksort(int A[], int lb, int ub) {
    if (lb < ub) {
        int k = partition(A, lb, ub);
        quicksort(A, lb, k - 1);
        quicksort(A, k + 1, ub);
    }
}

int main() {
    int arr[MAX];
    srand(time(NULL));

    for (int i = 1; i <= 10; i++) {
        int n = i * 10000;

        // generate random array
        for (int j = 0; j < n; j++)
            arr[j] = rand() % 200000;

        clock_t start = clock();

        quicksort(arr, 0, n - 1);

        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Input Size = %d, Time Taken = %f seconds\n", n, time_taken);
    }

    return 0;
}
