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

    ll n;
    cin>>n;
    pair<pair<ll,ll>, ll> p[4];
    f(0,4)
    {
        ll a, b, c, d;
        cin>>a>>b>>c>>d;
        a = min(a,b); c = min(c,d);
        p[i].first.first = a+c;    p[i].first.second = a;  p[i].second = i+1;
    }
    sort(p, p+4);
    if(p[0].first.first > n)
    {
        cout<<"-1"; return 0;
    }
    cout<<p[0].second<<" ";
    cout<<p[0].first.second<<" ";
    cout<<n-p[0].first.second;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

