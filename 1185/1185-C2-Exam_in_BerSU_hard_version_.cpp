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

    ll n, m;
    cin >> n >> m;
    ll a[n], t = 0;
    f(0, n) cin >> a[i];
    ll ma[105];
    memset(ma, 0, sizeof(ma));
    f(0, n)
    {
        if (a[i] + t <= m)
        {
            cout << "0 ";
            t += a[i];
            ma[a[i]]++;
            continue;
        }
        ll k = t + a[i], c = 0;
        fr(100, 1)
        {
            if (k <= m)
            {
                cout << c << " ";
                break;
            }
            if (ma[j] == 0)
                continue;
            if (k - ma[j] * j > m)
            {
                c += ma[j];
                k -= j * ma[j];
                continue;
            }
            ll p = (k - m) % j;
            if (p)
                p = (k - m) / j + 1;
            else
                p = (k - m) / j;
            cout << p + c << " ";
            break;
        }
        t += a[i];
        ma[a[i]]++;
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}