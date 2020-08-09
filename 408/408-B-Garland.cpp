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

    string a, b;
    cin>>a>>b;
    map<char,ll> m, mm;
    f(0, a.length()) m[a[i]]++;
    f(0, b.length()) mm[b[i]]++;
    map<char, ll> :: iterator it;
    ll s=0;
    for(it=mm.begin(); it!=mm.end(); it++)
    {
        if(m[it->first] == 0){cout<<"-1"; return 0;}
        s += min(it->second, m[it->first]);
    }
    cout<<s;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
