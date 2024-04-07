/******************************************************************************
Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))
Input Format:
The first line contains number of test cases, T.
For each test case, there will be three input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Third line contains K.
Output Format:
The output will have T number of lines.
For each test case, output will be the Kth smallest or largest array element.
If no Kth element is present, output should be “not present”.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
int kthSmallest(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - low == k - 1) {
            return arr[pivotIndex];
        }

        if (pivotIndex - low > k - 1) {
            return kthSmallest(arr, low, pivotIndex - 1, k);
        }

        return kthSmallest(arr, pivotIndex + 1, high, k - pivotIndex + low - 1);
    }

    return -1; 
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

        int k;
        scanf("%d", &k);

        int result = kthSmallest(arr, 0, n - 1, k);

        if (result != -1) {
            printf("%d\n", result);
        } else {
            printf("not present\n");
        }
    }
    return 0;
}

