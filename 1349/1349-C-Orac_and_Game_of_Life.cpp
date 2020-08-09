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
ll n, m, t;
string s[N];
ll good[N][N];

bool safe(ll i, ll j) { return i >= 0 && i < n && j >= 0 && j < m; }

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> t;
  f(0, n) cin >> s[i];
  memset(good, -1, sizeof(good));
  queue<pair<ll, ll>> q;
  f(0, n) {
    fi(0, m) {
      if ((safe(i + 1, j) && s[i + 1][j] == s[i][j]) ||
          (safe(i - 1, j) && s[i - 1][j] == s[i][j]) ||
          (safe(i, j + 1) && s[i][j + 1] == s[i][j]) ||
          (safe(i, j - 1) && s[i][j - 1] == s[i][j]))
        good[i][j] = 1, q.push({i, j});
    }
  }
  while (!q.empty()) {
    ll i = q.front().first, j = q.front().second;
    q.pop();
    if (safe(i + 1, j) && good[i + 1][j] == -1)
      good[i + 1][j] = good[i][j] + 1, q.push({i + 1, j});
    if (safe(i - 1, j) && good[i - 1][j] == -1)
      good[i - 1][j] = good[i][j] + 1, q.push({i - 1, j});
    if (safe(i, j + 1) && good[i][j + 1] == -1)
      good[i][j + 1] = good[i][j] + 1, q.push({i, j + 1});
    if (safe(i, j - 1) && good[i][j - 1] == -1)
      good[i][j - 1] = good[i][j] + 1, q.push({i, j - 1});
  }
  while (t--) {
    ll i, j, p;
    cin >> i >> j >> p;
    i--, j--;
    if (good[i][j] == -1 || (p < good[i][j]))
      cout << s[i][j] << '\n';
    else
      cout << ((1 & (good[i][j] ^ p)) ? (s[i][j] - '0') : ((s[i][j] - '0') ^ 1))
           << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}