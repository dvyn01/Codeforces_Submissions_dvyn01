#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
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

const ll N = 5001;
ll n, m, n1, n2, n3, c[N], dp[N][N], child[N][N], pr[N], ans[N];
vll adj[N];
pll p;
vector<pair<vector<ll>, vector<ll>>> comp;

bool dfs(ll x) {
  if (c[x] == 0)
    p.back().first++, comp.back().first.pb(x);
  else
    p.back().second++, comp.back().second.pb(x);
  bool k = true;
  f(0, adj[x].size()) {
    if (c[x] == c[adj[x][i]])
      return false;
    if (c[adj[x][i]] == -1) {
      c[adj[x][i]] = c[x] ^ 1;
      k &= dfs(adj[x][i]);
    }
  }
  return k;
}

ll rec(ll in, ll remTwo) {
  if (in == p.size())
    return remTwo == 0;
  if (dp[in][remTwo] != -1)
    return dp[in][remTwo];
  ll k = 0;
  ll remOne = n1 + n3;
  if (in != 0)
    remOne = n1 + n3 - (pr[in - 1] - (n2 - remTwo));
  if (remOne >= p[in].first && remTwo >= p[in].second) {
    if (rec(in + 1, remTwo - p[in].second) == 1)
      k = 1, child[in][remTwo] = 2;
  }
  if (remTwo >= p[in].first && remOne >= p[in].second) {
    if (rec(in + 1, remTwo - p[in].first) == 1)
      k = 1, child[in][remTwo] = 1;
  }
  return dp[in][remTwo] = k;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll x, y;
  cin >> n >> m >> n1 >> n2 >> n3;
  f(0, m) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
  memset(c, -1, sizeof(c));
  f(1, n + 1) {
    if (c[i] == -1) {
      c[i] = 0;
      p.pb({0, 0});
      vll v1, v2;
      comp.pb({v1, v2});
      if (!dfs(i)) {
        cout << "NO";
        return 0;
      }
    }
  }
  memset(dp, -1, sizeof(dp));
  pr[0] = p[0].first + p[0].second;
  f(1, p.size()) pr[i] = pr[i - 1], pr[i] += p[i].first + p[i].second;
  if (rec(0, n2)) {
    cout << "YES\n";
    ll remTwo = n2;
    f(0, p.size()) {
      if (child[i][remTwo] == 1) {
        remTwo -= p[i].first;
        fi(0, comp[i].first.size()) ans[comp[i].first[j]] = 2;
        fi(0, comp[i].second.size()) ans[comp[i].second[j]] = ((n1 > 0) ? 1 : 3),
                                     n1--;
      } else {
        remTwo -= p[i].second;
        fi(0, comp[i].first.size()) ans[comp[i].first[j]] = ((n1 > 0) ? 1 : 3),
                                    n1--;
        fi(0, comp[i].second.size()) ans[comp[i].second[j]] = 2;
      }
    }
    f(1, n + 1) cout << ans[i];
  } else
    cout << "NO";

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}