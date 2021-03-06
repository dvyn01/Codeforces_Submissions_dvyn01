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

    string s, t;
    ll ans=0;
    unordered_map<char, ll> m, mm;
    cin>>s>>t;
    f(0, t.length())    m[t[i]]++;
    f(0, t.length())
        if(s[i] != '?') mm[s[i]]++;
    bool ok = true;
    for(auto it=mm.begin(); it!=mm.end(); it++)
    {
        if(m[it->first] < it->second)
        {
            ok = false;
            break;
        }
    }
    if(ok)  ans++;
    ll cp=0;
    f(t.length(), s.length())
    {
        bool ok = true;
        if(s[cp] != '?')    mm[s[cp]]--;
        cp++;
        if(s[i] != '?') mm[s[i]]++;
        for(auto it=mm.begin(); it!=mm.end(); it++)
        {
            if(m[it->first] < it->second)
            {
                ok = false;
                break;
            }
        }
        if(ok)  ans++;
    }
    cout<<ans;


     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

