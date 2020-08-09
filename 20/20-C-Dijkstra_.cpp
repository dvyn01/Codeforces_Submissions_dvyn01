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
pll adj[1000050];
ll d[1000050], n, pr[1000050];
bool b[1000050];

void dij()
{
    priority_queue<ll, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push(mp(0, 1));
    f(2, n+1)   d[i] = 1e18;
    b[1] = true;
    while(!pq.empty())
    {
        pair<ll, ll> p = pq.top();
        pq.pop();
        ll x = p.second, w = p.first;
        b[x] = true;
        f(0, adj[x].size())
        {
            if(!b[adj[x][i].first])
            {
                ll k = d[adj[x][i].first];
                if(adj[x][i].second + w < k)
                {
                    d[adj[x][i].first] = adj[x][i].second + w;
                    pq.push(mp(d[adj[x][i].first], adj[x][i].first));
                    pr[adj[x][i].first] = x;
                }
            }
        }
    }
}

void kill(ll i)
{
    if(i != 1)  kill(pr[i]);
    cout<<i<<" ";
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m, x, y, w;
    cin>>n>>m;
    f(0, m)     cin>>x>>y>>w,       adj[x].pb(mp(y, w)),        adj[y].pb(mp(x, w));
    dij();
    if(d[n] >= 1e18)
    {
        cout<<-1;
        return 0;
    }
    kill(n);

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
