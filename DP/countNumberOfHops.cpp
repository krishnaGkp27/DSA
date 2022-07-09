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
        int ways[100000 + 1];
        ways[1] = 1;
        ways[2] = 2;
        ways[3] = 4;
        for (int i = 4; i <= 100001; i++)
            ways[i] = (((ways[i - 1] + ways[i - 2]) % mod) + ways[i - 3]) % mod;

        return ways[n];
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