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

const ll N = 300005;
ll n, l, x[N / 3], d[N / 3], t[N / 3], p[N / 3], dist[N], e, pr[N];
pll adj[N];
map<ll, ll> m, rev;
map<pair<ll, ll>, ll> m1, ramp;

void dij() {
  f(1, e + 1) dist[i] = 1e18;
  dist[1] = 0;
  set<pair<ll, ll>> s;
  s.insert({0, 1});
  while (!s.empty()) {
    ll x = s.begin()->second, d = s.begin()->first;
    s.erase(s.begin());
    f(0, adj[x].size()) if (dist[adj[x][i].first] >= d + adj[x][i].second)
        dist[adj[x][i].first] = d + adj[x][i].second,
        pr[adj[x][i].first] = x,
        s.insert({dist[adj[x][i].first], adj[x][i].first});
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> l;
  f(0, n) {
    cin >> x[i] >> d[i] >> t[i] >> p[i];
    m[x[i]] = 1, m[x[i] + d[i]] = 1, m[x[i] - p[i]] = 1;
    if (m1.find({x[i] - p[i], x[i] + d[i]}) == m1.end() ||
        m1[{x[i] - p[i], x[i] + d[i]}] > p[i] + t[i]) {
      m1[{x[i] - p[i], x[i] + d[i]}] = p[i] + t[i];
      ramp[{x[i] - p[i], x[i] + d[i]}] = i + 1;
    }
  }
  m[0] = 1;
  m[l] = 1;
  while (m.begin()->first < 0)
    m.erase(m.begin());
  ll c = 1;
  for (auto it : m)
    m[it.first] = c, rev[c] = it.first, c++;
  f(0, n) {
    if (x[i] - p[i] >= 0)
      adj[m[x[i] - p[i]]].pb({m[x[i] + d[i]], p[i] + t[i]});
  }
  auto it1 = m.rbegin();
  e = it1->second;
  for (auto it = m.rbegin(); it != m.rend(); it++) {
    if (it == m.rbegin())
      continue;
    adj[it1->second].pb({it->second, it1->first - it->first});
    adj[it->second].pb({it1->second, it1->first - it->first});
    it1 = it;
  }
  dij();
  cout << dist[e] << '\n';
  vll ans;
  c = e;
  while (pr[c] != 0) {
    ll c1 = pr[c];
    if (m1.find({rev[c1], rev[c]}) != m1.end()) {
      if (rev[c] - rev[c1] > m1[{rev[c1], rev[c]}])
        ans.pb(ramp[{rev[c1], rev[c]}]);
    }
    c = c1;
  }
  cout << ans.size() << '\n';
  reverse(ans.begin(), ans.end());
  f(0, ans.size()) cout << ans[i] << ' ';

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}