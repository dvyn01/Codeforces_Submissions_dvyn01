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

const ll N = 400005;
ll a[N], pr[N], pr1[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, x;
  cin >> n >> x;
  f(1, n + 1) cin >> a[i], a[i + n] = a[i];
  n <<= 1;
  f(1, n + 1) pr[i] = pr[i - 1] + (a[i] * (a[i] + 1) / 2),
              pr1[i] = pr1[i - 1] + a[i];
  ll ans = 0;
  ll end = 1;
  f(1, n + 1) {
    while (end <= n && pr1[end] - pr1[i - 1] < x)
      end++;
    if (end > n)
      break;
    if (i == end) {
      ll st = a[i] - x;
      ll k = a[i] * (a[i] + 1) / 2;
      k -= st * (st + 1) / 2;
      ans = max(ans, k);
      continue;
    }
    ll k = 0, k2 = 0;
    if (end - i > 1)
      k += pr[end - 1] - pr[i], k2 = pr1[end - 1] - pr1[i];
    ll rem = x - k2;
    rem -= a[i];
    rem = a[end] - rem;
    // cout << i << ' ' << end << ' ' << rem << '\n';
    if (rem == 0)
      ans = max(ans, pr[end] - pr[i - 1]);
    else {
      if (a[i] < rem)
        continue;
      ll inc = rem;
      k += (a[i] * (a[i] + 1) / 2);
      k -= inc * (inc + 1) / 2;
      k += (a[end] * (a[end] + 1) / 2);
      ans = max(ans, k);
      // cout << i << ' ' << end << ' ' << inc << ' ' << k << '\n';
    }
  }
  cout << ans;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}