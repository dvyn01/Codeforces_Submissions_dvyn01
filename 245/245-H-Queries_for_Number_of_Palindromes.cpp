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
bool pal[5005][5005];
ll ans[5005][5005];

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    ll n = s.length();
    f(0, s.length())
        pal[i][i] = true;
    f(0, s.length() - 1)    if(s[i] == s[i+1])  pal[i][i+1] = true;
    for(ll k = 3; k <= n; k++)
    {
        for(ll i = 0; i <= n - k + 1; i++)
        {
            ll j = i + k - 1;
            if(pal[i+1][j-1] && s[i] == s[j])
                pal[i][j] = true;
        }
    }
    f(0, n) ans[i][i] = 1;
    f(0, n-1){  if(s[i] == s[i+1])  ans[i][i+1] = 3;    else ans[i][i+1] = 2;   }
    for(ll k = 3; k <= n; k++)
    {
        for(ll i = 0; i <= n - k + 1; i++)
        {
            ll j = i + k - 1;
            ans[i][j] = ans[i+1][j] + ans[i][j-1];
            ans[i][j] -= ans[i+1][j-1];
            if(pal[i][j])   ans[i][j]++;
        }
    }
    ll q;
    cin>>q;
    while(q--)
    {
        ll l, r;
        cin>>l>>r;
        l--;    r--;
        cout<<ans[l][r]<<"\n";
    }

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

