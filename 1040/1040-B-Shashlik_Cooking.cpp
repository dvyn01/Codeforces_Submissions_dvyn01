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

    ll n, k;
    cin>>n>>k;
    ll x = 2*k+1;
    if(n % x == 0)
    {
        cout<<n/x<<"\n";
        ll p = k+1;
        while(p<=n)
        {
            cout<<p<<" ";
            p += 2*k+1;
        }
    }
    else{
        cout<<n/x+1<<"\n";
        if(n % x > k)
        {
        ll p = k+1;
            while(p<=n)
            {
                cout<<p<<" ";
                p += 2*k+1;
            }
        }
        else {
            cout<<1<<" ";
            ll p = 2*k+2;
            while(p<=n)
            {
                cout<<p<<" ";
                p += 2*k+1;
            }
        }
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

