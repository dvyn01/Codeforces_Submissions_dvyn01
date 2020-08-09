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


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll a[n], b[n], c[n];
    memset(b, -1, sizeof(b));
    f(0, n)     c[i] = n;
    f(0, n)     cin>>a[i];
    stack< pair<ll, ll> > s;
    f(0, n)
    {
        if(s.empty())
        {
            s.push({a[i], i});
            continue;
        }
        while(!s.empty() && s.top().first >= a[i])
            s.pop();
        if(!s.empty())
            b[i] = s.top().second;
        s.push({a[i], i});
    }
    while(!s.empty())       s.pop();
    fr(n-1, 0)
    {
        if(s.empty())
        {
            s.push({a[j], j});
            continue;
        }
        while(!s.empty() && s.top().first >= a[j])
            s.pop();
        if(!s.empty())
            c[j] = s.top().second;
        s.push({a[j], j});
    }
    pll p;
    f(0, n)     p.pb({a[i], c[i] - b[i] - 1});
    sort(p.begin(), p.end());
    ll ans[n+1];
    ll cp = n-1;
    f(1, n+1)
    {
        while(p[cp].second < i)
            p.pop_back(),   cp--;
        ans[i] = p[cp].first;
    }
    f(1, n+1)       cout<<ans[i]<<" ";

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

