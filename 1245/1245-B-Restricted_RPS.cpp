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
        ll n;
        cin >> n;
        ll a, b, c;
        string r;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        bool ok = true;
        ll x = n / 2;
        if (n & 1)
            x++;
        f(0, s.length()) r.pb('#');
        ll tot = 0;
        f(0, s.length())
        {
            if (s[i] == 'R' && b > 0)
                b--, r[i] = 'P', tot++;
            if (s[i] == 'P' && c > 0)
                c--, r[i] = 'S', tot++;
            if (s[i] == 'S' && a > 0)
                a--, r[i] = 'R', tot++;
        }
        if (tot < x)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        f(0, r.length())
        {
            if (r[i] == '#')
            {
                if (a > 0)
                    r[i] = 'R', a--;
                else if (b > 0)
                    r[i] = 'P', b--;
                else
                    r[i] = 'S', c--;
            }
        }
        cout << r << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}