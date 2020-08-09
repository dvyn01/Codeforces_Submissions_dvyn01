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

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ld n, m;
    cin>>n>>m;
    ld a = n*(n-1)/2, b;
    a = (ll)a;
    ld c=int(n/2); ld d=c*(c+1)/2*1.0; d*=2.0; b=d;
    b = (ll)b;
    if((ll)n%2==0) b -= (n/2);
    ld s=0;
    f(0, m)
    {
        ld x, y;
        cin>>x>>y;
        s += max(a*y+n*x, b*y+n*x);
    }
    s = s/n*1.0;
    cout<<fixed<<setprecision(15)<<s;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

