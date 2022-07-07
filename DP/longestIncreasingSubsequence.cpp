// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    int solve(int n, int a[], int pre)
    {
        if (n == 0)
            return 0;

        if (a[n] < a[n - 1])
            return max(1 + solve(n - 1, a, a[n]), solve(n - 1, a, pre));

        else
            return solve(n - 1, a, pre);
    }
    int longestSubsequence(int n, int a[])
    {
        // your code here
        return solve(n - 1, a, a[n - 1]) - 1;
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