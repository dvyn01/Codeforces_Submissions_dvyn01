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

inline ll mul(ll x, ll y, ll m) {
  ll z = 1LL * x * y;
  if (z >= m)
    z %= m;
  return z;
}
inline ll add(ll x, ll y, ll m) {
  ll z = x + y;
  if (z >= m)
    z %= m;
  return z;
}
inline ll sub(ll x, ll y, ll m) {
  ll z = x - y;
  if (z < 0)
    z += m;
  z %= m;
  return z;
}

const ll N = 200005;
ll dp[N], endd[N], ans[N];
vll adj[N];

ll dfs(ll x) {
  if (dp[x] != -1)
    return dp[x];
  ll k = 1;
  dp[x] = 0;
  f(0, adj[x].size()) {
    if (adj[x][i] == x) {
      endd[x] = -1;
      return 0;
    }
    k = mul(k, dfs(adj[x][i]), mod);
    endd[x] = endd[adj[x][i]];
  }
  if (adj[x].size() == 0)
    endd[x] = x;
  if (k == 0 && endd[x] == 0)
    endd[x] = x;
  return dp[x] = k;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  f(0, n) {
    ll x, y;
    cin >> x >> y;
    adj[x].pb(y);
  }
  memset(dp, -1, sizeof(dp));
  f(1, 2 * n + 1) if (dp[i] == -1) dfs(i);
  f(1, 2 * n + 1) if (dp[i] > 0) ans[endd[i]] += dp[i];
  ll finalAns = 1;
  f(1, 2 * n + 1) if (dp[i] == 0) ans[endd[i]] = 2;
  f(1, 2 * n + 1) if (ans[i] > 0) finalAns = mul(finalAns, ans[i], mod);
  cout << finalAns;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}