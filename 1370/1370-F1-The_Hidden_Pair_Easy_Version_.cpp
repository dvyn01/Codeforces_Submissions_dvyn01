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

const ll N = 1005;
ll n, a, b, d, mx;
vll adj[N];
bool m[N];
vll level[N];

pair<ll, ll> ask(vll v) {
  cout << "? ";
  cout << v.size() << ' ';
  f(0, v.size()) cout << v[i] << ' ';
  cout << endl;
  ll x, d;
  cin >> x >> d;
  if (x == -1 && d == -1)
    exit(0);
  return {x, d};
}

ll mark(ll x, ll pr) {
  if (x == b) {
    m[x] = true;
    return 0;
  }
  ll k = 1e18;
  f(0, adj[x].size()) {
    if (adj[x][i] != pr) {
      k = min(k, mark(adj[x][i], x) + 1);
      m[x] |= m[adj[x][i]];
    }
  }
  return k;
}

void dfs(ll x, ll pr, ll c) {
  level[c].pb(x);
  mx = max(mx, c);
  f(0, adj[x].size()) {
    if (adj[x][i] != pr && !m[adj[x][i]])
      dfs(adj[x][i], x, c + 1);
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    ll x, y;
    cin >> n;
    level[0].clear();
    f(1, n + 1) m[i] = false, adj[i].clear(), level[i].clear();
    f(0, n - 1) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
    vll v;
    f(1, n + 1) v.pb(i);
    pair<ll, ll> p = ask(v);
    a = p.first, d = p.second; // total dist
    v.clear();
    f(1, n + 1) if (i != a) v.pb(i);
    p = ask(v);
    b = p.first;
    ll d1 = mark(a, -1); // dist b/w a and b
    mx = 0;
    dfs(a, -1, 0);
    ll l = 0, h = mx;
    x = 0, y = 0;
    if (mx == 0)
      x = a;
    else {
      while (l <= h) {
        ll mid = l + h >> 1;
        v.clear();
        f(0, level[mid].size()) v.pb(level[mid][i]);
        if (v.size() == 1 && v[0] == a) {
          x = a, l = mid + 1;
          continue;
        }
        p = ask(v);
        if (p.second == d)
          x = p.first, l = mid + 1;
        else
          h = mid - 1;
      }
    }
    ll dist = mark(x, -1); // dist b/w x and b
    if (dist == d) {
      y = b;
    } else {
      level[0].clear();
      f(1, n + 1) level[i].clear();
      dfs(b, -1, 0);
      dist = d - dist;
      v.clear();
      f(0, level[dist].size()) v.pb(level[dist][i]);
      if (v.size() == 1)
        y = v[0];
      else {
        p = ask(v);
        y = p.first;
      }
    }
    cout << "! " << x << ' ' << y << endl;
    string s;
    cin >> s;
    if (s == "Incorrect")
      return 0;
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
