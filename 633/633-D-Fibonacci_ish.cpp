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

    ll n, ans = 0;
    cin>>n;
    ll a[n];
    unordered_map<ll, ll> m;
    f(0, n) cin>>a[i],   m[a[i]]++;
    map<ll, map<ll, ll>> m2;
    f(0, n)
    {
        fi(0, n)
        {
            if(i == j || (a[i] == 0 && a[j] == 0))
                continue;
            if(m2[a[i]][a[j]] != 0)
                continue;
            m2[a[i]][a[j]] = 1;
            unordered_map<ll, ll> m1;
            ll k1 = a[i], k2 = a[j], c = 2;
            m1[a[i]]++; m1[a[j]]++;
            while(c < n)
            {
                if(m1[k1 + k2] < m[k1 + k2])
                {   
                    m1[k1 + k2]++;
                    ll k3 = k1 + k2;
                    k1 = k2;
                    k2 = k3;
                    c++;
                }
                else break;
            }
            ans = max(ans, c);
        }
    }
    ans = max(ans, m[0]);
    cout<<ans;

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}