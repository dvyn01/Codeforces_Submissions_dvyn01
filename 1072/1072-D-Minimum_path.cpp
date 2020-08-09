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

const ll N = 2005;
string s[N];
ll n, k, dp[N][N];
pll p;

string find() {
  char mn = 'z';
  f(0, p.size()) {
    if (p[i].first != n - 1 && dp[p[i].first + 1][p[i].second] == -1)
      mn = min(mn, s[p[i].first + 1][p[i].second]);
    if (p[i].second != n - 1 && dp[p[i].first][p[i].second + 1] == -1)
      mn = min(mn, s[p[i].first][p[i].second + 1]);
  }
  f(0, p.size()) dp[p[i].first][p[i].second] = 0;
  pll p1;
  f(0, p.size()) {
    if (p[i].first != n - 1 && dp[p[i].first + 1][p[i].second] == -1 &&
        s[p[i].first + 1][p[i].second] == mn)
      p1.pb({p[i].first + 1, p[i].second}), dp[p[i].first + 1][p[i].second] = 0;
    if (p[i].second != n - 1 && dp[p[i].first][p[i].second + 1] == -1 &&
        s[p[i].first][p[i].second + 1] == mn)
      p1.pb({p[i].first, p[i].second + 1}), dp[p[i].first][p[i].second + 1] = 0;
  }
  p.clear();
  p = p1;
  if (p.size() == 1 && p[0].first == n - 1 && p[0].second == n - 1) {
    string s;
    s.pb(mn);
    return s;
  }
  return mn + find();
}

string compute() {
  string ans;
  if (k >= 2 * n - 1) {
    f(0, 2 * n - 1) ans.pb('a');
    return ans;
  }
  if (k == 0) {
    if (n == 1)
      return s[0];
    memset(dp, -1, sizeof(dp));
    p.pb({0, 0});
    return s[0][0] + find();
  }
  if (s[0][0] == 'a')
    dp[0][0] = 1;
  f(0, n) {
    fi(0, n) {
      if (i == 0 && j == 0)
        continue;
      if (i == 0)
        dp[i][j] = dp[i][j - 1];
      else if (j == 0)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      if (s[i][j] == 'a')
        dp[i][j]++;
    }
  }
  ll mx = 0;
  f(0, n) {
    fi(0, n) {
      ll moves = i + j;
      if (moves + 1 - dp[i][j] > k)
        dp[i][j] = -1;
      else
        dp[i][j] = k - (moves + 1 - dp[i][j]);
      if (dp[i][j] == 0)
        mx = max(mx, moves);
    }
  }
  if (dp[n - 1][n - 1] != -1) {
    f(0, 2 * n - 1) ans.pb('a');
    return ans;
  }
  f(0, mx + 1) ans.pb('a');
  f(0, n) {
    fi(0, n) {
      if (dp[i][j] == -1)
        continue;
      ll moves = i + j;
      if (moves == mx) {
        p.pb({i, j});
      }
    }
  }
  memset(dp, -1, sizeof(dp));
  ans += find();
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  f(0, n) cin >> s[i];
  cout << compute();

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}