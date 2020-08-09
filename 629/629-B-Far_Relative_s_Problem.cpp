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
ll a[367], b[367];

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
    f(0,n){
        char c; ll x, y;
        cin>>c>>x>>y;
        if(c=='M'){a[x]++; a[y+1]--;}
        else{b[x]++, b[y+1]--;}
    }
    f(1,367) a[i] = a[i-1] + a[i];
    f(1, 367) b[i] = b[i-1] + b[i];
    ll  s=0;
    f(1, 367) if(min(a[i], b[i]) > s) s=min(a[i], b[i]);
    cout<<2*s;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

