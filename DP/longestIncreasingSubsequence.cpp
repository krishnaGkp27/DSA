// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
#define INF 0x3f3f3f3f
    // Function to find length of longest increasing subsequence.
    vector<int> dp;
    int solve(int n, int a[], int pre)
    {
        if (n == 0)
            return 0;

        if (a[n - 1] < pre)
            return max(1 + solve(n - 1, a, a[n - 1]), solve(n - 1, a, pre));

        else
            return solve(n - 1, a, pre);
    }
    int longestSubsequence(int n, int a[])
    {
        // your code here
        dp.resize(n, 1);
        int maxSubSeq = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                if (a[j] < a[i])
                    dp[i] = max(dp[i], 1 + dp[j]);

            maxSubSeq = max(maxSubSeq, dp[i]);
        }
        return maxSubSeq;
        // return solve(n,a,INF);
    }
};

// { Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends