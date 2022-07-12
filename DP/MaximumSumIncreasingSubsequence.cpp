// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

private:
    int N;
    int **dp;

public:
    int checkSumSub(int arr[], int n, int preIdx)
    {
        if (n == 0)
            return 0;

        if (dp[n][preIdx] != -1)
            return dp[n][preIdx];

        else if (preIdx == N || arr[n - 1] < arr[preIdx])
        {
            int inclusion = arr[n - 1] + checkSumSub(arr, n - 1, n - 1);
            int exclusion = checkSumSub(arr, n - 1, preIdx);
            return dp[n][preIdx] = max(inclusion, exclusion);
        }

        else
            return dp[n][preIdx] = checkSumSub(arr, n - 1, preIdx);
    }

    int maxSumIS(int arr[], int n)
    {
        // Your code goes here
        int **dp = new int *[n + 1];
        for (int i = 0; i <= n; i++)
            dp[i] = new int[n + 1];

        this->dp = dp;
        this->N = n;

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = -1;

        checkSumSub(arr, n, n);
        return this->dp[n][n];
        /*int dp[n+1];
        dp[0] = 0;
        int maxSum = arr[0];

        for(int i = 1; i <=n; i++)
           {
               dp[i] = arr[i-1];
               for(int j = 1; j < i; j++)
                   if(arr[j-1] < arr[i-1])
                    dp[i] = max(dp[i], dp[j] + arr[i-1]);

               maxSum = max(maxSum,dp[i]);
           }
           return maxSum;*/
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.maxSumIS(a, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends