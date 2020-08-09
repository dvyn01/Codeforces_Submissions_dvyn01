#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll int
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define mod 1000000007
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

template <class T>
ostream &operator<<(ostream &os, vector<T> V)
{
    os << "[ ";
    for (auto v : V)
        os << v << " ";
    os << "]";
    return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> S)
{
    os << "{ ";
    for (auto s : S)
        os << s << " ";
    return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P)
{
    return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M)
{
    os << "{ ";
    for (auto m : M)
        os << "(" << m.first << ":" << m.second << ") ";
    return os << "}";
}

ll n, blockSize, q;
ordered_set s[500];
vll v;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    blockSize = sqrt(n);
    v.resize(n);
    f(0, n)
    {
        v[i] = i + 1;
        ll block = i / blockSize;
        s[block].insert(i + 1);
    }
    long long ans = 0;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        if (l > r)
            swap(l, r);
        l--, r--;
        ll lBlock = l / blockSize, rBlock = r / blockSize, le = v[l], re = v[r];
        swap(v[l], v[r]);
        if (le < re)
            ans++;
        else if (le > re)
            ans--;
        if (lBlock == rBlock)
        {
            f(l + 1, r)
            {
                if (v[i] > re)
                    ans--;
                else if (v[i] < re)
                    ans++;
                if (v[i] < le)
                    ans--;
                else if (v[i] > le)
                    ans++;
            }
            cout << ans << "\n";
            continue;
        }
        s[lBlock].erase(s[lBlock].upper_bound(le));
        s[lBlock].insert(re);
        s[rBlock].erase(s[rBlock].upper_bound(re));
        s[rBlock].insert(le);
        f(l + 1, n)
        {
            if (i / blockSize != lBlock)
            {
                i--;
                fr(i, l + 1)
                {
                    if (v[j] > re)
                        ans--;
                    else if (v[j] < re)
                        ans++;
                }
                break;
            }
            if (v[i] < le)
                ans--;
            else if (v[i] > le)
                ans++;
        }
        fr(r - 1, 0)
        {
            if (j / blockSize != rBlock)
            {
                j++;
                f(j, r)
                {
                    if (v[i] < le)
                        ans--;
                    else if (v[i] > le)
                        ans++;
                }
                break;
            }
            if (v[j] > re)
                ans--;
            else if (v[j] < re)
                ans++;
        }
        lBlock++;
        while (lBlock != rBlock)
        {
            ll k1 = s[lBlock].order_of_key(le), k2 = s[lBlock].order_of_key(re);
            ans -= k1, ans += k2;
            k1 = blockSize - s[lBlock].order_of_key(le + 1), k2 = blockSize - s[lBlock].order_of_key(re + 1);
            ans += k1, ans -= k2;
            lBlock++;
        }
        cout << ans << "\n";
    } 

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}