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

    ll n, k, m=1e18, pos=0;
    cin>>n>>k;
    ll a[n+1];
    f(1, n+1) cin>>a[i];
    f(1, k+1)
    {
        ll p = a[i];
        ll j;
        if((i+k)%n==0) j=n;
        else j = (i+k)%n;
        while(j!=i)
        {
            p += a[j];
            if((j+k)%n==0) j=n;
            else j = (j+k)%n;
        }
        if(p < m)
        { pos = i; m=p; }
    }
    cout<<pos;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

