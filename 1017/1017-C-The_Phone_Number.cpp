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

    ll n, k=0;
    cin>>n;
    k=n;
    ll s = sqrt(n);
    vll v;
    for(ll i=s; ; i+=s)
    {
        bool ok = true;
        if(k<s)
        {
            i -= s;
            i++;
            fr(k-1, 0)
            {
                v.pb(i+j);
            }
            break;
        }
        fr(i, i-s+1)
        {   v.pb(j);  k--;  if(k==0) {ok=false; break; }}
        if(!ok) break;
    }
    fr(v.size()-1, 0)   cout<<v[j]<<" ";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

