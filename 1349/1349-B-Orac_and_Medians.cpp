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
ll a[N], pr[N];

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
    ll n, k;
    bool present = false;
    cin >> n >> k;
    f(1, n + 1) cin >> a[i], present |= (a[i] == k);
    if (n == 1) {
      if (a[1] == k)
        cout << "yes\n";
      else
        cout << "no\n";
      continue;
    }
    if (!present) {
      cout << "no\n";
      continue;
    }
    bool ok = false;
    f(1, n + 1) {
      if (a[i] >= k) {
        if (i != 1 && a[i - 1] >= k) {
          ok = true;
          break;
        }
        if (i != n && a[i + 1] >= k) {
          ok = true;
          break;
        }
      }
    }
    if (ok) {
      cout << "yes\n";
      continue;
    }
    f(1, n + 1) {
      if (a[i] >= k) {
        if (i > 2 && a[i - 2] >= k) {
          ok = true;
          break;
        }
        if (i < n - 1 && a[i + 2] >= k) {
          ok = true;
          break;
        }
      }
    }
    if (present) {
    }
    if (ok)
      cout << "yes\n";
    else
      cout << "no\n";
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}