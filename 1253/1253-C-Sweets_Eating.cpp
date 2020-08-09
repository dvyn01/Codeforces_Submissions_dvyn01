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
#define print(x) cout << #x << " is " << x << endl;
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll s[200050], ans[200050], g[200050];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    ll a[n + 5];
    f(1, n + 1) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll c = 1;
    f(1, n + 1)
    {
        if (g[i] != 0)
            continue;
        g[i] = c++;
        fi(i + m, n + 1)
            g[j] = g[i],
            j += m - 1;
    }
    f(1, n + 1) s[g[i]] += a[i];
    c = 0;
    ll d = 1, tot = 0;
    fr(n, 1)
    {
        ll k1 = d * a[j];
        c++;
        if (c == m)
            d++, c = 0;
        tot += k1;
    }
    fr(n, 1)
    {
        ans[j] = tot;
        s[g[j]] -= a[j];
        tot -= s[g[j]] + a[j];
    }
    f(1, n + 1) cout << ans[i] << " ";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}