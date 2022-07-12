#include <cstring>
#include <iostream>
#define INF 0x3f3f3f3f

using namespace std;

int dp[1000 + 1][1000 + 1][2];

int die(int h, int a, bool inAir)
{
    if (h <= 0 || a <= 0)
        return -1;

    if (dp[h][a][inAir] != -1)
        return dp[h][a][inAir];

    if (inAir)
    {
        int fire = 1 + die(h - 20, a + 5, false);
        int water = 1 + die(h - 5, a - 10, false);
        return dp[h][a][inAir] = max(fire, water);
    }
    else
    {
        int air = 1 + die(h + 3, a + 2, true);
        return dp[h][a][inAir] = air;
    }
}
int main()
{
    int t;
    memset(dp, -1, sizeof(dp));
    cin >> t;
    while (t--)
    {
        int h, a;
        cin >> h >> a;
        cout << die(h, a, false) << '\n'; // 1 + 1 + 1 +...+ 0 + -1
    }
    return 0;
}