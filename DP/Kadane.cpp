// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
#define INF 1e18;

public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {

        vector<long long> dp(n + 1);
        dp[0] = 0;
        long long maxSum = -INF;

        for (int i = 1; i <= n; i++)
        {
            dp[i] = max(dp[i - 1] + arr[i - 1], (long long)arr[i - 1]);
            maxSum = max(maxSum, dp[i]);
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