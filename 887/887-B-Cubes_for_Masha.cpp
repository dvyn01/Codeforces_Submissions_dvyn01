//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
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

    ll n;
    cin>>n;
    map<ll,ll> m;
    bool b[10]={false}, bb[10]={false},bbb[10]={false};
    f(0, n){fi(0, 6){ll x; cin>>x; m[x]++;    if(i==0)b[x]=true; else if(i==1) bb[x]=true;    else bbb[x]=true;} }
    f(1, 10){if(m[i]==0){cout<<i-1; return 0; }}
    if(m[0]==0){cout<<9; return 0; }
    f(10, 100)
    {
        ll x=i%10, y=i/10;
        if(!((b[x]&&bb[y]) || (b[y]&&bb[x]) || (b[x]&&bbb[y]) || (b[y]&&bbb[x]) || (bb[x]&&bbb[y]) || (bb[y]&&bbb[x])))
        {
            cout<<i-1;
            return 0;
        }

    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
