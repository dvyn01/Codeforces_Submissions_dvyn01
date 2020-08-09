#include <bits/stdc++.h>
/** #include <ext/pb_ds/assoc_container.hpp>
 * #include <ext/pb_ds/tree_policy.hpp>
 * using namespace __gnu_pbds; */
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
/** typedef tree<ll
 * ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
 * ordered_set; */

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
template <class L, class R>
ostream &operator<<(ostream &os, unordered_map<L, R> M) {
  os << "{ ";
  for (auto m : M)
    os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
template <class L, class R> ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}

const ll N = 6004;
ll dp[N][N], n, l[N >> 1], r[N >> 1];
map<ll, ll> m;
map<pair<ll, ll>, bool> indexes;
vll start[N], en[N];

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
    cin >> n;
    f(0, 2 * n + 3) fi(i, 2 * n + 3) dp[i][j] = 0;
    f(0, 2 * n + 3) start[i].clear(), en[i].clear();
    m.clear();
    indexes.clear();
    f(1, n + 1) cin >> l[i] >> r[i], m[l[i]], m[r[i]];
    l[0] = 0, r[0] = 200001;
    ll c = 1;
    m[0];
    m[200001];
    for (auto it : m)
      m[it.first] = c++;
    f(0, n + 1) {
      l[i] = m[l[i]];
      r[i] = m[r[i]];
      indexes[{l[i], r[i]}] = true;
      start[l[i]].pb(r[i]);
      en[r[i]].pb(l[i]);
    }
    f(0, 2 * n + 3) {
      if (!start[i].empty())
        sort(start[i].begin(), start[i].end());
      if (!en[i].empty())
        sort(en[i].begin(), en[i].end()), reverse(en[i].begin(), en[i].end());
    }
    ll lim = m[200001] - m[0];
    f(0, lim + 1) {
      fi(1, m[200001] - i + 1) {
        ll l = j, r = j + i;
        dp[l][r] = max(dp[l + 1][r] + dp[l][l], dp[l][r - 1] + dp[r][r]);
        for (auto it : start[l]) {
          if (it > r)
            break;
          dp[l][r] = max(dp[l][r], dp[l][it] + dp[it + 1][r]);
        }
        for (auto it : en[r]) {
          if (it < l)
            break;
          dp[l][r] = max(dp[l][r], dp[l][it - 1] + dp[it][r]);
        }
        if (indexes.find({l, r}) != indexes.end())
          dp[l][r]++;
      }
    }
    cout << dp[1][m[200001]] - 1 << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}