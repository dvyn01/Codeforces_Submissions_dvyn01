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
#define fr(a, b) for (ll i = a; i >= b; i--)
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
template <class L, class R> ostream &operator<<(ostream &os, map<L, R> M) {
  os << "{ ";
  for (auto m : M)
    os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
template <class L, class R> ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}

const ll N = 2005;
string s[N];
ll n, m, dp[N][N], downRight[N][N], downLeft[N][N];

void fillDownRight(ll i, ll j) {
  if (i < 0 || i >= n || j < 0 || j >= m)
    return;
  if (i > 0 && j > 0) {
    if (s[i - 1][j - 1] == s[i][j])
      downRight[i - 1][j - 1] += downRight[i][j];
    fillDownRight(i - 1, j - 1);
  }
}

void fillDownLeft(ll i, ll j) {
  if (i < 0 || i >= n || j < 0 || j >= m)
    return;
  if (i > 0 && j < m - 1) {
    if (s[i - 1][j + 1] == s[i][j])
      downLeft[i - 1][j + 1] += downLeft[i][j];
    fillDownLeft(i - 1, j + 1);
  }
}

void calc(ll i, ll j) {
  ll left = j - dp[i][j], right = j + dp[i][j];
  if (left >= 0 && downRight[i][left] >= dp[i][j] + 1 && right < m &&
      downLeft[i][right] >= dp[i][j] + 1 && s[i][left] == s[i][j] &&
      s[i][right] == s[i][j])
    dp[i][j]++;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  f(0, n) cin >> s[i];
  f(0, n) fi(0, m) downRight[i][j]++, downLeft[i][j]++;
  f(0, m) fillDownLeft(n - 1, i), fillDownRight(n - 1, i);
  f(0, n - 1) fillDownLeft(i, 0), fillDownRight(i, m - 1);
  long long ans = 0;
  f(0, n) {
    fi(0, m) {
      if (i == 0 || j == 0 || i == n - 1 || j == m - 1 ||
          s[i - 1][j] != s[i][j] || s[i + 1][j] != s[i][j] ||
          s[i][j - 1] != s[i][j] || s[i][j + 1] != s[i][j]) {
        dp[i][j] = 1;
        continue;
      }
      ll mx = 0;
      dp[i][j] = dp[i - 1][j] - 1;
      calc(i, j);
      calc(i, j);
    }
  }
  f(0, n) fi(0, m) ans += dp[i][j];
  cout << ans << '\n';

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}