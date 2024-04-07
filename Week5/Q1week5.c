/******************************************************************************
Given an unsorted array of alphabets containing duplicate elements. Design an algorithm
and implement it using a program to find which alphabet has maximum number of
occurrences andprint it. (Time Complexity = O(n)) (Hint: Use counting sort)
Input Format:
The first line contains number of
test cases, T. For each test case,
there will be two input lines. First
line contains n (the size of array).
Second line contains space-separated integers describing array.
Output:
The output will have T number of lines.
For each test case, output will be the array element which has maximum occurrences and
its total number of occurrences.
If no duplicates are present (i.e. all the elements occur only once), output should be
“No Duplicates Present”
*******************************************************************************/
#include <stdio.h>
#include <string.h>

void findMaxOccurrence(char arr[], int n) {
    int count[26] = {0}; 
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 'a' && arr[i] <= 'z') {
            count[arr[i] - 'a']++;
        }
    }

    int maxCount = 0;
    char maxAlphabet = '\0';
    for (int i = 0; i < 26; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            maxAlphabet = 'a' + i;
        }
    }

    if (maxCount > 1) {
        printf("%c %d\n", maxAlphabet, maxCount);
    } 
    else 
    {
        printf("No Duplicates Present\n");
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
        char arr[n + 1]; 
        for (int i = 0; i < n; i++) {
            scanf(" %c", &arr[i]); 
        }
        arr[n] = '\0'; 
        findMaxOccurrence(arr, n);
    }

    return 0;
}
