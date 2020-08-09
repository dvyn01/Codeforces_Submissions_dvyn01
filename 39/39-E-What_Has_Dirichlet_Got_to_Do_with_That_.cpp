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

ll dp[100][10050], n;

bool check_kr(ll items, ll boxes)
{
    ll r = 1;
    while(items--)
    {
        r *= boxes;
        if(r >= n)
            return true;
    }
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll items, boxes;
    cin>>boxes>>items>>n;
    if(check_kr(items, boxes) || (check_kr(items+1, boxes) && check_kr(items, boxes+1)))
    {
        cout<<"Stas";
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    for(ll j = 10000; j >= 0; j--)
    {
            dp[99][j] = 1;
        
    }
    for(ll i = 98; i >= 0; i--)
    {
        for(ll j = 10000; j >= 0; j--)
        {
            if(check_kr(i, j))
                dp[i][j] = 1;
            else
            {
                if(dp[i][j+1] == 0 || dp[i+1][j] == 0)
                    dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }
    }
    // f(1, 6)
    // {
    //     fi(1, 10)        cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
    if(boxes == 1)
    {
        ll x = 0;
        if(check_kr(items, 2))
        {
            cout<<"Missing";
            return 0;
        }
        while(dp[items][2] == 1 && items < n && items < 31)
            items++,    x ^= 1;
        if(items == n || items == 31)
            cout<<"Missing";
        else if(x & 1)  cout<<"Stas";
        else cout<<"Masha";
        return 0;       
    }
    if(items == 1 && check_kr(2, boxes))
    {
        ll x = n - boxes;
        if(x & 1)
            cout<<"Stas";
        else cout<<"Masha";
        return 0;
    }
    if(dp[items][boxes])
        cout<<"Masha";
    else cout<<"Stas";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}