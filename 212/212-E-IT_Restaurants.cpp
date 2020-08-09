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
vll adj[5005];
ll n;
bool ps[5050],  ans[5050];

ll dfs(ll x, ll p)
{
    ll k = 0;
    vll v;
    f(0, adj[x].size())
    {
        if(adj[x][i] == p)
            continue;
        ll y = dfs(adj[x][i], x);
        k += y;
        v.pb(y);
    }
    v.pb(n-1-k);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    memset(ps, false, sizeof(ps));
    ps[0] = true;
    f(0, v.size())
    {
        ll k = v[i];
        fr(n, k)
            ps[j] |= ps[j-k];
    }
    f(0, n+1)   ans[i] |= ps[i];
    return k+1;
}

int main()
{
    #ifndef ONLINE_JUDGE
  //     freopen("input.txt", "rt", stdin);
  //     freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, y;
    cin>>n;
    f(0, n-1)       cin>>x>>y,      adj[x].pb(y),       adj[y].pb(x);
    dfs(1, -1);
    vll v;
    f(1, n-1)
        if(ans[i])  v.pb(i);
    cout<<v.size()<<"\n";
    f(0, v.size())  cout<<v[i]<<" "<<n-1-v[i]<<"\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
