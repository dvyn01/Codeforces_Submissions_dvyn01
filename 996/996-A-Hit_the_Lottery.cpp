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

    ll n;
    cin>>n;
    ll s=0;
    if(n >= 100)
    {
        s += n/100;
        n -= (n/100)*100;
    }
    if(n >= 20){
        s += n/20;
        n -= (n/20)*20;
    }
    if(n >= 10){
        s += n/10;
        n -= (n/10)*10;
    }
    if(n >= 5)
    {
        s += n/5;
        n -= (n/5)*5;
    }
    if(n >= 1)
    {
        s += n;
        n -= n;
    }
    cout<<s;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
