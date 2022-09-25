// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find the maximum possible amount of money we can win.
// 1. Push this one
// 2. Rearrange max(min()) with base conditions on diagnol (recursively) (case1, case2)
// 3. Tabulate part 2
// 4. Submit on Leetcode using even length optimization (https://leetcode.com/problems/predict-the-winner/)
// 5. Discuss approach using sum
class Solution
{
#include <unordered_map>
public:
    vector<vector<int>> dp;
    int solve(int arr[], int i, int j, bool isPlayer1)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1 && isPlayer1)
            return dp[i][j];

        if (isPlayer1)
            return dp[i][j] = max(arr[i] + solve(arr, i + 1, j, false), arr[j] + solve(arr, i, j - 1, false));

        else
            return min(solve(arr, i + 1, j, true), solve(arr, i, j - 1, true));
    }
    long long maximumAmount(int arr[], int n)
    {
        // Your code here
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return solve(arr, 0, n - 1, true);
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
        cout << ob.maximumAmount(a, n) << endl;
    }
    return 0;
} // } Driver Code Ends