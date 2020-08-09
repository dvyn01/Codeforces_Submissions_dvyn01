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
#define f(a,b) for(ll i = a; i < b; i++)
#define fr(a,b) for(ll j = a; j >= b; j--)
#define fi(a,b) for(ll j = a; j < b; j++)
#define fii(a,b) for(ll k = a; k < b; k++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll,ll>
#define vll vector<ll>
#define pll vector< pair<ll,ll> >
#define ld long double
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   //    freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin>>n>>k;
    ll a[n+1], mn = 1e18, mni = -1,	s[n+1], mnc = 0, mx = -1e18;
    ll x[n+1];  memset(x, 0, sizeof(x));
    memset(s, 0, sizeof(s));
    f(0, n)		{	cin>>a[i];	if(a[i] < mn)	mn = a[i],	mni = i, mnc = 1;   else if(a[i] == mn) mnc++;	}
    a[n] = 0;
    vll ans;
    pll p;
    f(0, k)
    {
    	ll l, r;
    	cin>>l>>r;
    	l--;	r--;
   // 	x[l]++;     x[r+1]--;
    	p.pb({l, r});
    }
 /*   f(1, n+1)   x[i] += x[i-1];
    ll ci = 0, cm = 0;
    f(0, n)
    {
        if(a[i] != mn)
            continue;
        if(x[i] > cm)
        {
            cm = x[i];
            ci = i;
        }
    }
    f(0, k)
    {
        ll l = p[i].first,  r = p[i].second;
        if(l <= ci && ci <= r)
            s[l]--, s[r+1]++, ans.pb(i+1);
    }       */
    ll mxx = -1e18;
    f(0, n)
    {
        vll v;
        mn = 1e18, mx = -1e18;
        memset(s, 0, sizeof(s));
        ll b[n+1];  memset(b, 0, sizeof(b));
        fi(0, k)
        {
            ll l = p[j].first,  r = p[j].second;
            if(l <= i && i <= r)
                s[l]--, s[r+1]++, v.pb(j+1);
        }
        f(1, n+1)   s[i] += s[i-1];
        f(0, n)     b[i] = a[i] + s[i];
        f(0, n)
        {
            if(b[i] > mx)	mx = b[i];
            if(b[i] < mn)	mn = b[i];
        }
        if(mx - mn > mxx)
        {
            mxx = mx - mn;
            ans.clear();
            ans = v;
        }
    }
    cout<<mxx<<"\n";
    cout<<ans.size()<<"\n";
    f(0, ans.size())
    	cout<<ans[i]<<" ";


    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

