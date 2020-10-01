#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef pair<long,long> pl;
typedef pair<ll,ll> pll;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<vl> vvl;
typedef vector<vll> vvll;
 
#define FOR(i,a,b) for(long long i=a;i<b;++i)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define tc(t) while(t--)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007

const int N = 1e5 + 5;

int D[N];
bool vis[N];
vector<int> G(N);
int main() 
{ 
	vector<int> ans(N);
	int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin>>G[i];
    }
    for (int i=1; i <= n; i++)
    {
    	memset(vis, false, sizeof vis);
		vis[i]=true;
		int p= G[i];
		while(vis[p]==false){
			vis[p]=true;
			p=G[p];
		}
		ans[i]=p;	      
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
    
	return 0;
}	