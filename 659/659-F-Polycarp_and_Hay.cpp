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

const ll N = 1005;
ll a[N][N], n, m, k, r[N * N], s[N * N];
map<ll, pll> cor;
bool vis[N][N];

bool safe(ll x, ll y) { return x > 0 && x <= n && y > 0 && y <= m; }

ll encode(ll x, ll y) { return (x - 1) * m + y; }

pair<ll, ll> decode(ll x) {
  if (x % m == 0)
    return {x / m, m};
  return {x / m + 1, x % m};
}

void init() { f(1, n * m + 1) r[i] = i, s[i] = 1; }

ll root(ll i) {
  while (i != r[i])
    i = r[r[i]];
  return i;
}

void merge(ll x, ll y) {
  ll xr = root(x), yr = root(y);
  if (xr == yr)
    return;
  if (s[xr] >= s[yr])
    s[xr] += s[yr], r[yr] = xr;
  else
    s[yr] += s[xr], r[xr] = yr;
}

void fill(ll x, ll y, ll rem, ll val) {
  ll r = root(encode(x, y));
  memset(a, 0, sizeof(a));
  queue<pair<ll, ll>> q;
  q.push({x, y});
  memset(vis, false, sizeof(vis));
  vis[x][y] = true;
  while (rem > 0) {
    ll cx = q.front().first, cy = q.front().second;
    q.pop();
    a[cx][cy] = val;
    rem--;
    if (rem == 0)
      break;
    if (safe(cx - 1, cy) && root(encode(cx - 1, cy)) == r && !vis[cx - 1][cy])
      q.push({cx - 1, cy}), vis[cx - 1][cy] = true;
    if (safe(cx + 1, cy) && root(encode(cx + 1, cy)) == r && !vis[cx + 1][cy])
      q.push({cx + 1, cy}), vis[cx + 1][cy] = true;
    if (safe(cx, cy - 1) && root(encode(cx, cy - 1)) == r && !vis[cx][cy - 1])
      q.push({cx, cy - 1}), vis[cx][cy - 1] = true;
    if (safe(cx, cy + 1) && root(encode(cx, cy + 1)) == r && !vis[cx][cy + 1])
      q.push({cx, cy + 1}), vis[cx][cy + 1] = true;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;
  f(1, n + 1) fi(1, m + 1) {
    cin >> a[i][j];
    if (cor[a[i][j]].size() == 0) {
      pll p;
      p.pb({i, j});
      cor[a[i][j]] = p;
    } else {
      cor[a[i][j]].pb({i, j});
    }
  }
  init();
  bool ok = false;
  for (auto it = cor.rbegin(); it != cor.rend(); it++) {
    pll p = it->second;
    f(0, p.size()) {
      ll x = p[i].first, y = p[i].second;
      vis[x][y] = true;
      if (safe(x - 1, y) && vis[x - 1][y])
        merge(encode(x, y), encode(x - 1, y));
      if (safe(x + 1, y) && vis[x + 1][y])
        merge(encode(x, y), encode(x + 1, y));
      if (safe(x, y - 1) && vis[x][y - 1])
        merge(encode(x, y), encode(x, y - 1));
      if (safe(x, y + 1) && vis[x][y + 1])
        merge(encode(x, y), encode(x, y + 1));
    }
    if (k % it->first != 0)
      continue;
    f(0, p.size()) {
      if (s[root(encode(p[i].first, p[i].second))] >= k / it->first) {
        fill(p[i].first, p[i].second, k / it->first, it->first);
        ok = true;
        break;
      }
    }
    if (ok)
      break;
  }
  if (!ok) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    f(1, n + 1) {
      fi(1, m + 1) cout << a[i][j] << ' ';
      cout << '\n';
    }
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}