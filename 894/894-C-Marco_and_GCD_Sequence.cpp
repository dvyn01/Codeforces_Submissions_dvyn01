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

    ll m;
    cin>>m;
    vll v;
    ll g;
    f(0, m)
    {
        ll x;
        cin>>x;
        if(i == 0)
            g = x;
        else g = __gcd(g, x);
        v.pb(x);
    }
    if(g != v[0])
    {
        cout<<-1;
        return 0;
    }
    cout<<2*(m-1)+1<<"\n";
    cout<<g<<" ";
    f(1, v.size())
        cout<<v[i]<<" "<<g<<" ";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

