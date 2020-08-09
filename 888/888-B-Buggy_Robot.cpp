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

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, f[4] = {0};
    string s;
    cin>>n>>s;
    f(0,n)
    {
        if(s[i]=='U')
            f[0]++;
        else if(s[i]=='D')
            f[1]++;
        else if(s[i]=='L')
            f[2]++;
        else if(s[i]=='R')
            f[3]++;
    }
    ll ans = min(f[0], f[1])*2 + min(f[2], f[3])*2;
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
