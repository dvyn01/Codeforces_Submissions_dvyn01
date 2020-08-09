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
#define fii(a, b) for (ll kk = a; kk < b; kk++)
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
template <class L, class R> ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R> ostream &operator<<(ostream &os, map<L, R> M) {
  os << "{ ";
  for (auto m : M)
    os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}

const ll N = 201;

vll adj[N];
ll n, k, a[N], dp[N][N], mxS[N];

ll pre(ll x, ll pr) {
  ll c = 1, mx = 0;
  f(0, adj[x].size()) if (adj[x][i] != pr) mx = max(mx, pre(adj[x][i], x));
  return mxS[x] = c + mx;
}

ll dfs(ll x, ll pr, ll d) {
  if (dp[x][d] != -1)
    return dp[x][d];
  ll mx = 0;
  if (d == 0) {
    ll mx1 = a[x];
    f(0, adj[x].size()) {
      if (adj[x][i] != pr)
        mx1 += dfs(adj[x][i], x, k);
    }
    mx = max(mx, mx1);
  }
  f(0, adj[x].size()) {
    if (adj[x][i] != pr) {
      dfs(adj[x][i], x, max(0LL, d - 1));
    }
  }
  f(0, adj[x].size()) {
    if (adj[x][i] != pr) {
      fi(max(d - 1, 0LL), mxS[adj[x][i]]) {
        ll mx1 = 0;
        if (dp[adj[x][i]][j] == -1)
          dfs(adj[x][i], x, j);
        mx1 = dp[adj[x][i]][j];
        ll rem = k - j - 1, c = 0;
        if (rem < d - 1)
          rem = d - 1;
        fii(0, adj[x].size()) {
          if (kk == i || adj[x][kk] == pr)
            continue;
          if (mxS[adj[x][kk]] - 1 >= rem)
            c++;
        }
        if (c > 1 && rem < k / 2)
          continue;
        fii(0, adj[x].size()) {
          if (adj[x][kk] != pr && kk != i) {
            if (dp[adj[x][kk]][rem] == -1)
              dfs(adj[x][kk], x, rem);
            mx1 += dp[adj[x][kk]][rem];
          }
        }
        mx = max(mx, mx1);
      }
    }
  }
  return dp[x][d] = mx;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll x, y;
  cin >> n >> k;
  f(1, n + 1) cin >> a[i];
  f(0, n - 1) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
  memset(dp, -1, sizeof(dp));
  pre(1, -1);
  ll ans = dfs(1, -1, 0);
  cout << ans;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}