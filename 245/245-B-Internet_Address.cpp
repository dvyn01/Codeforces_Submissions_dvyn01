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
    string z;
    bool c=false, d=false, e=false;
    ll l=0;
    f(0, s.length())
    {
        if(!c && i>=2 && s[i]=='p')
        {
            c = true;
            z += "p://";
            continue;
        }
        if(!e && s[i]=='r' && s[i+1]=='u' && z[i+2]!='/')
        {
            e = true;
            z += ".r";
            continue;
        }
        if(!d && s[i]=='u' && s[i-1]=='r' && e)
        {
            d = true;
            if(i != s.length()-1)
            z += "u/";
            else z += 'u';
            continue;
        }
        z += s[i];
    }
    cout<<z;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
