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
ll ans,
    dp[65][2][2][2]; // l se equal, greater ; r se less, equal ;  b == a, b > a
string l, r;

ll rec(ll in, ll t1, ll t2, ll b) {
  if (in == r.length())
    return 0;
  if (dp[in][t1][t2][b] != -1)
    return dp[in][t1][t2][b];
  ll k = 0;
  // 0-1
  if (!((t1 == 0 && l[in] == '1') || (t2 == 1 && r[in] == '0'))) {
    k = max(k, (1LL << (r.length() - in - 1)) + rec(in + 1, t1, t2, 1));
  }
  // 1-0
  if (b) {
    ll t11 = t1, t22 = t2;
    if (t1 == 0 && l[in] == '0')
      t11 = 1;
    if (t2 == 1 && r[in] == '1')
      t22 = 0;
    k = max(k, (1LL << (r.length() - in - 1)) + rec(in + 1, t11, t22, b));
  }
  // 0-0
  if (!(t1 == 0 && l[in] == '1')) {
    ll t11 = t1, t22 = t2;
    if (t2 == 1 && r[in] == '1')
      t22 = 0;
    k = max(k, rec(in + 1, t11, t22, b));
  }
  // 1-1
  if (!(t2 == 1 && r[in] == '0')) {
    ll t11 = t1, t22 = t2;
    if (t1 == 0 && l[in] == '0')
      t11 = 1;
    k = max(k, rec(in + 1, t11, t22, b));
  }
  return dp[in][t1][t2][b] = k;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof(dp));
  ll l1, r1;
  cin >> l1 >> r1;
  while (l1)
    l.pb('0' + (l1 & 1)), l1 >>= 1;
  while (r1)
    r.pb('0' + (r1 & 1)), r1 >>= 1;
  while (l.size() < r.size())
    l.pb('0');
  reverse(l.begin(), l.end());
  reverse(r.begin(), r.end());
  cout << rec(0, 0, 1, 0);

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}