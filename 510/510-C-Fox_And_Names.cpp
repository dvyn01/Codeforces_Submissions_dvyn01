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

vll adj[26];

stack<ll> st;
bool cycle;
bool vis[26];

void dfs(ll x, bool b[])
{
    if (vis[x])
        return;
    b[x] = true;
    vis[x] = true;
    f(0, adj[x].size())
    {
        if (b[adj[x][i]])
        {
            cycle = true;
            return;
        }
        if (!vis[adj[x][i]])
            dfs(adj[x][i], b);
    }
    b[x] = false;
    st.push(x);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    bool app[26];
    memset(app, false, sizeof(app));
    cin >> n;
    string s[n];
    f(0, n) cin >> s[i];
    f(0, n)
        fi(0, s[i].size())
            app[s[i][j] - 'a'] = true;
    f(0, n)
    {
        fi(i + 1, n)
        {
            bool ok = false;
            fii(0, min(s[i].length(), s[j].length()))
            {
                if (s[i][k] != s[j][k])
                {
                    ok = true;
                    adj[s[i][k] - 'a'].pb(s[j][k] - 'a');
                    break;
                }
            }
            if(!ok)
            {
                if(s[i].length() > s[j].length())
                {
                    cout<<"Impossible";
                    return 0;
                }
            }
        }
    }
    bool b[26];
    f(0, 26) if (!vis[i] && app[i]) memset(b, false, sizeof(b)), dfs(i, b);
    if (cycle)
        cout << "Impossible";
    else
    {
        string topo;
        memset(b, false, sizeof(b));
        while (!st.empty())
        {
            topo += st.top() + 'a';
            b[st.top()] = true;
            st.pop();
        }
        f(0, 26) if (!b[i])
            topo += 'a' + i;
        cout << topo;
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}