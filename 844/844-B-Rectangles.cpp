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

    ll n, m;
    cin>>n>>m;
    ll a[n][m];
    ll b[n]={0}, c[m]={0};
    f(0,n)
    {
        for(ll j=0; j<m; j++)
        {
            cin>>a[i][j];
            if(a[i][j] == 1)
            {
                b[i]++; c[j]++;
            }
        }
    }
    ll ans = 0;
    f(0,n){
        ans += (1LL<<b[i])-1;
        ans += (1LL<<(m-b[i]))-1;
    }
    f(0,m){
        ans += (1LL<<c[i])-1;
        ans += (1LL<<(n-c[i]))-1;
    }
    ans -= n*m;
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
