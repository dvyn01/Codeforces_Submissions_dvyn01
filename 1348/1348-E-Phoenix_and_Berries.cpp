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
#define fii(a, b) for (ll l = a; l < b; l++)
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

const ll N = 505;
ll n, k, a[N], b[N], ap[N], bp[N];
bool dp[N][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  f(1, n + 1) cin >> a[i] >> b[i];
  f(1, n + 1) ap[i] = a[i] + ap[i - 1], bp[i] = b[i] + bp[i - 1];
  dp[0][0] = true;
  f(1, n + 1) {
    fi(0, k) {
      if (dp[i - 1][j]) {
        fii(0, k) {
          if (l < j) {
            if (a[i] < k - j + l)
              continue;
            ll ar = a[i] - (k - j + l);
            ar %= k;
            if (b[i] < ((k - ar) % k))
              continue;
            dp[i][l] = true;
          } else {
            if (a[i] < l - j)
              continue;
            ll ar = a[i] - (l - j);
            ar %= k;
            if (b[i] < (k - ar) % k)
              continue;
            dp[i][l] = true;
          }
        }
      }
    }
  }
  ll ans = 0;
  f(0, k) if (dp[n][i]) ans = max(ans, (ap[n] + bp[n] - i) / k);
  cout << ans;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}