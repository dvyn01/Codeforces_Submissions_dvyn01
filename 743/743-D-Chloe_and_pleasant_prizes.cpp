/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>

/*    #include <ext/pb_ds/assoc_container.hpp>
      #include <ext/pb_ds/tree_policy.hpp>

      using namespace __gnu_pbds;       */

using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a,b) for(ll i = a; i < b; i++)
#define fr(a,b) for(ll j = a; j >= b; j--)
#define fi(a,b) for(ll j = a; j < b; j++)
#define fii(a,b) for(ll k = a; k < b; k++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll,ll>
#define vll vector<ll>
#define pll vector< pair<ll,ll> >
#define ld long double
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll a[200050], ans, s[2000050];
vll adj[200050];
vll v;

ll kill(ll x, ll p)
{
	ll k = a[x];
	f(0, adj[x].size())
	{
		if(adj[x][i] == p)
			continue;
		k += kill(adj[x][i], x);
	}
	s[x] = k;
	return k;
}

ll dfs(ll x, ll p)
{
	vll v;
	f(0, adj[x].size())
	{
		if(adj[x][i] == p)
			continue;
		ll c = dfs(adj[x][i], x);
		v.pb(c);
	}
	sort(v.begin(), v.end());
	if(v.size() > 1)
		ans = max(ans, v[v.size() - 1] + v[v.size() - 2]);
//	cout<<x<<" -------> ";	f(0, v.size())	cout<<v[i]<<" ";	cout<<"\n";
	v.pb(s[x]);
	sort(v.begin(), v.end());
	return v[v.size() - 1];
}


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
       freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, y, n;
    cin>>n;
    ans = -1e18;
    f(1, n+1)		cin>>a[i];
    f(0, n-1)		cin>>x>>y,		adj[x].pb(y),		adj[y].pb(x);
    kill(1, -1);
    dfs(1, -1);
    if(ans == -1e18)
    	cout<<"Impossible";
    else cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
