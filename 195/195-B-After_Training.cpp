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
    vll v;
    ll p, q;
    if(m%2) {   v.pb(m/2+1);    p = m/2; q=m/2+2;}
    else {  v.pb(m/2); v.pb(m/2+1);   p=m/2-1; q=m/2+2; }
    while(q<=m)
    {
        v.pb(p);
        p--;
        v.pb(q);
        q++;
    }
    ll k=0;
    f(0, n)
    {
        cout<<v[k]<<"\n";
        k++;
        if(k==v.size())    k=0;
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

