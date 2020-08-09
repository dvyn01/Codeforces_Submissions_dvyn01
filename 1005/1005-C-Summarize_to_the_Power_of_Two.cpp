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

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n;
    cin>>n;
    vll a;
    f(0, n){ll x; cin>>x; a.pb(x); }
    if(n==1){cout<<"1"; return 0; }
    sort(a.begin(), a.end());
    map<ll,ll> m;
    ll c=0;
    f(0, n)
    {
      //  if(m[a[i]])
        //    continue;
        ll k=0;
        while((1<<k) < a[i]) k++;
        ll s = 1<<k;
        for(ll j=s; j<=a[n-1]+a[i]; j*=2)
        {
          //  cout<<a[i]<<" "<<j<<"--- "<<"\n";
            ll p = j-a[i];
            ll pos = lower_bound(a.begin(), a.end(), p) - a.begin();
            if(pos!=n && a[pos]==p && (a[pos]!=a[i] || a[pos]==a[i] && a[i+1]==a[i]))
            {
                m[a[i]]++;
                m[p]++;
              //  cout<<a[i]<<" "<<p<<"\n";
            }
        }
        if(!m[a[i]])
            {  c++; }
    }
    cout<<c;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
