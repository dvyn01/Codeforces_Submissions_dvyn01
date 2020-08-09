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

    ll n, m, d;
    cin >> n >> m >> d;
    ll a[m + 1], b[m + 1];
    memset(b, 0, sizeof(b));
    f(1, m + 1) cin >> a[i];
    ll ans[n + 1];
    memset(ans, 0, sizeof(ans));
    ll cd = 0, in = 1;
    f(1, n + 1)
    {
        cd++;
        if (cd >= d)
        {
            if (in > m)
            {
                cout << "NO\n";
                return 0;
            }
            ll k = 0;
            fi(i, min(n + 1, i + a[in])) ans[j] = in, k = j, b[in]++;
            i = k;
            in++;
            cd = 0;
        }
    }
    f(1, n + 1)
    {
        if (ans[i] == 0)
        {
            cd = 0;
            ll k = 0;
            fi(i, n + 1)
            {
                if (ans[j] != 0)
                    break;
                cd++;
                k = j;
                if (cd >= d)
                {
                    cout << "NO\n";
                    return 0;
                }
            }
            i = k;
        }
    }
    cout << "YES\n";
    vll v;
    fi(1, m + 1)
    {
        if (b[j] < a[j])
            f(0, a[j] - b[j]) v.pb(j);
    }
    ll zc = 0;
    fr(n, 1)
    {
        if (zc == v.size())
            break;
        if (ans[j] == 0)
            zc++, ans[j] = -1;
    }
    f(1, n + 1) if (ans[i] != -1) cout << ans[i] << " ";
    f(0, v.size()) cout << v[i] << " ";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}