/*
    * AUTHOR : Divyanshu *
*/

#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

inline ll mul(ll x, ll y, ll m)
{
    ll z = 1LL * x * y;
    if (z >= m)
        z %= m;
    return z;
}
inline ll add(ll x, ll y, ll m)
{
    ll z = x + y;
    if (z >= m)
        z %= m;
    return z;
}
inline ll sub(ll x, ll y, ll m)
{
    ll z = x - y;
    if (z < 0)
        z += m;
    z %= m;
    return z;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k, x;
    cin >> n >> k;
    set<ll> s;
    map<ll, ll> m;
    ll ans[n] = {0};
    set<pair<ll, ll>> p;
    f(0, n) cin >> x, m[x] = i, s.insert(x), p.insert({i, x});
    ll ct = 1;
    while (!s.empty())
    {
        ll k1 = *--s.end(), c = 0;
        ll x = m[k1];
        auto it = p.lower_bound({x, k1});
        pll p1;
        for (auto it1 = it; it1 != p.end(); it1++)
        {
            c++;
            p1.pb({it1->first, it1->second});
            if (c == k + 1)
                break;
        }
        c = 0;
        auto it1 = it;
        if (it != p.begin())
        {
            for (it1 = --it; it1 != p.begin(); it1--)
            {
                c++;
                p1.pb({it1->first, it1->second});
                if (c == k)
                    break;
            }
            if(it1 == p.begin() && c < k)
                p1.pb({it1->first, it1->second});
        }
        f(0, p1.size())
            ans[p1[i].first] = ct,  s.erase(s.find(p1[i].second)),  p.erase(p.find(p1[i]));
        if (ct == 1)
            ct = 2;
        else
            ct = 1;
    }
    f(0, n) cout << ans[i];

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}