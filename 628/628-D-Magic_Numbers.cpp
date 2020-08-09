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

ll dp[2005][2][2005], m, d, l, a[2005];      // Length, Tight, Modulo   🤑🤑🤑🤑

ll rec(ll i, ll t, ll x)
{
    if(i == l && x == 0)
        return 1;
    if(i == l)
        return 0;
    if(dp[i][t][x] != -1)
        return dp[i][t][x];
    ll k = 9;
    if(t == 1)
        k = a[i];
    ll r = 0;
    if(i & 1)
    {
        if(k < d)
        {
            dp[i][t][x] = 0;
            return 0;
        }
        if(k == d)
            r = add(r, rec(i+1, t, (x * 10 + k) % m), mod);
        else
            r = add(r, rec(i+1, 0, (x * 10 + d) % m), mod);
    }
    else
    {
        ll s = 0;
        if(i == 0)
            s++;
        fi(s, k)
        {
            if(j == d)
                continue;
            r = add(r, rec(i+1, 0, (x * 10 + j) % m), mod);
        }
        if(k != d)
            r = add(r, rec(i+1, t, (x * 10 + k) % m), mod);
    }
    return dp[i][t][x] = r;
}

void nikal(string n)
{
    ll l = 0;
    f(0, n.length())
        a[l++] = n[i] - '0';
}

bool check(string s)
{
    ll sum = 0;
    f(0, s.length())
    {
        if((i & 1) && ((s[i] - '0') != d))
            return false;
        if(!(i & 1) && ((s[i] - '0') == d))
            return false;
        sum = mul(sum, 10, mod);
        sum = add(sum, s[i] - '0', mod);
    }
    if(sum % m != 0)
        return false;
    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m>>d;
    string aa, b;
    cin>>aa>>b;
    l = aa.length();
    nikal(aa);
    ll k1, k2;
    memset(dp, -1, sizeof(dp));
    k1 = rec(0, 1, 0);
    memset(dp, -1, sizeof(dp));
    nikal(b);
    k2 = rec(0, 1, 0);
    ll ans = sub(k2, k1, mod);
    if(check(aa))
        ans = add(ans, 1, mod);
    cout<<ans;

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}