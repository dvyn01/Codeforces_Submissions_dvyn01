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
    map<ll, ll> m;
    ll a[n];
    f(0, n)     cin>>a[i];
    ll ans = 1;
    multiset<ll> s;
    f(0, n)
    {
        ll x = a[i];
        if(m[x] != 0)
        {
            s.erase(s.find(m[x]));
            m[x]++;
            s.insert(m[x]);
        }
        else m[x] = 1,  s.insert(m[x]);
        if(s.size() == 1)
            ans = max(ans, i+1);
        else
        {
            auto it = s.end();
            --it;
            if(*s.begin() == *it-1 && *s.begin() == *(--it))
                ans = max(ans, i+1);
            it = s.end();   --it;
            if(*it == 1 && *s.begin() == 1)
                ans = max(ans, i+1);
            it = s.begin();
            if(*it == 1 && *(++it) == *s.rbegin())
                ans = max(ans, i+1);
        }
    }
    cout<<ans;

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}