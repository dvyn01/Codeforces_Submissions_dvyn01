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

ll x[2005], y[2005], c[2005], k[2005], dist[2005][2005];
pll p;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    p.resize(n + 5);
    f(1, n + 1) cin >> x[i] >> y[i], p[i] = {1e18, 1e18};
    f(1, n + 1) cin >> c[i];
    f(1, n + 1) cin >> k[i];
    f(1, n + 1) fi(1, n + 1) dist[i][j] = (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]);
    ll done = 0, tot = 0;
    bool hoGya[n + 5];
    memset(hoGya, false, sizeof(hoGya));
    pll edges;
    vll v;
    set<pair<ll, ll>> s1;
    f(1, n + 1) s1.insert({c[i], i});
    while (done < n)
    {
        ll x1 = -1, x2 = 1e18, uu = 0, vv = 0;
        if (!s1.empty())
            x1 = s1.begin()->first;
        f(1, n + 1)
        {
            if (!hoGya[i] && p[i].first < x2)
                x2 = p[i].first, uu = i, vv = p[i].second;
        }
        if (x2 == 1e18)
            x2 = -1;
        if (x2 == -1 || (x2 != -1 && x1 <= x2))
        {
            ll u = s1.begin()->second;
            s1.erase(s1.begin());
            if (hoGya[u])
                continue;
            tot += x1;
            hoGya[u] = true;
            v.pb(u);
            f(1, n + 1) if (i != u && !hoGya[i] && p[i].first > dist[u][i]) p[i].first = dist[u][i], p[i].second = u;
        }
        else if (x1 == -1 || (x1 != -1 && x2 < x1))
        {
            if (hoGya[uu] && hoGya[vv])
                continue;
            tot += x2;
            edges.pb({uu, vv});
            if (!hoGya[uu])
            {
                hoGya[uu] = true;
                f(1, n + 1) if (i != uu && !hoGya[i] && p[i].first > dist[uu][i]) p[i].first = dist[uu][i], p[i].second = uu;
            }
            if (!hoGya[vv])
            {
                hoGya[vv] = true;
                f(1, n + 1) if (i != vv && !hoGya[i] && p[i].first > dist[vv][i]) p[i].first = dist[vv][i], p[i].second = vv;
            }
        }
        done++;
    }
    cout << tot << "\n";
    cout << v.size() << "\n";
    f(0, v.size()) cout << v[i] << " ";
    cout << "\n";
    cout << edges.size() << "\n";
    f(0, edges.size()) cout << edges[i].first << " " << edges[i].second << "\n";

#ifndef ONLINE_JUDGE
    cout
        << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}