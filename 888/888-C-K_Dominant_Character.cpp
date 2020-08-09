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
    map<char, ll> m, lo, mm;
    f(0,26) lo[97+i] = -1;
    ll ans=1e18;
    f(0, s.length()) m[s[i]]++;
    f(0, s.length())
    {
        if(m[s[i]] == 1)
        {
            mm[s[i]] = max(i+1, s.length()-i);
            lo[s[i]] = i;
            continue;
        }
        if(lo[s[i]] == -1)
        {
            lo[s[i]] = i;
            mm[s[i]] = i+1;
            continue;
        }
        mm[s[i]] = max(mm[s[i]], i-lo[s[i]]);
        lo[s[i]] = i;
    }
    f(97, 123)
    {
        if(m[i] != 0)
        {
            mm[i] = max(mm[i], s.length()-lo[i]);
        }
    }
    f(0, 26)
    {
        if(m[97+i] != 0)
        {
            ans = min(ans, mm[97+i]);
        }
    }

    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

