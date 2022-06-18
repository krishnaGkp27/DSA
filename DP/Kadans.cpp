// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
#define INF 0x3f3f3f3f;
    int ans = -INF;
    vector<long long> dp;

public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {
        long long previousSum = 0;
        long long ans = -INF;

        for (int i = 1; i <= n; i++)
        {
            long long inclusion = previousSum + arr[i - 1];
            long long sum = -INF;

            sum = max((int)inclusion, arr[i - 1]);
            previousSum = sum;
            ans = max(ans, sum);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, n;

    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {

        cin >> n; // input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; // inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends