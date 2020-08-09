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
ll n, k;
ll a[200050];
string s;

/*ll rec(ll in, ll cc, char c)
{
    if(in >= n)
        return 0;
    if(cc > k)
        return -1e18;
    if(dp1[in] != -1 && c != s[in])
        return dp1[in];
 //   if(dp[in][cc] && c == s[in])
 //       return dp[in][cc];
    ll kk = 0, cs = 0;
    if(s[in] != c)
        return a[in] + rec(in + 1, 1, s[in]);
    char ccc = s[in];
    f(in, n)
    {
        if(s[in] != ccc || (i - in + 1) > k)
            break;
        kk = max(kk, cs + rec(i+2, '#', 0));
        cs += a[i];
    }
    return dp1[in] = kk;
}   */

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    f(0, n)     cin>>a[i];
  //  memset(dp1, -1, sizeof(dp1));
    cin>>s;
    ll ans = 0;
    f(0, s.length())
    {
        char c = s[i];
        if(i != n-1 && s[i] != s[i+1])
        {
            ans += a[i];
            continue;
        }
        ll j = i;
        multiset<ll> ss;
        ll cs = 0;
        while(j < n && s[j] == c)
        {
            if(ss.size() < k)
            {
                cs += a[j];
                ss.insert(a[j]);
                j++;
                continue;
            }
            else
            {
                if(*ss.begin() > a[j])
                {
                    j++;
                    continue;
                }
                cs -= *ss.begin();
                ss.erase(ss.begin());
                ss.insert(a[j]);
                cs += a[j];
                j++;
            }
        }
        ans += cs;
        i = j - 1;
    }
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

