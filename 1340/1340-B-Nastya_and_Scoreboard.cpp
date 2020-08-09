#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
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
string s[N], t[10];
ll a[N], dp[N][N], n, k, pos[N][10];

ll rec(ll in, ll rem) {
  if (in >= n)
    return rem == 0;
  if (dp[in][rem] != -1)
    return dp[in][rem];
  if (rem < 0)
    return 0;
  fr(9, 0) {
    ll c = pos[in][j];
    if (c == -1 || c > rem)
      continue;
    if (rec(in + 1, rem - c)) {
      a[in] = j;
      return dp[in][rem] = 1;
    }
  }
  return dp[in][rem] = 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  t[0] = "1110111", t[1] = "0010010", t[2] = "1011101", t[3] = "1011011",
  t[4] = "0111010", t[5] = "1101011", t[6] = "1101111", t[7] = "1010010",
  t[8] = "1111111", t[9] = "1111011";
  cin >> n >> k;
  f(0, n) cin >> s[i];
  fii(0, n) {
    fr(9, 0) {
      ll c = 0;
      f(0, 7) {
        if (s[k][i] == '1' && t[j][i] == '0') {
          c = -1;
          break;
        }
        if (s[k][i] == '0' && t[j][i] == '1')
          c++;
      }
      pos[k][j] = c;
    }
  }
  memset(dp, -1, sizeof(dp));
  if (rec(0, k) == 0) {
    cout << -1;
    return 0;
  }
  f(0, n) cout << a[i];

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}