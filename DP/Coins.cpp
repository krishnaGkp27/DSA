#include <iostream>
#include <map> //Do we need a map? Do we need to maintain order?
using namespace std;
map<int, long long> dp; // Do we need long long? How can you guarantee?

long long f(int n)
{
    if (n <= 4)
        return n; // O(1)

    if (dp.find(n) != dp.end()) // O(log x),  where x is the size of the map (number of keys in map)
        return dp[n];

    long long case1 = f(n / 2) + f(n / 3) + f(n / 4); // O(log(2)(n/2) + log(2)(n/3) + log(2)(n/4)) = O(log(2)(n/2)) = O(log n)
    // log(n/2) = log((1/2) * n) =log(1/2) + log(n) = log(n) - 1
    long long case2 = n;

    // So O(1 + log x + log n) <= O(log n + log n + log n) <= O(3logn) ~ O(log n)
    return dp[n] = max(case1, case2); // = O(log x)
    // O(1 + log x + log n + log x) <= O(log n + log n + log n + log n) <= O(log n)
}
int main()
{
    // your code goes here
    int coins;
    // t number of test cases
    while (cin >> coins) // t * O(log n + log x) =  O(tlog n + tlog x) <= O(t log n)
        cout << f(coins) << '\n';

    return 0;
}
