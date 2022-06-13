// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#define INF 0x3f3f3f3f
class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k)
    {
        // your code here
        int dp[n + 1][k + 1];

        for (int _floor = 0; _floor <= k; _floor++)
            dp[1][_floor] = _floor; // Single egg answer

        for (int egg = 0; egg <= n; egg++)
        {
            dp[egg][0] = 0; // Answer from 0th floor.
            dp[egg][1] = 1; // Answer from 1st floor
        }

        for (int egg = 2; egg <= n; egg++)
        {
            for (int _floor = 2; _floor <= k; _floor++)
            {
                dp[egg][_floor] = INF;
                for (int currentFloor = 2; currentFloor <= _floor; currentFloor++)
                {
                    int eggBreak = 1 + dp[egg - 1][currentFloor - 1];
                    int eggSafe = 1 + dp[egg][_floor - currentFloor];
                    dp[egg][_floor] = min(dp[egg][_floor], max(eggBreak, eggSafe));
                }
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