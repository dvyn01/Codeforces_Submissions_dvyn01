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

    string s;
    cin>>s;
    ll k=0, n=s.length(), oc=0;
    ll x=0;
    string ans;
    f(0, n){
        if(s[i]=='1') continue;
        else if(s[i] == '0') x++;
        else break;
    }
    f(0, x) ans += '0';
    f(0, n) if(s[i]=='1') oc++;
    f(0, oc) ans += '1';
    ll y=0;
    f(0, n)
    {
        if(s[i]=='0' && y<x){y++; continue; }
        if(s[i] == '1') continue;
        ans += s[i];
    }

    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
