// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    int arr[11] = {0, 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    vector<int> ans;

public:
    void minCoinCount(int N, int n)
    {
        if (N == 0 || n == 0)
            return;

        if (N - arr[n] >= 0)
        {
            ans.push_back(arr[n]);
            minCoinCount(N - arr[n], n);
        }
        else
            minCoinCount(N, n - 1);
    }
    vector<int> minPartition(int N)
    {
        // code here
        ans.clear();
        minCoinCount(N, 10);
        return ans;
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

        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for (auto u : numbers)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends