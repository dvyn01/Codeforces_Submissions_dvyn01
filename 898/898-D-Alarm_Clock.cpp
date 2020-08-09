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
bool b[200050];

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k, j = 0;
    cin>>n>>m>>k;
    ll a[n];
    f(0, n)     cin>>a[i],  b[i] = true;
    sort(a, a+n);
    if(k == 1)
    {
        cout<<n;
        return 0;
    }
    ll ans = 0, c = 0;
    f(0, n)
    {
        if(!b[i])
            continue;
        if(j < i)
        {
            j = i;
            c = 0;
        }
        while(j < n && a[j] - a[i] < m)
        {
            if(!b[j])
            {
                j++;
                continue;
            }
            c++;
            if(c >= k)
            {
                ans++;
                c--;
                b[j] = false;
            }
            j++;
        }
        c--;
    }
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

