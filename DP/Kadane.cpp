// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
#define INF 0x3f3f3f3f;
    int ans = -INF;

public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {

        vector<long long> dp(n + 1);
        dp[1] = arr[0];
        long long maxSum = arr[0];

        for (int i = 2; i <= n; i++)
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