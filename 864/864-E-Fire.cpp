/*
    * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
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
ll n, v[2005];
vector< pair< pair<ll, ll> , pair< ll, ll> > > p;
vll ans[2005];

bool compare(pair< pair<ll, ll> , pair< ll, ll> > p1, pair< pair<ll, ll> , pair< ll, ll> > p2)
{
    if(p1.second.second == p2.second.second)
        return p1.first.first < p2.first.first;
    return p1.second.second < p2.second.second;
}

// Recursion Nahi Lagana :(
    
// pair<ll, vll> rec(ll ci, ll ct)
// {
//     if(ci >= n)
//     {   vll v; return {0, v};  }
//     if(ct > 2000)
//     {   vll v; return {0, v};  }
//     if(dp[ci][ct].first != -1)
//         return dp[ci][ct];
//     ll k2 = 0, k1 = 0;
//     pair<ll, vll> xxx, xxx1, xxx2;
//     if(p[ci].second.second > ct + p[ci].second.first)
//         xxx1 = rec(ci + 1, ct + p[ci].second.first),    k1 = p[ci].first.first + xxx1.first;
//     xxx2 = rec(ci + 1, ct);
//     k2 = xxx2.first;
//     vll v;
//     if(k1 > k2)
//     {
//         xxx.second = xxx1.second;
//         xxx.second.pb(p[ci].first.second);
//         xxx.first = k1;
//     }
//     else
//         xxx.second = xxx2.second,   xxx.first = k2;
//     return xxx;
// }

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    p.resize(n);
    f(0, n)
        cin>>p[i].second.first>>p[i].second.second>>p[i].first.first,   p[i].first.second = i;
    sort(p.begin(), p.end(), compare);
    f(0, n)
    {
        fr(p[i].second.second - 1, p[i].second.first)
        {
            if(v[j] < v[j - p[i].second.first] + p[i].first.first)
            {
                v[j] = v[j - p[i].second.first] + p[i].first.first;
                ans[j] = ans[j - p[i].second.first];
                ans[j].pb(p[i].first.second + 1);
            } 
        }
    }
    ll ansss = 0;   vll kill;
    f(0, 2001)
    {
        if(v[i] > ansss)
        ansss = v[i],    kill = ans[i];
    }
    cout<<ansss<<"\n"<<kill.size()<<"\n";
    f(0, kill.size())       cout<<kill[i]<<" ";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}