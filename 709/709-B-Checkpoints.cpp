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

    ll n, k;
    cin>>n>>k;
    ll a[n];
    f(0,n) cin>>a[i];
    sort(a, a+n);
    if(n==1){cout<<"0"; return 0;}
    if(k<=a[0])
    {
        cout<<abs(a[n-2]-k);
    }
    else if(k>=a[n-1])
    {
        cout<<abs(a[1]-k);
    }
    else if(n==2){
        cout<<min(abs(k-a[0]), abs(k-a[1]));
    }
    else if(n==3){
        ll x=abs(a[0]-k), y=abs(a[1]-k), z=abs(a[2]-k);
        if(k==a[1]){
            cout<<min(x, z);
        }
        else if(k<a[1]){
            cout<<min(2*x+y, min(2*y+x, z));
        }
        else{
            cout<<min(2*y+z, min(2*z+y, x));
        }
    }
    else{
        ll s, t, u, v;
        ll p=1e18, q=1e18;
        if(k>a[0] && k<=a[1]) p = abs(a[n-1]-k);
        if(k<a[n-1] && k>=a[n-2]) q = abs(a[0]-k);
        s = abs(a[0]-k); t = abs(a[1]-k); u = abs(a[n-1]-k); v = abs(a[n-2]-k);
      //  cout<<s<<" "<<t<<" "<<u<<" "<<v<<" "<<p<<" "<<q<<"\n";
        cout<<min(s+abs(a[n-2]-a[0]), min(u+abs(a[n-1]-a[1]), min(p,min(q, min(t+abs(a[1]-a[n-1]), v+abs(a[0]-a[n-2]))))));
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

