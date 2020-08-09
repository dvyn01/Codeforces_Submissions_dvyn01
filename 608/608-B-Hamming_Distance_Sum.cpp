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

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    string a, b;
    cin>>a>>b;
    ll n=a.length(), m=b.length(), ans=0;

    ll f[m+1] = {0};
    f[0] = 0;
    f(1, m+1)
    {
        if(b[i-1] == '1')
            f[i] = f[i-1]+1;
        else f[i] = f[i-1];
    }
  //  f(1, m+1) cout<<f[i]<<" ";
    f(0,n)
    {
        if(a[i] == '0')
            ans += f[m-n+i+1] - f[i];
        else ans += m-n+1 - f[m-n+i+1] + f[i];
    }

    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

