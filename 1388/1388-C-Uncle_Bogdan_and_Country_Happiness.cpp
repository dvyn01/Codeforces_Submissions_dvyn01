#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
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
/**      typedef tree<ll
 * ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
 * ordered_set; */

template <class T> ostream &operator<<(ostream &os, vector<T> V) {
  os << "[ ";
  for (auto v : V)
    os << v << " ";
  os << "]";
  return os;
}
template <class T> ostream &operator<<(ostream &os, set<T> S) {
  os << "{ ";
  for (auto s : S)
    os << s << " ";
  return os << "}";
}
template <class L, class R> ostream &operator<<(ostream &os, map<L, R> M) {
  os << "{ ";
  for (auto m : M)
    os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
template <class L, class R> ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}

const ll N = 100005;
ll n, p[N], h[N], sub[N], m;
vll adj[N];

void dfs(ll x, ll pr) {
  sub[x] += p[x];
  f(0, adj[x].size()) if (adj[x][i] != pr) dfs(adj[x][i], x),
      sub[x] += sub[adj[x][i]];
}

bool check(ll x, ll pr) {
  if ((abs(h[x]) > sub[x]) || (abs(h[x]) & 1 ^ sub[x] & 1))
    return false;
  bool k = true, leaf = true;
  ll h1 = 0;
  f(0, adj[x].size()) if (adj[x][i] != pr) leaf = false,
                                           k &= check(adj[x][i], x),
                                           h1 += h[adj[x][i]];
  return (k & (h[x] >= h1 - p[x]));
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    ll x, y;
    cin >> n >> m;
    f(1, n + 1) adj[i].clear(), sub[i] = 0;
    f(1, n + 1) cin >> p[i];
    f(1, n + 1) cin >> h[i];
    f(0, n - 1) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
    dfs(1, -1);
    if (check(1, -1))
      cout << "YES\n";
    else
      cout << "NO\n";
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}