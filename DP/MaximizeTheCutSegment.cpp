// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
private:
    const int INF = 0x3f3f3f3f;
    vector<vector<int>> dp;
    bool flag;

public:
    // Function to find the maximum number of cuts.
    int cutMax(int len, int cut[], int n)
    {
        if (len == 0)
        {
            flag = true;
            return 0;
        }

        if (n == 0)
            return -INF;

        if (dp[n][len] != -1)
            return dp[n][len];

        int inc = -INF;
        if (len - cut[n - 1] >= 0)
            inc = 1 + cutMax(len - cut[n - 1], cut, n);
        int exc = cutMax(len, cut, n - 1);

        return dp[n][len] = max(inc, exc);
    }

    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Your code here
        int ans = 0;
        int aLimit = n / x;
        int bLimit = n / y;
        int cLimit = n / z;
        for (int a = 0; a <= aLimit; a++)
        {
            for (int b = 0; b <= bLimit; b++)
            {
                int temp = n - x * a - y * b;
                if (temp >= 0 && temp % z == 0)
                {
                    int c = temp / z;
                    if (c <= cLimit && a * x + b * y + c * z > n)
                        break;
                    ans = max(ans, (a + b + c));
                }
            }
        }
        return ans;
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
        // taking length of line segment
        int n;
        cin >> n;

        // taking types of segments
        int x, y, z;
        cin >> x >> y >> z;
        Solution obj;
        // calling function maximizeTheCuts()
        cout << obj.maximizeTheCuts(n, x, y, z) << endl;
    }

    return 0;
} // } Driver Code Ends