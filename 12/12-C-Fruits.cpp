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

    ll n, m;
    cin>>n>>m;
    ll a[n];
    f(0, n) cin>>a[i];
    sort(a, a+n);
    unordered_map<string, ll> mm;
    f(0, m)
    {
        string s;
        cin>>s;
        mm[s]++;
    }
    vll v;
    for(auto it=mm.begin(); it!=mm.end(); it++)
        v.pb(it->second);
    sort(v.begin(), v.end());
    ll s1=0, s2=0, p=0;
    fr(v.size()-1, 0)  s1 += v[j]*a[p++];
    p = n-1;
    fr(v.size()-1, 0)  s2 += v[j]*a[p--];
    cout<<s1<<" "<<s2;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

