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
template <class L, class R> ostream &operator<<(ostream &os, map<L, R> M) {
  os << "{ ";
  for (auto m : M)
    os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
template <class L, class R> ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}

const ll N = 10000001;
ll b[N];

void sieve() {
  f(2, N) b[i] = i;
  f(4, N) b[i] = 2, i++;
  f(3, N) {
    if (i * i > N)
      break;
    if (b[i] == i) {
      fi(i * i, N) {
        if (b[j] == j)
          b[j] = i;
        j += i - 1;
      }
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve();
  ll n, x;
  cin >> n;
  pll ans(n);
  f(0, n) {
    cin >> x;
    if (b[x] == x) {
      ans[i].first = -1;
      ans[i].second = -1;
      continue;
    }
    ll k = b[x];
    while (x % k == 0)
      x /= k;
    if (x == 1) {
      ans[i].first = -1;
      ans[i].second = -1;
      continue;
    }
    ans[i].first = k;
    ans[i].second = x;
  }
  f(0, n) cout << ans[i].first << ' ';
  cout << '\n';
  f(0, n) cout << ans[i].second << ' ';

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}