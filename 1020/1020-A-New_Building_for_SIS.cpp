//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, h, a, b, k;
    cin>>n>>h>>a>>b>>k;
    while(k--)
    {
        ll ta, fa, tb, fb;
        cin>>ta>>fa>>tb>>fb;
        ll s=0;
        if(ta == tb){   s = abs(fa-fb); cout<<s<<"\n"; continue; }
        s += abs(ta-tb);
        if(fa>b&&fb>b)  s += fa-b+fb-b;
        else if(fa<a&&fb<a) s += a-fa+a-fb;
        else s += abs(fa-fb);
        cout<<s<<"\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

