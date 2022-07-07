// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    vector<vector<int>> dp;

public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];

        if (sum % 2 != 0)
            return 0;

        int halfSum = sum / 2;
        bool dp[N + 1][halfSum + 1];

        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= halfSum; j++)
            {
                if (j == 0)
                    dp[i][j] = true;

                else if (i == 0)
                    dp[i][j] = false;

                else
                {

                    bool include = false;
                    bool exclude = false;

                    if (j - arr[i - 1] >= 0)
                        include = dp[i - 1][j - arr[i - 1]];

                    exclude = dp[i - 1][j];

                    dp[i][j] = include || exclude;
                }
            }
        }
        return dp[N][halfSum];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
} // } Driver Code Ends