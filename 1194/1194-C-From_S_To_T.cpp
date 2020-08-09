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
        string s, t, p;
        cin >> s >> t >> p;
        ll c[4][28];
        memset(c, 0, sizeof(c));
        f(0, s.length()) c[0][s[i] - 'a']++;
        f(0, t.length()) c[1][t[i] - 'a']++;
        f(0, p.length()) c[2][p[i] - 'a']++;
        vll v[27];
        f(0, t.length()) v[t[i] - 'a'].pb(i);
        bool ok = true;
        ll k = -1;
        f(0, s.length())
        {
            ll x = s[i] - 'a';
            if (v[x].size() == 0)
            {
                ok = false;
                break;
            }
            ll in = upper_bound(v[x].begin(), v[x].end(), k) - v[x].begin();
            // cout << in << " " << v[x].size() << "\n";
            if (in == v[x].size())
            {
                ok = false;
                break;
            }
            k = v[x][in];
        }
        if (!ok)
        {
            cout << "NO\n";
            continue;
        }
        f(0, 26)
        {
            if (c[0][i] + c[2][i] < c[1][i])
            {
                ok = false;
                break;
            }
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