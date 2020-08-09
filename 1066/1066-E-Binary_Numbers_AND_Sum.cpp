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
#define mod 998244353
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

ll powmod(ll x, ll y)
{
    x %= mod;
    ll r = 1;
    while(y)
    {
        if(y & 1)
            r = (r * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return r;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin>>n>>m;
    string s1, s2;
    cin>>s1>>s2;
    ll b[m];
    b[0] = 1;
    f(1, m)
        if(s2[i] == '1')
            b[i] = b[i-1] + 1;
        else b[i] = b[i-1];
    ll j, ans = 0, k = 0;
    if(n >= m)      j = 0;
    else j = m - n;
    for(ll i = max(n-m, k); i< n; i++, j++)
    {
        if(s1[i] == '0')
            continue;
        ans  = (ans + (powmod(2, n - i - 1) * b[j] % mod))% mod;
    }
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
