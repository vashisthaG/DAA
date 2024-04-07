/******************************************************************************
Given an unsorted array of integers, design an algorithm and implement it using a
program to sort an array of elements by dividing the array into two subarrays and
combining these subarrays after sorting each one of them. Your program should
also find number of comparisons and inversions during sorting the array.
Input Format:
The first line contains number of
test cases, T. For each test case,
there will be two input lines. First
line contains n (the size of array).
Second line contains space-separated integers describing array.
*******************************************************************************/
#include <stdio.h>
int merge(int arr[], int temp[], int left, int mid, int right) 
{
    int i = left, j = mid, k = left;
    int inversions = 0;
    while (i < mid && j <= right) 
    {
        if (arr[i] <= arr[j]) 
        {
            temp[k++] = arr[i++];
        } else
        {
            inversions += mid - i;
            temp[k++] = arr[j++];
        }
    }

    while (i < mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inversions;
}

int mergesort(int arr[], int temp[], int left, int right) 
{
    int inversions = 0;
    if (left < right) 
    {
        int mid = (left + right) / 2;
        inversions += mergesort(arr, temp, left, mid);
        inversions += mergesort(arr, temp, mid + 1, right);
        inversions += merge(arr, temp, left, mid + 1, right);
    }

    return inversions;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        int temp[n];
        int inversions = mergesort(arr, temp, 0, n - 1);
        printf("sorted array:");
        for (int i = 0; i < n; i++) {
            printf(" %d", arr[i]);
        }
        printf("\n");
        printf("comparisons: %d\n", n * (n - 1) / 2); 
        printf("inversions: %d\n", inversions);
    }

    return 0;
}
