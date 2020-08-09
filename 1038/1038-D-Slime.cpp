/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll,ll>
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

    ll n;
    cin>>n;
    ll sm = 1e18, s=0;
    bool neg = false;
    if(n == 1)
    {
        ll x;
        cin>>x;
        cout<<x;
        return 0;
    }
    bool allneg = true;
    ll mx = -1e18;
    f(0, n)
    {
        ll x;
        cin>>x;
        s += abs(x);
        if(x <= 0)  neg = true;
        if(x >= 0)
            sm = min(sm, x);
        if(x > 0)
            allneg = false;
        mx = max(mx, x);
    }
    if(allneg)
    {
        cout<<s + 2*mx;
        return 0;
    }
    if(neg)
        cout<<s;
    else cout<<s - 2*sm;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

