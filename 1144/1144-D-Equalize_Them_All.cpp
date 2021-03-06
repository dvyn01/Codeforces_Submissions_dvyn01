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

inline ll mul(ll x, ll y, ll m)	{	ll z = 1LL * x * y;		if(z >= m)	z %= m;		return z;	}
inline ll add(ll x, ll y, ll m)	{	ll z = x + y;			if(z >= m)	z %= m;		return z;	}
inline ll sub(ll x, ll y, ll m)	{	ll z = x - y;			if(z < 0)	z += m;		z %= m;		return z;	}

map<ll, ll> m, p;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll a[n];
    f(0, n)     cin>>a[i],      m[a[i]]++,      p[a[i]] = i;
    ll mx = 0, mxe = 0, mxp = 0;
    for(auto it = m.begin(); it != m.end(); it++)
    {
        if(it -> second > mx)
            mx = it -> second,  mxp = p[it -> first],   mxe = it -> first;
    }
    vector< pair< ll, pair<ll, ll> > > ans;
    // cout<<mx<<" "<<mxe<<" "<<mxp<<" ";
    f(mxp+1, n)
    {
        ll x = a[i];
        if(x == mxe)
            continue;
        if(x > mxe)
            ans.pb({2, {i, i-1}}),        a[i] = mxe;
        else ans.pb({1, {i, i-1}}),       a[i] = mxe;
    }
    fr(mxp-1, 0)
    {
        ll x = a[j];
        if(x == mxe)
            continue;
        if(x > mxe)
            ans.pb({2, {j, j+1}}),        a[j] = mxe;
        else ans.pb({1, {j, j+1}}),       a[j] = mxe;
    }
    cout<<ans.size()<<"\n";
    f(0, ans.size())        cout<<ans[i].first<<" "<<ans[i].second.first+1<<" "<<ans[i].second.second+1<<"\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}