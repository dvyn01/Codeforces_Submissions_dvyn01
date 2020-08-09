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

ll n, a0[200050], a1[200050], s0[200050], s1[200050];
bool b[200050][2];

void init(ll n)
{
    f(0, n + 5) a0[i] = i, a1[i] = i, s0[i] = 1, s1[i] = 1;
}

ll root(ll i, ll a[])
{
    while (i != a[i])
        i = a[i];
    return i;
}

void merge(ll x, ll y, ll *a, ll *s)
{
    ll xr = root(x, a), yr = root(y, a);
    if (xr == yr)
        return;
    if (s[xr] >= s[yr])
        s[xr] += s[yr], a[yr] = xr;
    else
        s[yr] += s[xr], a[xr] = yr;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    init(n);
    f(0, n - 1)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        if (w == 0)
            merge(x, y, a0, s0), b[x][0] = true, b[y][0] = true;
        else
            merge(x, y, a1, s1), b[x][1] = true, b[y][1] = true;
    }
    ll ans = 0;
    f(1, n + 1)
    {
        if (root(i, a0) == i)
            ans += s0[i] * (s0[i] - 1);
        if (root(i, a1) == i)
            ans += s1[i] * (s1[i] - 1);
    }
    f(1, n + 1) if (b[i][0] && b[i][1])
        ans += (s0[root(i, a0)] - 1) * (s1[root(i, a1)] - 1);
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}