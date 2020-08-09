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

    ll n, c=0;
    cin>>n;
    vll a, b;
    f(0,n) {ll x;   cin>>x;   a.pb(x);}
    f(0,n){
        b.pb(a[i]);
        if(i!=n-1 && __gcd(a[i], a[i+1]) != 1)
            b.pb(1);
    }
    cout<<b.size()-a.size()<<"\n";
    f(0,b.size()) cout<<b[i]<<" ";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

