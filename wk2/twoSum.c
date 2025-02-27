#include <stdbool.h>
#include <stdio.h>

// return whether there are two numbers in the array that sum to 'sum'
// n = size of the array
// [1,2,3,4,5], sum = 7 => true
// [1,2,3,4,5], sum = 10 => false
// O(n^2)
bool hasTwoSum(int *arr, int n, int sum) {
    for (int i = 0; i < n; i++) {  // O(n)
        int other = sum - arr[i];
        for (int j = i + 1; j < n; j++) {  // O(n)
            if (arr[j] == other) {
                return true;
            }
        }
    }
    return false;
}
