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

    ll n;
    cin>>n;
    ll a[n];
    f(0,n) cin>>a[i];
    ll ans, mt=1e18;
    f(0, n){
        if(a[i] <= i)
        {
            ans = i+1;
            break;
        }
        ll p;
        a[i] -= i;
        if(a[i]%n != 0)
            p = a[i]/n+2;
        else
            p = a[i]/n+1;
        if(p < mt){
            ans = i+1;
            mt = p;
        }
    }
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
