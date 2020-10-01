#include <bits/stdc++.h>
#define ll long long int
#define pll pair<ll, ll>
#define pii pair<int, int>
//#define debug

using namespace std;
const int N = 1e5 + 5;

vector<int> G[N];
bool vis[N];

void dfs(int a)
{
    for (auto elm : G[a])
    {
        if (!vis[elm])
        {
            vis[elm] = 1;
            dfs(elm);
        }
    }
}

int main()
{
#ifndef debug
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    return 0;
}
