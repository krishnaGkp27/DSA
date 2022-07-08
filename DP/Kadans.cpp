// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
#define INF 0x3f3f3f3f;
    int ans = -INF;
    vector<long long> dp;

public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {
        long long previousSum = -INF;
        long long maxSum = -INF;

        for (int i = 1; i <= n; i++)
        {
            if (previousSum < 0)
                previousSum = arr[i - 1];
            else
                previousSum += arr[i - 1];

            maxSum = max(maxSum, previousSum);
        }
        return maxSum;
    }
};

// { Driver Code Starts.

int main()
{
    int t, n;

    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {

        cin >> n; // input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; // inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends