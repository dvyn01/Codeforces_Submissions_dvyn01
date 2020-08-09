/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
//      #include <ext/pb_ds/assoc_container.hpp>
//      #include <ext/pb_ds/tree_policy.hpp>

//      using namespace __gnu_pbds;
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
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin>>s>>t;
    ll n = s.length();
    ll x[n+1],  y[n+1]; memset(x, 0, sizeof(x));    memset(y, 0, sizeof(y));
    ll c = 0;
    f(0, n)
    {
        x[i] = c;
        if(c != t.length() - 1 && s[i] == t[c])
            c++;
    }
    c = t.length()-1;
    fr(n-1, 0)
    {
        y[j] = t.length() - c - 1;
        if(c != 0 && s[j] == t[c])
            c--;
    }
    ll cp[26];  memset(cp, 0, sizeof(cp));
    vll v[26];
    f(0, t.length())
        v[t[i] - 'a'].pb(i);
  //  f(0, n)     cout<<x[i]<<" "<<y[i]<<"\n";
    bool ans = true;
    f(0, s.length())
    {
        ll ch = s[i] - 'a';
        if(cp[ch] == v[ch].size())
        {
            ans = false;
            break;
        }
        ll k1 = v[ch][cp[ch]],  k2 = t.length() - k1 - 1;
        if(x[i] >= k1 && y[i] >= k2)
            continue;
        while(cp[ch] != v[ch].size())
        {
            cp[ch]++;
            k1 = v[ch][cp[ch]];  k2 = t.length() - k1 - 1;
            if(x[i] >= k1 && y[i] >= k2)
                break;
        }
        if(cp[ch] == v[ch].size())
        {
            ans = false;
            break;
        }
    }
    if(ans)
        cout<<"Yes";
    else cout<<"No";

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

