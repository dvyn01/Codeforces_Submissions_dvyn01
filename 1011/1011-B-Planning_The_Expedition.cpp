//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)

bool compare(ll a, ll b)
{
    return a>b;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
 //   ios_base::sync_with_stdio(false);
 //   cin.tie(NULL);
 //   cout.tie(0);

    ll n, m;
    cin>>n>>m;
    unordered_map<ll,ll> mm;
    f(0, m) {ll x; cin>>x; mm[x]++;}
    ll ans = 0;
    unordered_map<ll,ll> :: iterator it;
    vll v;
    for(it=mm.begin(); it!=mm.end(); it++)
        v.pb(it->second);
    sort(v.begin(), v.end());
  //  f(0, v.size()) cout<<v[i]<<"\n";
    ll l=1, r=1000000000;
    while(l<=r)
    {
        ll mid = (l+r)/2;
     //   cout<<mid<<" ";
        ll x=0;
        f(0, v.size())
        {
            ll ss = v[i]/mid;
            x += ss;
        }
      //  cout<<x<<"\n";
        if(x >= n)
        {
            ans = max(ans, mid);
            l = mid+1;
        }
        else r = mid-1;
    }
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

