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

const ll N = 100005;

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
    ll n;
    cin >> n;
    string s[n];
    f(0, n) cin >> s[i];
    bool vis[n][n];
    memset(vis, false, sizeof(vis));
    queue<pair<ll, ll>> q;
    f(0, n) {
      if (s[i][n - 1] == '1')
        q.push({i, n - 1}), vis[i][n - 1] = true;
      if (s[n - 1][i] == '1' && i != n - 1)
        q.push({n - 1, i}), vis[n - 1][i] = true;
    }
    while (!q.empty()) {
      ll x = q.front().first, y = q.front().second;
      q.pop();
      if (x != 0 && !vis[x - 1][y] && s[x - 1][y] == '1')
        vis[x - 1][y] = true, q.push({x - 1, y});
      if (y != 0 && !vis[x][y - 1] && s[x][y - 1] == '1')
        vis[x][y - 1] = true, q.push({x, y - 1});
    }
    bool ok = true;
    f(0, n) {
      fi(0, n) {
        if (s[i][j] == '1' && !vis[i][j]) {
          ok = false;
          break;
        }
      }
    }
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}