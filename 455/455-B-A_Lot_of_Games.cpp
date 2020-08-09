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
    bool win = false, lose = false;
    trie *c[26];
};

trie *root;

void insert(string s)
{
    trie *temp = root;
    f(0, s.length())
    {
        if (temp->c[s[i] - 'a'] == NULL)
            temp->c[s[i] - 'a'] = new trie();
        temp = temp->c[s[i] - 'a'];
    }
}

void dfs(trie *temp)
{
    bool child = false;
    f(0, 26) if (temp->c[i] != NULL)
        child = true,
        dfs(temp->c[i]), temp->win |= !(temp->c[i]->win), temp->lose |= !(temp->c[i]->lose);
    if (!child)
        temp->lose = true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool w = false, l = false;
    root = new trie();
    ll n, k;
    cin >> n >> k;
    f(0, n)
    {
        string s;
        cin >> s;
        insert(s);
    }
    dfs(root);
    if (root->win && root->lose)
        cout << "First";
    else if (root->win)
        cout << ((k & 1) ? "First" : "Second");
    else
        cout << "Second";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}