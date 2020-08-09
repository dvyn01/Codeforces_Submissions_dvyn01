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
ll a[105], n, ans, m;

    /*void rec(ll in, ll m, ll p, ll d)
{
    if(in >= n)
        return;
  //  if(dp[m][in][p] != -1)
  //      return dp[m][in][p];
    if(d > ans)
        return;
    ll k = 1e18;
    ll xxx = m - max(0LL, a[in] - p);
    if(xxx <= 0)
    {   ans = min(ans, d);      return; }
    if(a[in] - p > 0)
        rec(in + 1, xxx, p + 1, d);
    rec(in + 1, xxx, 0, d+1);
}   */

bool check(ll d)
{
    ll s = 0;
    f(0, d)
    {
        s += a[i];
        ll j = i + d, c = 1;
        while(j < n)
            s += max(0LL, a[j] - c++),  j += d;
    }
    if(s >= m)
        return true;
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll s = 0;
    cin>>n>>m;
    f(0, n) cin>>a[i],  s += a[i];
    sort(a , a+n);
    reverse(a, a+n);
    ans = 1e18;
    if(s < m)
    {
        cout<<-1;
        return 0;
    }
    ll l = 1, r = 100;
    while(l <= r)
    {
        ll mid = l + r >> 1;
        if(check(mid))
            ans = mid,  r = mid - 1;
        else l = mid + 1;
    }
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

