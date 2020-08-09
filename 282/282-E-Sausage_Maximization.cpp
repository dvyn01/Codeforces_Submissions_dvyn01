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

struct trie
{
    trie *left = NULL, *right = NULL;
};

trie *root;

string convert(ll n)
{
    if(n == 0)
    {
        string s;
        f(0, 40)
            s += '0';
        return s;
    }
    string r;
    while (n)
    {
        r += '0' + (n & 1);
        n >>= 1;
    }
    string s;
    f(0, 40 - r.length())
        s += '0';
    fr(r.length() - 1, 0)
        s += r[j];
    return s;
}

void insert(string s)
{
    trie *temp = root;
    ll i = 0;
    while (i < 40)
    {
        if (s[i] == '0')
        {
            if (temp->left == NULL)
                temp->left = new trie();
            temp = temp->left;
        }
        else
        {
            if (temp->right == NULL)
                temp->right = new trie();
            temp = temp->right;
        }
        i++;
    }
}

string find(string s)
{
    trie *temp = root;
    ll i = 0;
    string z;
    while (i < 40)
    {
        char req;
        if (s[i] == '0')
        {
            if (temp->right != NULL)
                z += '1', temp = temp->right;
            else
                z += '0', temp = temp->left;
        }
        else
        {
            if (temp->left != NULL)
                z += '1', temp = temp->left;
            else
                z += '0', temp = temp->right;
        }
        i++;
    }
    return z;
}

ll back(string s)
{
    ll n = 0;
    fr(s.length() - 1, 0) if (s[j] == '1')
        n += (1LL << (40 - j - 1));
    return n;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    root = new trie();
    ll n, ans = 0, current = 0;
    cin >> n;
    ll a[n], b[n];
    f(0, n) cin >> a[i];
    b[0] = a[0];
    f(1, n)
        b[i] = b[i - 1] ^ a[i];
    current = a[n - 1];
    ans = b[n - 1];
    insert(convert(a[n - 1]));
    ans = max(ans, current);
    fr(n - 2, 0)
    {
        string s = convert(b[j]);
        string z = find(s);
        ans = max(ans, back(z));
        ans = max(ans, b[j]);
        current ^= a[j];
        ans = max(ans, current);
        z = convert(current);
        insert(z);
    }
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}