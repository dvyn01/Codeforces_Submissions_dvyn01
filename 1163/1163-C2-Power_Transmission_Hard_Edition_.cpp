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

pll p;
map<ll, map<ll, ll>> m;

map<ll, map<ll, map<ll, ll>>> m1;
ll ppp;

void fckk(ll i, ll j)
{
    ll k1 = p[j].second - p[i].second,    k2 = p[j].first - p[i].first;
    ll g = __gcd(abs(k1), abs(k2));
    k1 /= g,    k2 /= g;
    if((k1 > 0 && k2 < 0) || (k1 < 0 && k2 > 0))
    {
        k1 = abs(k1);
        k1 *= -1;
        k2 = abs(k2);
    }
    else
    {
        k1 = abs(k1);
        k2 = abs(k2);
    }
    if(k2 == 0)
        k1 = 1;
    else if(k1 == 0)
        k2 = 1;
    // cout<<i<<" "<<j<<" "<<k1<<" "<<k2<<"\n";
    if(m1[i][k1][k2] != 0)
    {   ppp++;  m1[j][k1][k2] = 1; return; }
    if(m1[j][k1][k2] != 0)
    {   ppp++;  m1[i][k1][k2] = 1; return; }
    // cout<<i<<" "<<j<<" "<<k1<<" "<<k2<<"\n";
    m1[i][k1][k2] = 1;
    m1[j][k1][k2] = 1;
    m[k1][k2]++;
}

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
    p.resize(n);
    f(0, n)   cin>>p[i].first>>p[i].second;
    sort(p.begin(), p.end());
    f(0, n)
        fi(i+1, n)    fckk(i, j);
    ll c = 0;
    for(auto it = m.begin(); it != m.end(); it++)
    {
        for(auto it1 = it->second.begin(); it1 != it->second.end(); it1++)
        {
            ll kk = it1 -> second;
            // cout<<kk<<" ";
            c += kk * (kk - 1) / 2;
        }
    }
    // cout<<c<<" ";
    ll ans = n * (n - 1) / 2;
    ans -= ppp;
    // cout<<ans<< " "<<ppp<<" ";
    ans = ans * (ans - 1) / 2 - c;
    cout<<ans;

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}