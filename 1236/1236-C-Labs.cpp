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

vll v[305];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll c = 1, d = 1;
    f(1, n * n + 1)
    {
        if (c == 1)
        {
            if (d == 1)
            {
                v[c].pb(i);
                c++;
            }
            else
            {
                v[c].pb(i);
                d = 1;
            }
        }
        else if (c == n)
        {
            if (d == 0)
            {
                v[c].pb(i);
                c--;
            }
            else
            {
                v[c].pb(i);
                d = 0;
            }
        }
        else if (d == 1)
        {
            v[c].pb(i);
            c++;
        }
        else if (d == 0)
        {
            v[c].pb(i);
            c--;
        }
    }
    f(1, n + 1)
    {
        // cout << v[i].size() << "\n";
        fi(0, n) cout << v[i][j] << " ";
        cout << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}