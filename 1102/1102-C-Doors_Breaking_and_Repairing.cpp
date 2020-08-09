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

ll fun(ll x, ll y)
{
    if(x % y == 0)
        return x / y;
    return x / y + 1;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x, y;
    cin>>n>>x>>y;
    vll a(n);
    f(0, n)     cin>>a[i];
    if(x > y)
    {
        cout<<n;
        return 0;
    }
    sort(a.begin(), a.end());
    ll k1 = upper_bound(a.begin(), a.end(), x) - a.begin();
    k1--;
    vll p(n);
    f(0, n)     p[i] = fun(a[i], y);
    ll k2 = 0, ans = 0;
    while(k1 > k2)
    {
        ll xx = p[k1];
        k2 += xx;
        ans += xx;
        k1--;
    }
    if(k1 == k2 && a[k1] <= x)
        ans++;
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

