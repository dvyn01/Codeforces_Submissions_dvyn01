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
//      typedef tree<ll
//      ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//      ordered_set;

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

const ll N = 200005;
ll a[N], b[N], c[N], dp[N], s01[N], s10[N], mn[N];
vll adj[N];

void dfs(ll x, ll pr, ll c1) {
  c1 = min(c1, a[x]);
  mn[x] = c1;
  if (b[x] == 0 && c[x] == 1)
    s01[x]++;
  if (b[x] == 1 && c[x] == 0)
    s10[x]++;
  f(0, adj[x].size()) {
    if (adj[x][i] != pr) {
      dfs(adj[x][i], x, c1);
      s01[x] += s01[adj[x][i]];
      s10[x] += s10[adj[x][i]];
    }
  }
}

void calc(ll x, ll pr) {
  ll cs01 = s01[x], cs10 = s10[x];
  f(0, adj[x].size()) {
    if (adj[x][i] != pr) {
      calc(adj[x][i], x);
      ll v = adj[x][i];
      ll k = 2 * min(s01[v], s10[v]);
      if (dp[v] > mn[x] * k)
        dp[v] = mn[x] * k;
      dp[x] += dp[v];
      cs01 -= min(s01[v], s10[v]), cs10 -= min(s01[v], s10[v]);
    }
  }
  dp[x] += mn[x] * 2 * min(cs01, cs10);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, x, y, zc = 0, zb = 0;
  cin >> n;
  f(1, n + 1) {
    cin >> a[i] >> b[i] >> c[i];
    if (b[i] == 0)
      zb++;
    if (c[i] == 0)
      zc++;
  }
  f(0, n - 1) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
  if (zb != zc) {
    cout << -1;
    return 0;
  }
  dfs(1, -1, 1e18);
  calc(1, -1);
  cout << dp[1];

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}