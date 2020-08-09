/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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
typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
vll adj[100005], adj2[100005], v;
stack<ll> s;
ll n, a[100005];
bool b[100005];

void dusra_list_bnao()
{
    f(1, n+1)
        fi(0, adj[i].size())
            adj2[adj[i][j]].pb(i);
}

void dfs(ll x)
{
    b[x] = true;
    f(0, adj[x].size())
        if(!b[adj[x][i]])
            dfs(adj[x][i]);
    s.push(x);
}

void dusra_dfs(ll x)
{
    v.pb(a[x]);
    b[x] = true;
    f(0, adj2[x].size())
        if(!b[adj2[x][i]])
            dusra_dfs(adj2[x][i]);
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    f(1, n+1)   cin>>a[i];
    memset(b, false, sizeof(b));
    ll m, x, y;
    cin>>m;
    while(m--)
        cin>>x>>y,      adj[x].pb(y);
    f(1, n+1)
        if(!b[i])
            dfs(i);
    vector<vll> scc;
    memset(b, false, sizeof(b));
    dusra_list_bnao();
    while(!s.empty())
    {
        if(b[s.top()])
        {
            s.pop();
            continue;
        }
        v.clear();
        dusra_dfs(s.top());
        s.pop();
        sort(v.begin(), v.end());
        scc.pb(v);
    }
    ll paisa = 0,   ways = 1;
    f(0, scc.size())
    {
        paisa += scc[i][0];
        ll k = 1;
        while(k < scc[i].size() && scc[i][k] == scc[i][k-1])
            k++;
        ways = (ways * k) % mod;
    }
    cout<<paisa<<" "<<ways;


    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

