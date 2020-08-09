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
ll n, m;
vll adj[100050];
set<ll> s;
bool b[100050];

void dfs(ll x)
{
    cout<<x<<" ";
    b[x] = true;
    auto it = s.find(x);
    if(it != s.end())   s.erase(it);
    f(0, adj[x].size())
    {
        if(!b[adj[x][i]])
            s.insert(adj[x][i]);
    }
 //   for(auto it = s.begin(); it != s.end(); it++)
 //   cout<<*it<<" "; cout<<"-----\n";
    if(!s.empty())
        dfs(*s.begin());
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    while(m--)
    {
        ll x, y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
  //  f(1, n+1)       sort(adj[i].begin(), adj[i].end());
    s.insert(1);
    dfs(1);

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
