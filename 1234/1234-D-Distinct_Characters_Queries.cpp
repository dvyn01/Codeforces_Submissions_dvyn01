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
#define print(x) cerr << #x << " is " << x << endl;
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

    string s;
    cin >> s;
    set<ll> xxx[26];
    f(0, s.length()) xxx[s[i] - 'a'].insert(i + 1);
    ll q;
    cin >> q;
    while (q--)
    {
        ll c;
        cin >> c;
        if (c == 1)
        {
            ll pos;
            char x;
            cin >> pos >> x;
            ll k = s[pos - 1] - 'a';
            xxx[k].erase(xxx[k].find(pos));
            k = x - 'a';
            xxx[k].insert(pos);
            s[pos - 1] = x;
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            ll ans = 0;
            f(0, 26)
            {
                auto it = xxx[i].lower_bound(l);
                if (it == xxx[i].end() || *it > r)
                    continue;
                ans++;
            }
            cout << ans << "\n";
        }
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}