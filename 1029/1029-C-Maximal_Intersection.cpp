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
    ll l[n+1], r[n+1];
    f(1, n+1)   cin>>l[i]>>r[i];
    ll pr[n+2], pl[n+2], sr[n+2], sl[n+2];
    pl[1]=0;    sl[n]=0;  pr[1]=1e18;     sr[n]=1e18;
    f(1, n)
    {
        pl[i+1] = max(l[i], pl[i]);
        pr[i+1] = min(pr[i], r[i]);
    }
    fr(n, 1)
    {
        sl[j-1] = max(sl[j], l[j]);
        sr[j-1] = min(sr[j], r[j]);
    }
    ll ans = 0;
    f(1, n+1)
       ans = max(ans, min(pr[i], sr[i]) - max(pl[i], sl[i]));
 //       cout<<pl[i]<<" "<<pr[i]<<" "<<sl[i]<<" "<<sr[i]<<"\n";
  //      cout<<min(pr[i], sr[i]) - max(pl[i], sl[i])<<"\n";
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

