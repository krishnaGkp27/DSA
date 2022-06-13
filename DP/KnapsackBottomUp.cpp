#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    vector<vector<int>> dp;
    int knapsackHelper(int W, int wt[], int val[], int n)
    {
        // Your code here
        if (n == 0 || W == 0)
            return 0;
        if (dp[W][n] != -1)
            return dp[W][n];

        int include = -INF;
        int exclude = knapSack(W, wt, val, n - 1);

        if (wt[n - 1] <= W)
            include = val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1);

        return dp[W][n] = max(include, exclude);
    }

public:
#define INF 0x3f3f3f3f;
    int knapSack(int W, int wt[], int val[], int n)
    {
        dp.resize(w + 1, vector<int>(n + 1, -1));
        return knapsackHelper(W, wt, val, n);
    }
};

// { Driver Code Starts.

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        // inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        // inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        // calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
} // } Driver Code Ends