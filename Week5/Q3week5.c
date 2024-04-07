/******************************************************************************
Givenan unsorted array of positive integers, design an algorithm and implement it using a
program to find whether there are any duplicate elements in the array or not. (use sorting) (Time
Complexity =O(n log n))
Input Format:
The first line contains number of test cases, T.
For each test case, there will be two input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Output Format:
The output will have T number of lines.
For each test case, output will be 'YES' if duplicates are present otherwise 'NO
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
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
int hasDuplicates(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            return 1; 
        }
    }

    return 0;
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

        if (hasDuplicates(arr, n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
