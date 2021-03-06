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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        char a[n + 5][m + 5];
        f(1, n + 1) fi(1, m + 1) cin >> a[i][j];
        ll r[n + 5], c[m + 5];
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        f(1, n + 1)
            fi(1, m + 1) if (a[i][j] == '.')
                r[i]++,
            c[j]++;
        ll ans = 1e18;
        f(1, n + 1)
        {
            fi(1, m + 1)
            {
                ll k = r[i] + c[j];
                if (a[i][j] == '.')
                    k--;
                ans = min(ans, k);
            }
        }
        cout << ans << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}