// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this function*/

class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        // Your code here
        int maxSubArrayCount = 0;
        int sum = 0;
        unordered_map<int, int> ump;

        for (int i = 0; i < n; i++)
        {
            sum += A[i];

            if (ump.find(sum) != ump.end())
                maxSubArrayCount = max(maxSubArrayCount, i - ump[sum]);
            else
                ump[sum] = i;

            if (sum == 0)
                maxSubArrayCount = max(maxSubArrayCount, i + 1);
        }
        return maxSubArrayCount;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends