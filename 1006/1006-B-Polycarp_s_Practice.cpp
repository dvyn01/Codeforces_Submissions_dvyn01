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

    ll n, k, s=0;
    cin>>n>>k;
    ll a[n], b[n];
    f(0, n){cin>>a[i]; b[i]=a[i];}
    sort(b, b+n);
    map<ll,ll> m;
    fr(n-1, n-k)
        { m[b[j]]++; s+=b[j]; }
    ll ans[k] = {0}, c=0, p=0, mp=0;
    f(0, n)
    {
        if(m[a[i]])
        {
            ans[p++] = c+1;
            c=0; mp=i;
            m[a[i]]--;
            continue;
        }
        c++;
    }
    p--; ans[p] += n-mp-1;
    cout<<s<<"\n";
    f(0, k) cout<<ans[i]<<" ";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

