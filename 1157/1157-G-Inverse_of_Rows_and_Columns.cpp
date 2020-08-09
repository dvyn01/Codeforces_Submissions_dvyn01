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
    ll a[n][m];
    string s[n];
    bool one = false, zero = false;
    f(0, n) fi(0, m) cin >> a[i][j], s[i] += '0' + a[i][j], (a[i][j] == 1) ? one = true : 0, (a[i][j] == 0) ? zero = true : 0;
    if (!one || !zero)
    {
        cout << "YES\n";
        f(0, n) cout << 0;
        cout << "\n";
        f(0, m) cout << 0;
        return 0;
    }
    f(0, n)
    {
        fi(0, m)
        {
            bool ok = true;
            string x, y;
            fii(0, m)
            {
                if (k < j)
                {
                    if (a[i][k] == 0)
                        x += '0', y += '1';
                    else
                        x += '1', y += '0';
                }
                else
                {
                    if (a[i][k] == 0)
                        x += '1', y += '0';
                    else
                        x += '0', y += '1';
                }
            }
            vll v;
            // cout<<x<<" "<<y<<"\n";
            fii(0, n)
            {
                if (k == i)
                {   v.pb(0);    continue;   }
                if (s[k] == x)
                {
                    if (k < i)
                        v.pb(0);
                    else
                        v.pb(1);
                }
                else if (s[k] == y)
                {
                    if (k < i)
                        v.pb(1);
                    else
                        v.pb(0);
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                cout << "YES\n";
                // cout<<i<<" "<<j<<"----\n";
                fii(0, v.size())
                {
                    if (k == i - 1)
                        cout << v[k];
                    else
                        cout << v[k];
                }
                cout << "\n";
                cout << x;
                return 0;
            }
        }
    }
    cout << "NO";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}