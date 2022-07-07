// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
#define mod 1000000007
public:
    // Function to count the number of ways in which frog can reach the top.
    long long countJumps(int jumps, int arr[], int n)
    {

        if (jumps == 0)
            return 1;

        if (n == 0)
            return 0;

        if (jumps - arr[n - 1] >= 0)
            return countJumps(jumps - arr[n - 1], arr, n) + countJumps(jumps, arr, n - 1);

        else
            return countJumps(jumps, arr, n - 1);
    }
    long long countWays(int n)
    {

        // your code here
        int x = 1;
        int y = 2;
        int z = 3;
        int ans[n + 1] = {0};
        ans[1] = 1;
        ans[2] = 1;
        ans[3] = 1;

        for (int i = 1; i <= n; i++)
        {
            long long val1 = 0;
            long long val2 = 0;
            long long val3 = 0;

            if (i - x >= 0)
                val1 = ans[i - x];

            if (i - y >= 0)
                val2 = ans[i - y];

            if (i - z >= 0)
                val3 = ans[i - z];

            ans[i] += (val1 + val2 + val3) % mod;
        }
        return ans[n] % mod;
    }
};

// { Driver Code Starts.
int main()
{
    // taking testcases
    int t;
    cin >> t;

    while (t--)
    {
        // taking number of steps in stair
        int n;
        cin >> n;
        Solution ob;
        // calling function countWays()
        cout << ob.countWays(n) << endl;
    }

    return 0;
}
// } Driver Code Ends