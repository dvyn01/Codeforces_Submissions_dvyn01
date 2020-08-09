#include <bits/stdc++.h>
/** #include <ext/pb_ds/assoc_container.hpp>
 * #include <ext/pb_ds/tree_policy.hpp>
 * using namespace __gnu_pbds; */
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

const ll N = 4005;
ll n, a[N], dp[N][N];
vll v;

ll rec(ll in, ll rem) {
  if (rem == 0)
    return 1;
  if (in == v.size())
    return 0;
  if (dp[in][rem] != -1)
    return dp[in][rem];
  ll k = rec(in + 1, rem);
  if (v[in] <= rem)
    k = max(k, rec(in + 1, rem - v[in]));
  return dp[in][rem] = k;
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
    cin >> n;
    f(0, 2 * n + 1) fi(0, n + 1) dp[i][j] = -1;
    f(1, 2 * n + 1) cin >> a[i];
    v.clear();
    ll mx = a[1], pos = 1;
    f(2, 2 * n + 1) {
      if (a[i] > mx) {
        v.pb(i - pos);
        pos = i;
        mx = a[i];
      }
    }
    v.pb(2 * n + 1 - pos);
    if (rec(0, n))
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