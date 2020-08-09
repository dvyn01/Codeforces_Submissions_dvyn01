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

ll a[200050], b[200050], c[200050];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, ans = 0;
    cin >> n;
    f(1, n + 1) cin >> a[i];
    f(1, n + 1) cin >> b[i];
    if (n == 1)
    {
        if (b[1] == 1)
            cout << 0;
        else
            cout << 1;
        return 0;
    }
    f(1, n + 1) c[b[i]] = i;
    bool ok = true, one = false;
    f(1, n + 1)
    {
        if (b[i] == 1)
        {
            one = true;
            ll xx = 2;
            fi(i + 1, n + 1)
            {
                if (b[j] != xx)
                {
                    ok = false;
                    break;
                }
                xx++;
            }
        }
    }
    if (ok && one)
    {
        ll x = b[n] + 1;
        if (x == n + 1)
        {
            cout << 0;
            return 0;
        }
        ll k = 0;
        f(x, n + 1)
        {
            k++;
            if (c[i] >= k)
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            cout<<n - b[n];
            return 0;
        }
    }
    pl p;
    ll k = c[1] + 1;
    p.first = c[1] + 1, p.second = 1;
    f(2, n + 1)
    {
        k++;
        if (c[i] >= k)
            p.first = c[i] + 1, p.second = i, k = c[i] + 1;
    }
    ans = p.first + n - p.second;
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}