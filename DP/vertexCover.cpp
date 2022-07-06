#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
void dfs(int u, vector<int> adj[], bool visited[])
{
    visited[u] = true;
    dp[u][0] = 0;
    dp[u][1] = 1;

    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v, adj, visited);
            dp[u][0] += dp[v][1];
            dp[u][1] += min(dp[v][0], dp[v][1]);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];

    int input = n - 1;

    while (input--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool visited[n + 1] = {0};
    dp.resize(n + 1, vector<int>(2, -1));
    dfs(1, adj, visited);
    cout << min(dp[n][0], dp[n][1]);
}