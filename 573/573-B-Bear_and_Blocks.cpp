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
    ll a[n];
    f(0, n) cin>>a[i];
    ll b[n], c[n];
    f(0, n) c[i]=1000000000;
    c[0]=1; c[n-1]=1;
    b[0]=0; b[n-1]=0;
    f(1, n-1)
    {
        b[i] = min(a[i-1], min(a[i+1], a[i]-1));
        if(b[i] == a[i]-1)
            c[i]=a[i];
    }
    f(1, n-1)
    {
        if(b[i-1]==0)
        {
            ll y=2;
            c[i] = min(c[i], y);
            continue;
        }
        c[i] = min(c[i], c[i-1]+1);
    }
   // f(0, n) cout<<c[i]<<" "; cout<<"\n";
    fr(n-2, 1)
    {
       if(b[j+1]==0)
       {
           ll y=2;
           c[j] = min(c[j], y);
           continue;
       }
       c[j] = min(c[j], c[j+1]+1);
    }
  //  f(0, n) cout<<c[i]<<" "; cout<<"\n";
    ll ans=0;
    f(0, n) ans=max(ans, c[i]);
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

