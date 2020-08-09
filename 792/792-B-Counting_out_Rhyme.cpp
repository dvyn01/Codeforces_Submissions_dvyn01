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

    ll n, k;
    cin>>n>>k;
    ll a[k];
    f(0, k) cin>>a[i];
    ll p = 1;
    bool b[n+1] = {false};
    f(0, k)
    {
        ll x = a[i]%(n-i), c=0;
        while(c!=x)
        {
            if(b[p]){p = (p%n)+1; continue;}
            c++;
            p = (p%n)+1;
        }
        while(b[p]) p = (p%n)+1;
        b[p] = true;
        cout<<p<<" ";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

