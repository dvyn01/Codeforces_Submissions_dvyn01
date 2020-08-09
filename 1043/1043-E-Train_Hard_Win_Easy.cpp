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


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin>>n>>m;
    pair<ll, ll> p[n+1];
    pll wow;
    ll rrs = 0, cls = 0;
    ll ans[n+1];        memset(ans, 0, sizeof(ans));
    f(1, n+1)     {   cin>>p[i].first>>p[i].second;       wow.pb(mp(p[i].first - p[i].second, i));      rrs += p[i].second; }
    sort(wow.begin(), wow.end());
    f(0, wow.size())
    {
        ll pos = wow[i].second;
        rrs -= p[pos].second;
        ans[pos] += cls;
        ans[pos] += i * p[pos].second;
        ans[pos] += (n-i-1) * p[pos].first;
        ans[pos] += rrs;
        cls += p[pos].first;
    }
    while(m--)
    {
        ll x, y;
        cin>>x>>y;
        ll c = min(p[x].first + p[y].second,    p[x].second + p[y].first);
        ans[x] -= c;
        ans[y] -= c;
    }
    f(1, n+1)       cout<<ans[i]<<" ";

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

