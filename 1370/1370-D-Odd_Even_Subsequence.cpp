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

const ll N = 200005;
ll a[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k;
  cin >> n >> k;
  f(1, n + 1) cin >> a[i];
  ll l = 1, h = 1e9, ans = -1;
  while (l <= h) {
    ll mid = l + h >> 1;
    ll last = -1, c1 = 0, c2 = 0;
    if (k & 1) {
      f(1, n + 1) if (a[i] <= mid && last != i - 1) last = i, c1++;
      last = -1;
      f(2, n) if (a[i] <= mid && last != i - 1) last = i, c2++;
      if (c1 >= ((k >> 1) + 1) || c2 >= (k >> 1))
        ans = mid, h = mid - 1;
      else
        l = mid + 1;
    } else {
      f(1, n) if (a[i] <= mid && last != i - 1) last = i, c1++;
      last = -1;
      f(2, n + 1) if (a[i] <= mid && last != i - 1) last = i, c2++;
      if (c1 >= (k >> 1) || c2 >= (k >> 1))
        ans = mid, h = mid - 1;
      else
        l = mid + 1;
    }
  }
  cout << ans;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}