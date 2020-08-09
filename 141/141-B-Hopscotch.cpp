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

    ld a, x, y;
    cin>>a>>x>>y;
    if(int(y)%int(a) == 0)
    {
        cout<<-1;
        return 0;
    }
    ld p=-1*a, q=-1*a/2, r=a/2, s=a;
    ll e = y/a;
    if(e < 1)
    {
        if(x<=q || x>=r)
            cout<<-1;
        else cout<<1;
            return 0;
    }
    if(e%2)
    {
        if(x<=q || x>=r)
            cout<<-1;
        else cout<<e+int(e/2)+1;
        return 0;
    }
    else
    {
        if(x<=p || x>=s || x==0)
            cout<<-1;
        else{
            ll xx = e-1+(e-1)/2;
            if(x<0) cout<<xx+2;
            else cout<<xx+3;
        }
        return 0;
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

