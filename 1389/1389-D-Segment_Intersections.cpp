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
ll l1, l2, r1, r2, n, k;

bool pos(ll mid) {
  ll req = k, moves = 0;
  f(0, n) {
    ll cur = 0, done = 0;
    if (l2 > r1) {
      // if (mid < l2 - r1)
      // return false;
      moves += l2 - r1, cur += l2 - r1;
    } else {
      if (r2 >= r1) {
        ll mx = r1 - l2;
        done += mx;
        // req -= mx;
      } else {
        ll mx = r2 - l2;
        done += mx;
        // req -= mx;
      }
    }
    if (req <= 0)
      break;
    ll sp = max(r1, r2) - min(l1, l2);
    if (sp - done >= req) {
      ll m1 = 1e18;
      if (i > 0) {
        m1 = 0;
        m1 += moves - cur + (2 * req);
      }
      moves -= cur;
      // cout << moves << ' ' << req << ' ' << m1 << '\n';
      moves = min(moves + cur + req, m1);
      req = 0;
      break;
    }
    req -= sp - done;
    ll lmin = l1, rmax = max(r1, r2);
    moves -= cur;
    moves += l1 - lmin + rmax - r1 + l2 - lmin + rmax - r2;
    if (moves + 2 * req <= mid)
      return true;
  }
  ll rem = mid - moves;
  if (rem > 0)
    req -= rem / 2;
  // cout << mid << ' ' << req << ' ' << rem << '\n';
  if (req > 0)
    return false;
  return rem >= 0;
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
    cin >> n >> k;
    cin >> l1 >> r1 >> l2 >> r2;
    if (l1 > l2)
      swap(l1, l2), swap(r1, r2);
    if (r1 >= r2) {
      ll p = (r2 - l2) * n;
      if (p >= k) {
        cout << 0 << '\n';
        continue;
      }
      k -= p;
    } else if (r1 >= l2) {
      ll p = (r1 - l2) * n;
      if (p >= k) {
        cout << 0 << '\n';
        continue;
      }
      k -= p;
    }
    // cout << k << '\n';
    ll l = 0, h = 5e9, ans = -1;
    while (l <= h) {
      ll mid = l + h >> 1;
      if (pos(mid))
        ans = mid, h = mid - 1;
      else
        l = mid + 1;
    }
    cout << ans << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}