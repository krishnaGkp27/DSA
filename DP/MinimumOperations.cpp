// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
#define INF 1000001
    int n;
    vector<int> dp;

public:
    int findMin(int num)
    {
        if (dp[num] != INF)
            return dp[num];

        if (num % 2 == 0)
            dp[num] = 1 + min(findMin(num / 2), findMin(num - 1));
        else
            dp[num] = 1 + findMin(num - 1);

        return dp[num];
    }
    int minOperation(int n)
    {
        // code here.
        this->n = n;
        dp.resize(n + 1, INF);
        dp[1] = 1;
        findMin(n);
        /*for(int x:dp)
            cout<<x<<" ";
        cout<<endl;*/

        return dp[n];
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
        Solution ob;
        cout << ob.minOperation(n) << endl;
    }
} // } Driver Code Ends