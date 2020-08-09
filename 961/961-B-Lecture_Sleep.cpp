//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define vll vector<ll>;
#define pll vector<pair<ll,ll>>


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n,k;
    cin>>n>>k;
    ll a[n+1], b[n+1], s[n+1], cs[n+1],p=0;
    a[0]=0, b[0]=0,cs[0]=0,s[0]=0;
    f(1,n+1) {
     cin>>a[i];
     p += a[i];
     cs[i] = p;
    }
    p=0;
    f(1,n+1)
    {
        cin>>b[i];
        if(b[i]==1)
            p += a[i];
        s[i] = p;
    }
    ll m=0;
    f(1,n-k+2)
    {
        ll bf = s[i-1], af = s[n]-s[i+k-1], ss = cs[i+k-1]-cs[i-1];
        ll ts = bf+af+ss;
        if(ts > m)
            m = ts;
      //     cout<<bf<<" "<<ss<<" "<<af<<"     ";
    }
    cout<<m;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

