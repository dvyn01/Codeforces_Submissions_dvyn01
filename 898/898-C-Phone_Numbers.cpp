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

bool suf(string a, string b)
{
    bool ok = true;
    f(0, a.length())
    {
        if(a[i] != b[b.length() - a.length() + i])
        {
            ok = false;
            break;
        }
    }
    return ok;
}

bool compare(string a, string b)
{
    if(a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

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
    vector<string> v[n];
    string s[n];
    map<string, ll> m;
    f(0, n)
    {
        cin>>s[i];
        ll kk = i;
        if(m[s[i]])
            kk = m[s[i]] - 1;
        else m[s[i]] = i+1;
        ll k;
        string x;
        cin>>k;
        while(k--)
            cin>>x,     v[kk].pb(x);
    }
    f(0, n)     sort(v[i].begin(), v[i].end(), compare);
  //  f(0, n) {fi(0, v[i].size())      cout<<v[i][j]<<" "; cout<<"\n"; }
    vector<string> ans[n];
    f(0, n)
    {
        fi(0, v[i].size())
        {
            bool ok = true;
            fii(j+1, v[i].size())
            {
                if(suf(v[i][j], v[i][k]))
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
                ans[i].pb(v[i][j]);
        }
    }
    ll x = 0;
    f(0, n)
    {
        if(ans[i].size() != 0)
            x++;
    }
    cout<<x<<"\n";
    f(0, n)
    {
        if(ans[i].size())
        {
            cout<<s[i]<<" ";
            cout<<ans[i].size()<<" ";
            fi(0, ans[i].size())        cout<<ans[i][j]<<" ";
            cout<<"\n";
        }
    }

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

