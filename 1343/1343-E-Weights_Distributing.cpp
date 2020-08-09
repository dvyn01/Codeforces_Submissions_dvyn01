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
template <class L, class R> ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R> ostream &operator<<(ostream &os, map<L, R> M) {
  os << "{ ";
  for (auto m : M)
    os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}

const ll N = 200005;
ll n, m, a, b, c, p[N], da[N], db[N], dc[N], pr[N];
vll adj[N];
bool vis[N];

void update(ll s, ll in, ll d) {
  if (s == a)
    da[in] = d;
  else if (s == b)
    db[in] = d;
  else
    dc[in] = d;
}

ll get(ll s, ll in) {
  if (s == a)
    return da[in];
  else if (s == b)
    return db[in];
  return dc[in];
}

void bfs(ll s) {
  queue<ll> q;
  f(1, n + 1) vis[i] = false;
  vis[s] = true;
  update(s, s, 0);
  q.push(s);
  while (!q.empty()) {
    ll x = q.front();
    q.pop();
    ll d = get(s, x);
    f(0, adj[x].size()) {
      if (!vis[adj[x][i]]) {
        vis[adj[x][i]] = true;
        update(s, adj[x][i], d + 1);
        q.push(adj[x][i]);
      }
    }
  }
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
    cin >> n >> m >> a >> b >> c;
    f(1, m + 1) cin >> p[i];
    sort(p + 1, p + m + 1);
    f(1, m + 1) pr[i] = pr[i - 1] + p[i];
    f(1, n + 1) adj[i].clear();
    f(0, m) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
    if (a == b && b == c) {
      cout << 0 << '\n';
      continue;
    }
    bfs(a);
    bfs(b);
    bfs(c);
    if (a == b || b == c) {
      cout << pr[da[c]] << '\n';
      continue;
    }
    if (a == c) {
      cout << 2 * pr[da[b]] << '\n';
      continue;
    }
    ll ans = 1e18;
    f(1, n + 1) {
      ll c = 0;
      ll k1 = da[i] + dc[i], k2 = db[i];
      if (k1 + k2 > m)
        continue;
      c += pr[k2] * 2;
      c += pr[k1 + k2] - pr[k2];
      ans = min(ans, c);
    }
    cout << ans << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}