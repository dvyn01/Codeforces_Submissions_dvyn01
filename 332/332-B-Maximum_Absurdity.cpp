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

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll a[1000000] = {0}, s[1000000] = {0}, b[1000000]={0};
    ll n, k;
    cin>>n>>k;
    f(1, n+1)
    { cin>>a[i]; s[i] = s[i-1]+a[i]; }
    f(1, n+1)   { if(i+k-1<=n) b[i] = s[i+k-1]-s[i-1];  }
  // f(1, n+1) cout<<b[i]<<" ";
    ll p = n;
    while(b[p]==0)
        p--;
    ll m=0, li=p-k, ri=p,ls=b[li], ts=b[li]+b[li+k],mv=b[li+k], mi=p;
  //  f(1, n+1) cout<<i<<" "<<b[i]<<"\n";
  //  cout<<endl;
    for(ll j=li-1; j>0; j--)
    {
        mv = max(mv, b[j+k]);
        if(mv == b[j+k]) mi = j+k;
        ll tt = b[j] + mv;
       // cout<<j<<" "<<ri<<"\n";
    //    cout<<tt<<" ";
        if(tt >= ts){
            ri = mi;
            ts = tt;
            li = j;
        }
      //  cout<<ts<<" ";
    }
    //cout<<ts<<" ";
    cout<<li<<" "<<ri;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
//OK
