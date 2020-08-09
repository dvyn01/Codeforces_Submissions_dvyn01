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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        pll parts;
        parts.pb({1, n});
        ll ans = 0, c;
        while (1)
        {
            pll p1, p2;
            ll x1 = 0, x2 = 0;
            bool ok = true;
            f(0, parts.size())
            {
                ll k = parts[i].second - parts[i].first + 1;
                if (k & 1)
                    k = k / 2 + 1;
                else
                    k = k / 2;
                //     cout << "k -> " << k << "\n";
                ll x = parts[i].first;
                x += k - 1;
                p1.pb({parts[i].first, x});
                p2.pb({x + 1, parts[i].second});
                x1 += k;
                x2 += parts[i].second - parts[i].first + 1 - k;
            }
            cout << x1 << " " << x2 << " ";
            f(0, p1.size()) for (ll kk = p1[i].first; kk <= p1[i].second; kk++)
                    cout
                << kk << " ";
            f(0, p2.size()) for (ll kk = p2[i].first; kk <= p2[i].second; kk++)
                    cout
                << kk << " ";
            cout << endl;
            cin >> c;
            if (c > ans)
                ans = c;
            parts.clear();
            // cout << "p1 -> ";
            f(0, p1.size())
            {
                parts.pb({p1[i].first, p1[i].second});
                if (p1[i].second > p1[i].first)
                    ok = false;
            }
            // cout << "p2 -> ";
            f(0, p2.size())
            {
                parts.pb({p2[i].first, p2[i].second});
                if (p2[i].second > p2[i].first)
                    ok = false;
            }
            if (ok)
                break;
        }
        cout << "-1 " << ans << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}
