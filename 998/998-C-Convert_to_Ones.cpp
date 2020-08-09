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

    ll n, x, y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    ll c=0, j=-1, k=s.length();
    if(s[0] == '1')
    {
        j=0;
        while(j<s.length() && s[j]=='1') j++;
        if(j == s.length()){cout<<"0"; return 0;}
    }
    if(s[s.length()-1] == '1')
    {
        k = s.length()-2;
        while(k>=0 && s[k] == '1') k--;
    }
    f(j, k+1)
        if(s[i]=='1' && s[i-1]=='0')    c++;
    ll ans=0;
    ans = min(c*x+y, (c+1)*y);
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

