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

    ll n, d, s=0;
    cin>>n>>d;
    ll a[n];
    f(0,n)  cin>>a[i];
    f(1, n)
    {
        if(a[i] <= a[i-1])
           {
               s += abs(a[i]-a[i-1])/d+1;
               a[i] += (abs(a[i]-a[i-1])/d+1)*d;
           }
    }
  //  f(0,n) cout<<a[i]<<" "; cOmMeNt +  CoMmEnT = COMMENT + comment
    cout<<s;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

