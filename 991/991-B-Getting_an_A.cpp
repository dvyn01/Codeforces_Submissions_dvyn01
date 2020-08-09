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

    ll n;   ld s=0.0;
    cin>>n;
    ll a[n];
    f(0,n) { cin>>a[i]; s+=a[i]; }
    ld m = s/n*1.0;
    if(m >= 4.5){cout<<"0"; return 0;}
    sort(a, a+n);
    ll c=0;
    f(0,n){
        s -= a[i];
        s += 5.0;
        m = s/n*1.0;
        c++;
        if(m>=4.5){cout<<c; return 0;}
    }


     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

