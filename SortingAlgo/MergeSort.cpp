//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
public:
    void merge(int arr[], int l, int m, int r)
    {
        // Your code here
        int leftIdx = l;
        int midIdx = m + 1;
        int temp[r - l + 1];
        int idx = 0;

        while (leftIdx <= m && midIdx <= r)
        {
            if (arr[leftIdx] <= arr[midIdx])
                temp[idx++] = arr[leftIdx++];
            else
                temp[idx++] = arr[midIdx++];
        }

        while (leftIdx <= m)
            temp[idx++] = arr[leftIdx++];

        while (midIdx <= r)
            temp[idx++] = arr[midIdx++];

        for (int i = l; i <= r; i++)
            arr[i] = temp[i - l];
    }

public:
    void mergeSort(int arr[], int l, int r)
    {
        // code here
        if (l >= r)
            return;
        // cout<<l<<r<<endl;
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
};

//{ Driver Code Starts.

int main()
{
    int n, T, i;

    scanf("%d", &T);

    while (T--)
    {

        scanf("%d", &n);
        int arr[n + 1];
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;
        ob.mergeSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends