#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
#define INF INT_MAX;
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        if (n == 0 || W == 0)
            return 0;

        int include = -INF;
        int exclude = knapSack(W, wt, val, n - 1);

        if (wt[n - 1] <= W)
            include = val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1);

        return max(include, exclude);
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