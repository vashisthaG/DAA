/******************************************************************************
 Given an unsorted array of integers, design an algorithm and implement it using a
program to sort an array of elements by partitioning the array into two subarrays
based on a pivot element such that one of the sub array holds values smaller than
the pivot element while another sub array holds values greater than the pivot
element. Pivot element should be selected randomly from the array. Your program
should also find number of comparisons and swaps required for sorting the array.
Input Format:
The first line contains number of test cases, T.
For each test case, there will be two input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high, int *comparisons, int *swaps) {
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[high]);
    (*swaps)++;

    int i = low - 1;
    for (int j = low; j < high; j++) {
        (*comparisons)++;
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            (*swaps)++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    (*swaps)++;

    return i + 1;
}
void quicksort(int arr[], int low, int high, int *comparisons, int *swaps) 
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high, comparisons, swaps);
        quicksort(arr, low, pivotIndex - 1, comparisons, swaps);
        quicksort(arr, pivotIndex + 1, high, comparisons, swaps);
    }
}

int main() 
{
    int T;
    scanf("%d", &T);
    while (T--) 
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int comparisons = 0;
        int swaps = 0;
        quicksort(arr, 0, n - 1, &comparisons, &swaps);
        printf("sorted array:");
        for (int i = 0; i < n; i++) {
            printf(" %d", arr[i]);
        }
        printf("\n");
        printf("comparisons: %d\n", comparisons);
        printf("swaps: %d\n", swaps);
    }

    return 0;
}
