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
    ll a[n];
    vll v1, v2;
    f(0, n)     cin>>a[i];
    sort(a, a+n);
    f(0, n-1)
    {
        if(a[i] != a[i+1])
            v1.pb(a[i]);
        else v2.pb(a[i]);
    }
    if(n > 1 && a[n-1] == a[n-2])
        v1.pb(a[n-1]);
    else v2.pb(a[n-1]);
    bool ok = true;
    if(v2.size())
    {
        f(0, v2.size() - 1)
        {
            if(v2[i] == v2[i+1])
            {
                ok = false;
                break;
            }
        }
    }
    if(!ok)
        cout<<"NO";
    else
    {
        cout<<"YES\n";
        cout<<v1.size()<<"\n";
        f(0, v1.size())     cout<<v1[i]<<" ";   cout<<"\n";
        cout<<v2.size()<<"\n";
        fr(v2.size() - 1, 0)        cout<<v2[j]<<" ";
    }
    

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}