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

ll dp[505][505];

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
    string a;
    cin>>a;
    f(0, n)     dp[i][i] = 1;
    f(0, n-1)   {   if(a[i] == a[i+1])      dp[i][i+1] = 1;     else dp[i][i+1] = 2;    }
    fii(3, n+1)
    {
        f(0, n-k+1)
        {
            ll j = i + k - 1;
            dp[i][j] = k;
            dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
            if(a[i] == a[j])
                dp[i][j] = min(dp[i][j], (dp[i+1][j-1] + 1, min(dp[i+1][j], dp[i][j-1]) + 1));
            for(ll r = i+1; r <= j; r++)
                if(a[i] == a[r])
                    dp[i][j] = min(dp[i][j], dp[i+1][r-1] + dp[r][j]);
        }
    }
    cout<<dp[0][n-1];

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}