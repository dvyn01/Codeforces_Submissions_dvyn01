/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
//      #include <ext/pb_ds/assoc_container.hpp>
//      #include <ext/pb_ds/tree_policy.hpp>

//      using namespace __gnu_pbds;
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

    ll n, x;
    cin>>n;
    pair<ll, ll> p[n+1];
    ll m[n+1], m1[n+1];
    f(0, n)     cin>>x,     m[x] = i+1;
    f(0, n)     cin>>x,     m1[x] = i+1;
    f(1, n+1) p[i].first = m[i],  p[i].second = m1[i];
    sort(p+1, p+n+1);
    ll ans = 0;
    vll v(n+5);
    f(0, n+5)     v[i] = 1e18;
    fr(n, 1)
    {
        ll k = p[j].second;
      //  cout<<p[j].first<<" "<<p[j].second<<"\n";
        *lower_bound(v.begin(), v.end(), k) = k;
    }
    f(0, n+3)
    {
        if(v[i] == 1e18)
        {   cout<<i;    return 0;   }
    }

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

