// Problem Statement
// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

// Input Format
// An integer array arr[].

// Output Format
// Print the length of the longest subarray with sum equal to zero.

// Sample Input
// 15 -2 2 -8 1 7 10 23

// Sample Output
// 5

// Explanation
// The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.

#include <stdio.h>

int longestZeroSumSubarray(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Using large array as hashmap (for simplicity)
    int hash[20001];
    
    // Initialize with -1
    for (int i = 0; i < 20001; i++)
        hash[i] = -2;

    // To handle sum = 0 at index -1
    hash[10000] = -1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        int index = sum + 10000; // shift to handle negative sums

        if (hash[index] != -2) {
            int len = i - hash[index];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[index] = i; // store first occurrence
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = longestZeroSumSubarray(arr, n);
    printf("%d", result);

    return 0;
}