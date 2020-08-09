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

    string a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c)
    {
        cout << 0;
        return 0;
    }
    if (a[1] == b[1] && b[1] == c[1])
    {
        string z;
        z += a[0];
        z += b[0];
        z += c[0];
        sort(z.begin(), z.end());
        if (z[1] == z[0] + 1 && z[2] == z[1] + 1 || z[0] == z[1] && z[1] == z[2])
        {
            cout << 0;
            return 0;
        }
        if (z[1] == z[0] + 1 || z[2] == z[1] + 1 || z[0] == z[1] || z[1] == z[2] || z[1] == z[0] + 2 || z[2] == z[1] + 2)
        {
            cout << 1;
            return 0;
        }
        cout << 2;
        return 0;
    }
    if (a[1] != b[1] && b[1] != c[1] && c[1] != a[1])
    {
        cout << 2;
        return 0;
    }
    string z;
    if (a[1] == b[1])
        z += a[0], z += b[0];
    else if (a[1] == c[1])
        z += a[0], z += c[0];
    else
        z += b[0], z += c[0];
    sort(z.begin(), z.end());
    if (z[1] == z[0] + 1 || z[0] == z[1] || z[1] == z[0] + 2)
        cout << 1;
    else
        cout << 2;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}