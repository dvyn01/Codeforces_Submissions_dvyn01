/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
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
    ll a[n+1];
    f(1, n+1) cin>>a[i];
    ll s, f;
    cin>>s>>f;
    ll me = 0, mi=0;
    ll c[n+2] = {0};
    f(1, n+1)
    {
        ll k1 = i-s+1, k2 = i-f+2;
        if(k1 <= 0)
            k1 += n;
        if(k2 <= 0)
            k2 += n;
        if(k2 <= k1)
        {
            c[k2] += a[i];
            c[k1+1] -= a[i];
        }
        else
        {
            c[k2] += a[i];
            c[1] += a[i];
            c[k1+1] -= a[i];
        }
     //   cout<<i<<" "<<k1<<" "<<k2<<" "<<a[i]<<"\n";
    }
    f(1, n+1)
    {
        c[i] = c[i-1] + c[i];
      //  cout<<c[i]<<" ";
        if(c[i] >= me)
        {
            me = c[i];
            mi = i;
        }
    }
 //   cout<<mi<<endl;
    ll ans = n;
    fr(mi-2, 1) ans--;
    if(mi != 1)
        cout<<ans;
    else cout<<mi;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

