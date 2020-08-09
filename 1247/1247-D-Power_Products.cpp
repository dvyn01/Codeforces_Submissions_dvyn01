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

ll a[100050];
map<pll, ll> m;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, n, k, ans = 0;
    cin >> n >> k;
    ll mx = 0;
    f(1, n + 1)
    {
        cin >> a[i];
        pll p;
        for (ll j = 2; j * j <= a[i]; j++)
        {
            ll c = 0;
            while (a[i] % j == 0)
                a[i] /= j, c++;
            if (c % k != 0)
                p.pb({j, c % k});
        }
        if (a[i] > 1)
            p.pb({a[i], 1});
        pll p1;
        fi(0, p.size()) p1.pb({p[j].first, k - p[j].second});
        ans += m[p1];
        m[p]++;
    }
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}