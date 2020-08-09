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

    ll n, ans=0;
    cin>>n;
    map<string, ll> m;
    m["ABSINTH"]=1; m["BRANDY"]=1; m["BEER"]=1;m["CHAMPAGNE"]=1; m["GIN"]=1;m["RUM"]=1;m["SAKE"]=1;
    m["TEQUILA"]=1;m["VODKA"]=1;m["WHISKEY"]=1;m["WINE"]=1;
    f(0, n)
    {
        string s;
        cin>>s;
        if(s[0]>=48 && s[0]<=57)
        {
            ll k=0, ss=0;
            while(k<s.length())
            {
                ss *= 10;
                ll p = s[k]-48;
                ss += p;
                k++;
            }
            if(ss < 18) ans++;
        }
        else{
            if(m[s])
                ans++;
        }
    }
    cout<<ans<<" ";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
