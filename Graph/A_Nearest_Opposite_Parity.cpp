#include <bits/stdc++.h>
#define ll long long int
#define pll pair<ll, ll>
#define pii pair<int, int>
//#define debug

using namespace std;
const int N = 2e5 + 5;

vector<int> G[N];
int arr[N], dist[N], ans[N];
bool vis[N];

int main()
{
#ifndef debug
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int i1 = i - arr[i], i2 = i + arr[i];
        if (i1 >= 0)
        {
            G[i1].push_back(i);
        }
        if (i2 < n)
        {
            G[i2].push_back(i);
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & 1)
        {
            q.push(i);
            vis[i] = 1;
        }
    }
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        for (auto elm : G[a])
        {
            if (!vis[elm])
            {
                q.push(elm);
                vis[elm] = 1;
                dist[elm] = dist[a] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!(arr[i] & 1))
            ans[i] = dist[i];
    }

    fill(dist, dist + n, 0);
    fill(vis, vis + n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!(arr[i] & 1))
        {
            q.push(i);
            vis[i] = 1;
        }
    }
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        for (auto elm : G[a])
        {
            if (!vis[elm])
            {
                q.push(elm);
                vis[elm] = 1;
                dist[elm] = dist[a] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & 1))
            ans[i] = dist[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (ans[i] == 0)
        {
            ans[i]--;
        }
        cout << ans[i] << ' ';
    }
    return 0;
}