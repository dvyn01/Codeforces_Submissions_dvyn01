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
template <class T> ostream &operator<<(ostream &os, multiset<T> S) {
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
pll adj[N];
ll n, s, sum = 0;
multiset<pair<ll, pair<ll, ll>>> diff;

ll calc(ll wt, ll leaves) {
  ll rem = wt - (wt / 2);
  rem *= leaves;
  return rem;
}

ll dfs(ll x, ll pr) {
  if (adj[x].size() == 1 && x != 1)
    return 1;
  ll k = 0;
  f(0, adj[x].size()) {
    if (adj[x][i].first != pr) {
      ll y = dfs(adj[x][i].first, x);
      diff.insert({calc(adj[x][i].second, y), {adj[x][i].second, y}});
      k += y;
      sum += adj[x][i].second * y;
    }
  }
  return k;
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
    sum = 0;
    ll x, y, w;
    cin >> n >> s;
    f(1, n + 1) adj[i].clear();
    f(0, n - 1) cin >> x >> y >> w, adj[x].pb({y, w}), adj[y].pb({x, w});
    diff.clear();
    dfs(1, -1);
    ll ans = 0;
    while (sum > s && !diff.empty()) {
      pair<ll, pair<ll, ll>> p1 = *(--diff.end());
      diff.erase(--diff.end());
      sum -= p1.first;
      ll newWt = p1.second.first / 2;
      if (newWt != 0)
        diff.insert({calc(newWt, p1.second.second), {newWt, p1.second.second}});
      ans++;
    }
    cout << ans << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}