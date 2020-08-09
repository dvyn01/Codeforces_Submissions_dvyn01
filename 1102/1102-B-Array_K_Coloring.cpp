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
bool b[5005][5005];

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin>>n>>k;
    ll a[n], c[n];
    memset(c, -1, sizeof(c));
    bool ans = false;
    ll f[5005]; memset(f, 0, sizeof(f));
    f(0, n)     {   cin>>a[i];  f[a[i]]++;  }
    f(0, 5005)
    {
        if(f[i] > k)
        {
            cout<<"NO";
            return 0;
        }
    }
    ll cc = 1;
    f(0, n)
    {
        if(!b[a[i]][cc])
        {
            b[a[i]][cc] = true;
            c[i] = cc;
            if(cc == k)
                ans = true;
            cc = cc % k + 1;
        }
        else{
            cc = cc % k + 1;
            i--;
        }
    }
    if(ans)
    {
        cout<<"YES\n";
        f(0, n)     cout<<c[i]<<" ";
    }
    else cout<<"NO";

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

