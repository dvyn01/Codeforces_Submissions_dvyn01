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
string s;
ll dp[19][4][2];

ll rec(ll in, ll done, ll t) {
  if (done == 3)
    return 1;
  if (in == s.length())
    return 1;
  if (dp[in][done][t] != -1)
    return dp[in][done][t];
  ll r = 9;
  if (t == 1)
    r = s[in] - '0';
  dp[in][done][t] = 0;
  f(0, r + 1) {
    ll t1 = t;
    if (t == 1 && i < r)
      t1 = 0;
    if (i != 0)
      dp[in][done][t] += rec(in + 1, done + 1, t1);
    else
      dp[in][done][t] += rec(in + 1, done, t1);
  }
  return dp[in][done][t];
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
    ll l, r;
    cin >> l >> r;
    l--;
    memset(dp, -1, sizeof(dp));
    s.clear();
    while (r)
      s.pb('0' + (r % 10)), r /= 10;
    reverse(s.begin(), s.end());
    ll ans = rec(0, 0, 1);
    s.clear();
    memset(dp, -1, sizeof(dp));
    while (l)
      s.pb('0' + (l % 10)), l /= 10;
    reverse(s.begin(), s.end());
    ans -= rec(0, 0, 1);
    cout << ans << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}