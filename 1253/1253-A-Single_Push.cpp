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
        ll n;
        cin >> n;
        ll a[n], b[n];
        bool done = false, ok = true;
        f(0, n) cin >> a[i];
        f(0, n) cin >> b[i];
        f(0, n)
        {
            if (done == true && a[i] != b[i])
            {
                ok = false;
                break;
            }
            if (a[i] == b[i])
                continue;
            ll k = b[i] - a[i];
            if (k < 0)
            {
                ok = false;
                break;
            }
            ll j = i;
            done = true;
            while (j < n)
            {
                if (b[j] == a[j])
                    break;
                if (b[j] - a[j] != k)
                {
                    ok = false;
                    break;
                }
                j++;
            }
            if (!ok)
                break;
            i = j - 1;
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}