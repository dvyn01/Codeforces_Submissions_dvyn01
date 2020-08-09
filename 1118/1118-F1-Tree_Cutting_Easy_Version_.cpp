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
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll,ll>
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll n, ans, a[300050], oc, tc;
vll adj[300050];

pair<ll, ll> dfs(ll x, ll pr)
{
    pair<ll, ll> p;
    p.first = 0;    p.second = 0;
    f(0, adj[x].size())
    {
        if(adj[x][i] != pr)
        {
            pair<ll, ll> q = dfs(adj[x][i], x);
            p.first += q.first;
            p.second += q.second;
        }
    }
    if(a[x] == 1)
        p.first++;
    else if(a[x] == 2)
        p.second++;
    if(p.first == 0 && p.second == 0)
    {
        if(tc == 0 || oc == 0)
            ans++;
    }
    else if(p.first == 0 && p.second != 0)
    {
        ll k1 = oc - p.first,   k2 = tc - p.second;
        if(k1 == 0 || k2 == 0)
            ans++;
    }
    else if(p.first != 0 && p.second == 0)
    {
        ll k1 = oc - p.first,   k2 = tc - p.second;
        if(k1 == 0 || k2 == 0)
            ans++;
    }
    return p;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, y;
    cin>>n;
    f(1, n+1){  cin>>a[i];      if(a[i] == 1) oc++; else if(a[i] == 2)  tc++;   }
    f(0, n-1)   cin>>x>>y,      adj[x].pb(y),       adj[y].pb(x);
    dfs(1, -1);
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

