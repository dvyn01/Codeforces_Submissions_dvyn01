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
vector<pair<ll, pair<ll, ll>>> adj[N];
ll n, s, sum = 0;
multiset<pair<ll, pair<ll, ll>>> diff1, diff2;

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
      if (adj[x][i].second.second == 1)
        diff1.insert(
            {calc(adj[x][i].second.first, y), {adj[x][i].second.first, y}});
      else
        diff2.insert(
            {calc(adj[x][i].second.first, y), {adj[x][i].second.first, y}});
      k += y;
      sum += adj[x][i].second.first * y;
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
    ll x, y, w, c;
    cin >> n >> s;
    f(1, n + 1) adj[i].clear();
    f(0, n - 1) cin >> x >> y >> w >> c, adj[x].pb({y, {w, c}}),
        adj[y].pb({x, {w, c}});
    diff1.clear();
    diff2.clear();
    dfs(1, -1);
    ll ans = 0;
    while (sum > s) {
      pair<ll, pair<ll, ll>> p1 = {-1e18, {-1e18, -1e18}};
      pair<ll, pair<ll, ll>> p2 = {-1e18, {-1e18, -1e18}};
      if (!diff1.empty())
        p1 = *(--diff1.end());
      if (!diff2.empty())
        p2 = *(--diff2.end());
      if (p2.first == -1e18) {
        ans++;
        diff1.erase(--diff1.end());
        sum -= p1.first;
        ll newWt = p1.second.first / 2;
        if (newWt != 0)
          diff1.insert(
              {calc(newWt, p1.second.second), {newWt, p1.second.second}});
      } else if (p1.first == -1e18) {
        ans += 2;
        diff2.erase(--diff2.end());
        sum -= p2.first;
        ll newWt = p2.second.first / 2;
        if (newWt != 0)
          diff2.insert(
              {calc(newWt, p2.second.second), {newWt, p2.second.second}});
      } else if (sum - p1.first <= s) {
        ans++;
        break;
      } else if (diff1.size() == 1 &&
                 p2.first >
                     p1.first + calc(p1.second.first / 2, p1.second.second)) {
        ans += 2;
        diff2.erase(--diff2.end());
        sum -= p2.first;
        ll newWt = p2.second.first / 2;
        if (newWt != 0)
          diff2.insert(
              {calc(newWt, p2.second.second), {newWt, p2.second.second}});
      } else {
        ll tot = p1.first;
        if (diff1.size() > 1) {
          auto it = --(diff1.end());
          --it;
          tot += max(it->first, calc(p1.second.first / 2, p1.second.second));
        } else
          tot += calc(p1.second.first / 2, p1.second.second);
        if (tot >= p2.first) {
          diff1.erase(--diff1.end());
          sum -= p1.first;
          ans++;
          ll newWt = p1.second.first / 2;
          if (newWt != 0)
            diff1.insert(
                {calc(newWt, p1.second.second), {newWt, p1.second.second}});
        } else {
          ans += 2;
          sum -= p2.first;
          ll newWt = p2.second.first / 2;
          diff2.erase(--diff2.end());
          if (newWt != 0)
            diff2.insert(
                {calc(newWt, p2.second.second), {newWt, p2.second.second}});
        }
      }
    }
    cout << ans << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}