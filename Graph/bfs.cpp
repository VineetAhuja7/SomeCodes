#include <bits/stdc++.h>
#define ll long long int
#define pll pair<ll, ll>
#define pii pair<int, int>
//#define debug

using namespace std;
const int N = 1e5 + 5;

int D[N];
bool vis[N];
vector<int> G[N];

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

    queue<int> q;
    int start = 1;
    vis[1] = 1;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto elm : G[node])
        {
            if (!vis[elm])
            {
                vis[elm] = 1;
                q.push(elm);
                D[elm] = D[node] + 1;
            }
        }
    }

    return 0;
}