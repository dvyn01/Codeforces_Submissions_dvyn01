/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll,ll>
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

    ll n;
    cin>>n;
    map<string, ll> m;
    f(0, n)
    {
        ll p;   string s;
        cin>>p>>s;
        sort(s.begin(), s.end());
        if(m[s] == 0)
            m[s] = p;
        else if(p < m[s])
            m[s] = p;
    }
    ll ans = 1e18;
    if(m["ABC"])    ans = min(m["ABC"], ans);
    if(m["AB"] && m["C"])    ans = min(m["AB"] + m["C"], ans);
    if(m["AC"] && m["B"])    ans = min(m["AC"] + m["B"], ans);
    if(m["BC"] && m["A"])    ans = min(m["BC"] + m["A"], ans);
    if(m["A"] && m["B"] && m["C"])  ans = min(ans, m["A"] + m["B"] + m["C"]);
    if(m["AB"] && m["AC"])    ans = min(m["AB"] + m["AC"], ans);
    if(m["AB"] && m["BC"])    ans = min(m["AB"] + m["BC"], ans);
    if(m["AC"] && m["BC"])    ans = min(m["AC"] + m["BC"], ans);
    if(ans == 1e18) cout<<-1;
    else
        cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

