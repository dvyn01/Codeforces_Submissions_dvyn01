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

    ll n, k, p, x, y, s=0;
    cin>>n>>k>>p>>x>>y;
    vll ans;
    ll a[k];
    f(0, k) { cin>>a[i]; s+=a[i]; }
    sort(a, a+k);
    ll r = n-k;
    if(k > n/2 && a[n/2]<y){cout<<"-1"; return 0; }
    ll q=0;
    f(0, k)
        {if(a[i]>=y) {q=i; break;} if(i==k-1)q=k; }

    q = n/2 - q;
    f(0, min(q, n-k)){ans.pb(1); s++; }
    q = k+ans.size();
    f(q, n) {ans.pb(y); s += y;}
    if(s > x){cout<<"-1"; return 0;}
    else f(0, ans.size()) cout<<ans[i]<<" ";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

