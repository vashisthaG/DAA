/******************************************************************************
Given an unsorted array of integers, design an algorithm and implement it using a
program to find whether two elements exist such that their sum is equal to the given
key element. (Time Complexity = O(n log n))
Input Format:
The first line contains number of
test cases, T. For each test case,
there will be two input lines. First
line contains n (the size of array).
Second line contains space-separated integers
describing array. Third line contains key
Output Format:
The output will have T number of lines.
For each test case, output will be the elements arr[i] and arr[j] such that arr[i]+arr[j]
= key if exist otherwise print 'No Such Elements Exist”.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) 
{
    int intA = *((int *)a);
    int intB = *((int *)b);

    if (intA < intB) {
        return -1;
    } else if (intA > intB) {
        return 1;
    } else {
        return 0;
    }
}
void findElementsWithSum(int arr[], int n, int key) {
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];

        if (currentSum == key) {
            printf("%d %d\n", arr[left], arr[right]);
            return;
        } else if (currentSum < key) {
            left++;
        } else {
            right--;
        }
    }

    printf("No Such Elements Exist\n");
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

        int key;
        scanf("%d", &key);

        findElementsWithSum(arr, n, key);
    }

    return 0;
}
