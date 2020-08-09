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

    ll n, m;
    cin>>n>>m;
    ll a[n+1];
    memset(a, 0, sizeof(a));
    f(0, m)
    {
        ll x, y;
        cin>>x>>y;
        a[x]++;
        a[y]++;
    }
    ll oc=0, tc=0, mc=0;
    f(1, n+1)
    {
        if(a[i] == 1)
            oc++;
        else if(a[i] == 2)
            tc++;
        else mc++;
    }
    if(oc==0 && mc==0 && tc==n)
        cout<<"ring topology";
    else if(mc==1 && oc==n-1 && tc==0)
        cout<<"star topology";
    else if(oc==2 && tc==n-2)
        cout<<"bus topology";
    else cout<<"unknown topology";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

