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
typedef tree<ll ,null_type,greater_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

inline ll mul(ll x, ll y, ll m)	{	ll z = 1LL * x * y;		if(z >= m)	z %= m;		return z;	}
inline ll add(ll x, ll y, ll m)	{	ll z = x + y;			if(z >= m)	z %= m;		return z;	}
inline ll sub(ll x, ll y, ll m)	{	ll z = x - y;			if(z < 0)	z += m;		z %= m;		return z;	}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin>>n>>k;
    pll p;
    p.resize(n);
    f(0, n)     cin>>p[i].second>>p[i].first;
    sort(p.begin(), p.end());
    multiset<ll> s;
    ll ans = 0, cs = 0;
    if(k == 1)
    {
        f(0, n)     ans = max(ans, p[i].first * p[i].second);
        cout<<ans;
        return 0;
    }
    fr(n-1, 0)
    {
        if(s.size() < k - 1)
        {
            s.insert(p[j].second);
            cs += p[j].second;
            ans = max(ans, cs * p[j].first);
        }
        else
        {
            ans = max(ans, p[j].first * (cs + p[j].second));
            if(p[j].second > *s.begin())
            {
                cs -= *s.begin();
                auto it = s.begin();
                s.erase(it);
                cs += p[j].second;
                s.insert(p[j].second);
            }
        }
    }
    cout<<ans;

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}