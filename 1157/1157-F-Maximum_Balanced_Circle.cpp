/*
    * AUTHOR : Divyanshu *
*/

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
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll a[200050];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x;
    cin >> n;
    f(0, n) cin >> x, a[x]++;
    ll lp = 1, rp = 1, mx = 0, c = 0, mxl = 0, mxr = 0;
    f(1, 200001)
    {
        if (a[i] && a[i + 1])
        {
            if (a[i] + a[i + 1] > mx)
            {
                mx = a[i] + a[i + 1];
                mxl = i;
                mxr = i + 1;
            }
        }
        else if (a[i] > mx)
            mx = a[i], mxl = i, mxr = i;
    }
    while (lp <= 200000)
    {
        if (a[lp] == 0 || a[lp + 1] < 2 || a[lp + 2] < 1)
        {
            lp++;
            rp = lp;
            c = 0;
            continue;
        }
        rp = lp + 2;
        c += a[lp] + a[lp + 1];
        while (a[rp - 1] > 1)
        {
            c += a[rp];
            rp++;
        }
        if (c > mx)
        {
            mx = c;
            mxl = lp;
            mxr = rp - 1;
        }
        lp = rp - 1;
        c = 0;
    }
    cout << mx << "\n";
    if (mxr - mxl < 2)
    {
        f(0, a[mxl])
                cout
            << mxl << " ";
        if (mxl != mxr)
            f(0, a[mxr])
                    cout
                << mxr << " ";
    }
    else
    {
        vll v1, v2;
        f(mxl, mxr + 1)
        {
            if (a[i] == 0)
                break;
            v1.pb(i);
            if (a[i] > 1)
                v2.pb(i);
        }
        f(0, v1.size())
        {
            cout << v1[i] << " ";
            if (a[v1[i]] == 1)
                continue;
            fi(0, a[v1[i]] - 2)
                    cout
                << v1[i] << " ";
        }
        fr(v2.size() - 1, 0)
                cout
            << v2[j] << " ";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}