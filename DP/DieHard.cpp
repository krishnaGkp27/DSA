#include <cstring>
#include <iostream>

using namespace std;
#define INF 0x3f3f3f3f
const int air = 0;
const int water = 1;
const int fire = 2;
int dp[1001][1001][3];

int die(int h, int a, int state)
{
    if (h <= 0 || a <= 0)
        return 0;

    int temp = -INF;

    if (dp[h][a][state] != -1)
        return dp[h][a][state];

    if (state == air) // T(h,a) = 1 + max(T(h-20,a+5),T(h-5,a-10)) = O(max(h/20), max(h/5, a/10))
        temp = 1 + max(die(h - 20, a + 5, fire), die(h - 5, a - 10, water));
    if (state == water)
        temp = 1 + max(die(h - 20, a + 5, fire), die(h + 3, a + 2, air));
    if (state == fire)
        temp = 1 + max(die(h + 3, a + 2, air), die(h - 5, a - 10, water));

    return dp[h][a][state] = temp;
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
        cout << die(h, a, water) - 1 << '\n';
    }
    return 0;
}