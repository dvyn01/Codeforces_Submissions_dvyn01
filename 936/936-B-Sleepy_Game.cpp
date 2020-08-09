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
vll adj[100050], v;
bool draw,   dp[300050][2],     dp1[300050][2];
ll n, m, s;

bool dfs(ll x, ll c)
{
    dp[x][c] = true;
    if(dp1[x][c])   return false;
    dp1[x][c] = true;
    if(adj[x].size() == 0 && c == 1)
    {   dp[x][c] = false;   return true;    }
    if(adj[x].size() == 0 && c == 0)
    {   dp[x][c] = false;   return false;   }
    bool k = false;
    f(0, adj[x].size())
    {
        if(dp[adj[x][i]][c^1])
        {   draw = true;     continue;   }
        k |= dfs(adj[x][i], c^1);
        if(k)
        {
            v.pb(adj[x][i]);
            return true;
        }
    }
    dp[x][c] = false;
    return k;
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
    cin>>n>>m;
    f(1, n+1)
    {
        cin>>x;
        while(x--)
            cin>>y,     adj[i].pb(y);
    }
    cin>>s;
    bool ans = dfs(s, 0);
    if(ans)
    {
        cout<<"Win\n";
        cout<<s<<" ";
        fr(v.size() - 1, 0)     cout<<v[j]<<" ";
    }
    else if(draw)
        cout<<"Draw";
    else cout<<"Lose";

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

