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

ll a[200050], s[200050], far[200050];

ll root(ll i)
{
    while (i != a[i])
        i = a[a[i]];
    return i;
}

void merge(ll x, ll y)
{
    ll xr = root(x), yr = root(y);
    if (xr == yr)
        return;
    if (s[xr] >= s[yr])
        s[xr] += s[yr], far[xr] = max(far[xr], far[yr]), a[yr] = xr;
    else
        s[yr] += s[xr], far[yr] = max(far[xr], far[yr]), a[xr] = yr;
}

void init(ll n)
{
    f(0, n + 5) a[i] = i, s[i] = 1, far[i] = i;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, x, y;
    cin >> n >> m;
    init(n);
    f(0, m) cin >> x >> y, merge(x, y);
    ll mx = 0, j = 2, ans = 0;
    f(1, n + 1)
    {
        ll k = far[root(i)];
        if (k < mx)
            continue;
        mx = k;
        while (j <= mx)
        {
            if (root(i) != root(j))
            {
                merge(i, j);
                ans++;
            }
            j++;
        }
    }
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}