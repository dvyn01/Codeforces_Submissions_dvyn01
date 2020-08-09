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
ll n, m, a[200050], sz[200050];
vector<pair<ll, pair<ll, ll>>> s;
pll p;

ll root(ll i)
{
    while(i != a[i])
        i = a[i];
    return i;
}

void unionn(ll x, ll y)
{
    if(root(x) == root(y))
        return;
    ll xr = root(x),    yr = root(y),   xs = sz[xr],     ys = sz[yr];
    if(xs >= ys)
    {
        a[yr] = a[xr];
        sz[xr] += ys;
    }
    else
    {
        a[xr] = a[yr];
        sz[yr] += xs;
    }
}

void init(ll n)
{
    f(0, n+1)       a[i] = i,   sz[i] = 1;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, y, w;
    cin>>n>>m;
    init(n);
    f(1, n+1)     cin>>x,     p.pb(mp(x, i));
    sort(p.begin(), p.end());
    f(0, m) cin>>x>>y>>w,       s.pb(mp(w, mp(x, y)));
    ll ans = 0;
    sort(s.begin(), s.end());
    ll cp = 0;
    f(1, p.size())
    {
        x = p[0].first + p[i].first;
        while(cp < s.size() && s[cp].first <= x)
        {
            if(root(s[cp].second.first) == root(s[cp].second.second))
            {   cp++;       continue;   }
            unionn(s[cp].second.first, s[cp].second.second);
            ans += s[cp].first;
            cp++;
        }
        if(root(p[0].second) != root(p[i].second))
            ans += x,   unionn(p[0].second, p[i].second);
    }
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
