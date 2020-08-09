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

bool checkChar(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '_'));
}

bool check(string s)
{
    ll c = 0;
    while (c < s.length() && s[c] != '@')
        c++;
    if (c == s.length() || c > 16)
        return false;
    if (c == 0 || c > 16)
        return false;
    f(0, c)
    {
        if (!checkChar(s[i]))
            return false;
    }
    ll sl = 0;
    f(c, s.length())
    {
        if (s[i] == '/')
        {
            sl = i;
            break;
        }
    }
    if (sl == 0)
        sl = s.length();
    if (sl == c + 1 || sl - c - 1 > 32)
        return false;
    f(c + 1, sl - 1) if (s[i] == '.' && s[i + 1] == '.') return false;
    if (s[sl - 1] == '.')
        return false;
    vll dots;
    dots.pb(c);
    f(c + 1, sl)
    {
        if (s[i] != '.' && !checkChar(s[i]))
            return false;
        else if (s[i] == '.')
            dots.pb(i);
    }
    f(0, dots.size() - 1) if (dots[i + 1] - dots[i] - 1 > 16 || dots[i + 1] - dots[i] == 1) return false;
    if (sl != s.length() && s.length() - sl - 1 > 16)
        return false;
    if (s[s.length() - 1] == '/' || s[s.length() - 1] == '.')
        return false;
    f(sl + 1, s.length()) if (!checkChar(s[i])) return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    if (check(s))
        cout << "YES";
    else
        cout << "NO";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}