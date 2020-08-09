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
    if(n==1){cout<<"1\n"; cout<<a[0]; return 0;}
    sort(a, a+n);
    if(a[0]==a[n-1]){cout<<"1\n"<<a[0]; return 0;}
    ll x = a[n-1]-a[0];
    ll m=0; vll v;
    f(0,n){
        for(ll j=1; j+a[i]<=a[n-1]; j*=2)
        {
            ll k=1;
            if(binary_search(a, a+n, a[i]+j))
            {
                k++;
                if(binary_search(a, a+n, a[i]+2*j))
                {
                    cout<<"3\n";
                    cout<<a[i]<<" "<<a[i]+j<<" "<<a[i]+2*j;
                    return 0;
                }
            }
            if(k>m)
            {
                if(k==1){ v.pb(a[i]); m=1; }
                else if(k==2){v.clear(); v.pb(a[i]); v.pb(a[i]+j); m=k;}
            }
        }
    }
    cout<<m<<"\n";
    f(0, v.size()) cout<<v[i]<<" ";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

