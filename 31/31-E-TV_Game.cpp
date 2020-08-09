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

const ll N = 37;
ll dp[N][N], child[N][N], n;
string s, ans;

ll rec(ll in, ll k) {
  if (in == (n << 1)) {
    if (k == n)
      return 0;
    return -1e18;
  }
  if (dp[in][k] != -1)
    return dp[in][k];
  ll x = -1;
  ll k1 = in - k;
  if (k < n && (s[in] - '0') * pow(10, n - k - 1) + rec(in + 1, k + 1) > x) {
    x = (s[in] - '0') * pow(10, n - k - 1) + rec(in + 1, k + 1);
    child[in][k] = 1;
  }
  if (k1 < n && (s[in] - '0') * pow(10, n - k1 - 1) + rec(in + 1, k1 + 1) > x) {
    x = (s[in] - '0') * pow(10, n - k1 - 1) + rec(in + 1, k);
    child[in][k] = 2;
  }
  return dp[in][k] = x;
}

void get(ll in, ll k) {
  if (in == (n << 1))
    return;
  if (child[in][k] == 1)
    ans.pb('H'), get(in + 1, k + 1);
  else
    ans.pb('M'), get(in + 1, k);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> s;
  memset(dp, -1, sizeof(dp));
  rec(0, 0);
  get(0, 0);
  cout << ans;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}