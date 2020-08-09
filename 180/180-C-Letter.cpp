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

    string s;
    cin>>s;
    ll n = s.length();
    ll a[n+1]={0};
    if(s[0]>='A' && s[0]<='Z')
        a[0]=1;
    ll ans = 0;
    f(0, n) if(s[i]>='A' && s[i]<='Z')  ans++;
    f(1, n)
    {
        if(s[i]>='A' && s[i]<='Z')
            a[i] = a[i-1]+1;
        else a[i] = a[i-1];
    }
    a[n] = a[n-1];
    f(0, n)
    {
        ans = min(ans, i+1-a[i]-a[i]+a[n]);
    }
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


