/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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
typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll s = 0, ns = 0;
    ll a[n], b[n], c[n];
    f(0, n)
    {
        b[i] = 1e18;
        c[i] = 1e18;
        cin>>a[i];
        ld k = sqrt(a[i]);
        ll p = k;
        if(p == k)
        {
            s++;
            if(a[i] == 0)
                c[i] = 2;
            else c[i] = 1;
            continue;
        }
        ns++;
        ll q = p + 1;
        b[i] = min(abs(p * p - a[i]), abs(q * q - a[i]));
    }
    sort(b, b+n);
    sort(c, c+n);
//    cout<<s<<" "<<ns<<"\n";
    if(s == ns)
    {
        cout<<0<<"\n";
        return 0;
    }
    if(s > ns)
    {
        ll ans = 0;
        f(0, (s - ns) / 2)
            ans += c[i];
        cout<<ans;
        return 0;
    }
    ll ans = 0;
    f(0, (ns - s) / 2)        ans += b[i];
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

