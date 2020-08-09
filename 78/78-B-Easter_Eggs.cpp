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

    ll n;
    cin>>n;
    while(n > 10)
    {
        cout<<"ROYGBIV";
        n -= 7;
    }
    if(n==4){cout<<"ROYG";}
    else if(n==5){cout<<"ROYGB";}
    else if(n==6){cout<<"ROYGBI";}
    else if(n==7){cout<<"ROYGBIV";}
    else if(n==8){cout<<"ROYGRBIV";}
    else if(n==9){cout<<"ROYGBROIV";}
    else if(n==10){cout<<"ROYGBROYIV";}

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

