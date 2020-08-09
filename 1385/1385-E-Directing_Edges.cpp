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
vll adj[N];
ll n, m, c[N], pos[N], p = 0;

bool cycle(ll x) {
  c[x] = 1;
  f(0, adj[x].size()) {
    if (c[adj[x][i]] == 1)
      return true;
    if (c[adj[x][i]] == 2)
      continue;
    if (cycle(adj[x][i]))
      return true;
  }
  c[x] = 2;
  return false;
}

void dfs(ll x) {
  c[x] = 1;
  f(0, adj[x].size()) if (c[adj[x][i]] == 0) dfs(adj[x][i]);
  pos[x] = p++;
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
    cin >> n >> m;
    f(0, n + 1) c[i] = 0, pos[i] = -1, adj[i].clear();
    pll aux;
    f(0, m) {
      ll c, x, y;
      cin >> c >> x >> y;
      if (c == 0)
        aux.pb({x, y});
      else
        adj[x].pb(y);
    }
    bool done = false;
    f(1, n + 1) {
      if (c[i] == 0) {
        if (cycle(i)) {
          cout << "NO\n";
          done = true;
          break;
        }
      }
    }
    if (done)
      continue;
    p = 0;
    f(0, n + 1) c[i] = 0;
    f(1, n + 1) {
      if (c[i] == 0)
        dfs(i);
    }
    cout << "YES\n";
    f(1, n + 1) fi(0, adj[i].size()) cout << i << ' ' << adj[i][j] << '\n';
    f(0, aux.size()) {
      if (pos[aux[i].first] < pos[aux[i].second])
        cout << aux[i].second << ' ' << aux[i].first << '\n';
      else
        cout << aux[i].first << ' ' << aux[i].second << '\n';
    }
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}