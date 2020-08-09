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

    ll n, x;
    cin>>n>>x;
    vll v;
    f(0, n){ll a; cin>>a; v.pb(a);}
    sort(v.begin(), v.end());
    f(0, v.size()-1)
    {
        if(v[i]==v[i+1])
        {
            cout<<0;
            return 0;
        }
    }
    vll b;
    f(0, n)
    {
        ll y = v[i]&x;
        b.pb(y);
        if(binary_search(v.begin(), v.end(), y) && y!=v[i])
        {
            cout<<1;
            return 0;
        }
    }
    sort(b.begin(), b.end());
    f(0, b.size()-1)
    {
        if(b[i]==b[i+1])
        {
            cout<<2;
            return 0;
        }
    }
    cout<<-1;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

