// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k)
    {
        // your code here
        int dp[n + 1][k + 1];

        for (int f = 0; f <= k; f++)
            dp[1][f] = f; // Single egg answer

        for (int egg = 0; egg <= n; egg++)
        {
            dp[egg][0] = 0; // Answer from 0th floor.
            dp[egg][1] = 1; // Answer from 1st floor
        }

        for (int egg = 2; egg <= n; egg++)
        {
            for (int f = 2; f <= k; f++)
            {
                int ans = INT_MAX;

                for (int k = 2; k <= f; k++)
                {
                    int temp = 1 + max(dp[egg - 1][k - 1], dp[egg][f - k]);
                    ans = min(ans, temp);
                }
                dp[egg][f] = ans;
            }
        }
        return dp[n][k];
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
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends