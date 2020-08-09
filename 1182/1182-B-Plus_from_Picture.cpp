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

ll h, w;

bool safe(ll x, ll y)
{
    return x > 0 && x <= h && y > 0 && y <= w;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w;
    char a[h + 5][w + 5];
    f(1, h + 1)
            fi(1, w + 1)
                cin >>
        a[i][j];
    ll c = 0;
    bool b[h + 5][w + 5];
    memset(b, false, sizeof(b));
    f(1, h + 1)
    {
        if (c > 1)
        {
            cout << "NO";
            return 0;
        }
        fi(1, w + 1)
        {
            if (c > 1)
            {
                cout << "NO";
                return 0;
            }
            if (a[i][j] == '*')
            {
                if (b[i][j])
                    continue;
                if (c > 0)
                {
                    cout << "NO";
                    return 0;
                }
                if (safe(i - 1, j) && safe(i + 1, j) && safe(i, j - 1) && safe(i, j + 1))
                {
                    if (a[i - 1][j] == '*' && a[i + 1][j] == '*' && a[i][j - 1] == '*' && a[i][j + 1] == '*')
                    {
                        c++;
                        b[i][j] = true;
                        ll k = i - 1;
                        while (safe(k, j) && a[k][j] == '*')
                        {
                            b[k][j] = true;
                            k--;
                        }
                        k = i + 1;
                        while (safe(k, j) && a[k][j] == '*')
                        {
                            b[k][j] = true;
                            k++;
                        }
                        k = j - 1;
                        while (safe(i, k) && a[i][k] == '*')
                        {
                            b[i][k] = true;
                            k--;
                        }
                        k = j + 1;
                        while (safe(i, k) && a[i][k] == '*')
                        {
                            b[i][k] = true;
                            k++;
                        }
                    }
                }
                if (c > 1)
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
        if (c > 1)
        {
            cout << "NO";
            return 0;
        }
    }
    if (c > 1 || c == 0)
    {
        cout << "NO";
        return 0;
    }
    if (c == 1)
    {
        f(1, h + 1)
        {
            fi(1, w + 1)
            {
                if (a[i][j] == '*' && !b[i][j])
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    cout << "YES";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}